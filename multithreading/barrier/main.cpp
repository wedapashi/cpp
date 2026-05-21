#include <barrier>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <semaphore>
#include <stop_token>
#include <string>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

template<typename BarrierType>
void initializeDatabase(const std::string& name,
                        int startupTimeMs,
                        std::binary_semaphore& dbReady,
                        BarrierType& startupBarrier) {

    std::cout << name << " initialization started"
              << std::endl;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(startupTimeMs));

    std::cout << name << " initialization completed"
              << std::endl;

    // Signal Redis that DB is ready
    dbReady.release();

    startupBarrier.arrive_and_wait();
}

template<typename BarrierType>
void initializeRedis(const std::string& name,
                     int startupTimeMs,
                     std::binary_semaphore& dbReady,
                     BarrierType& startupBarrier) {

    std::cout << name
              << " waiting for Database..."
              << std::endl;

    dbReady.acquire();

    std::cout << name
              << " detected Database ready"
              << std::endl;

    std::cout << name
              << " initialization started"
              << std::endl;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(startupTimeMs));

    std::cout << name
              << " initialization completed"
              << std::endl;

    startupBarrier.arrive_and_wait();
}

template<typename BarrierType>
void init_AppConfig(std::stop_token stopToken,
                    const std::string& name,
                    int startupTimeMs,
                    BarrierType& startupBarrier) {

    std::cout << name << " started"
              << std::endl;

    std::filesystem::create_directories("config");

    std::filesystem::path configPath {
        "config/app.config"
    };

    while(!std::filesystem::exists(configPath)) {

        if(stopToken.stop_requested()) {
            break;
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(startupTimeMs));

        std::cout << "Waiting for app.config..."
                  << std::endl;
    }

    std::cout << name
              << " completed"
              << std::endl;

    startupBarrier.arrive_and_wait();
}

int main() {

    constexpr int numberOfWorkers { 3 };

    std::binary_semaphore dbReady(0);

    std::barrier startupBarrier(
        numberOfWorkers + 1,
        []() noexcept {
            std::cout << std::endl
                      << "=== All services initialized ==="
                      << std::endl;
        });

    std::vector<std::jthread> workers;

    workers.emplace_back(
        initializeDatabase<decltype(startupBarrier)>,
        "Database",
        3000,
        std::ref(dbReady),
        std::ref(startupBarrier));

    workers.emplace_back(
        initializeRedis<decltype(startupBarrier)>,
        "Redis Server",
        2000,
        std::ref(dbReady),
        std::ref(startupBarrier));

    workers.emplace_back(
        init_AppConfig<decltype(startupBarrier)>,
        "App Configuration",
        1000,
        std::ref(startupBarrier));

    std::cout << "Main thread waiting..."
              << std::endl;

    startupBarrier.arrive_and_wait();

    std::cout << "Application is now ready"
              << std::endl;

    return 0;
}