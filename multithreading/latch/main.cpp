#include <chrono>
#include <iostream>
#include <filesystem>
#include <latch>
#include <string>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

void initializeComponent(const std::string& name,
                         int startupTimeMs,
                         std::latch& startupLatch) {

    std::cout << name << " initialization started" << std::endl;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(startupTimeMs));

    std::cout << name << " initialization completed" << std::endl;

    // Signal that this worker is done
    startupLatch.count_down();
}

void init_AppConfig(std::stop_token stopToken,
                    const std::string& name,
                    int startupTimeMs,
                    std::latch& startupLatch) {

    try {
        std::cout << name << " started" << std::endl;
        std::filesystem::create_directories("config");
        std::filesystem::path configPath { "config/app.config" };

        while(!std::filesystem::exists(configPath)) {
            if(stopToken.stop_requested()) {
                std::cout << name << " stop requested" << std::endl;
                break;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(startupTimeMs));
            std::cout << "Waiting for app.config to exist.." << std::endl;
        }

        if(std::filesystem::exists(configPath)) {
            std::cout << "app.config found.." << std::endl;
        }

        std::cout << name << " completed" << std::endl;
    }
    catch(const std::filesystem::filesystem_error& ex) {
        std::cerr << "Filesystem error in " << name
                  << ": " << ex.what() << std::endl;
    }
    catch(const std::exception& ex) {
        std::cerr << "Exception in " << name
                  << ": " << ex.what() << std::endl;
    }
    catch(...) {
        std::cerr << "Unknown exception in "
                  << name << std::endl;
    }

    // Always signal latch, even on failure
    startupLatch.count_down();
}

int main() {

    constexpr int numberOfThreads { 3 };

    // Main thread waits for 4 workers
    std::latch startupLatch(numberOfThreads);

    std::vector<std::jthread> workers;

    workers.emplace_back(
        initializeComponent,
        "Database",
        2000,
        std::ref(startupLatch));

    workers.emplace_back(
        initializeComponent,
        "Redis Server",
        1500,
        std::ref(startupLatch));

    workers.emplace_back(
        init_AppConfig,
        "App Configuration",
        2500,
        std::ref(startupLatch));

    std::cout << std::endl << "Main thread waiting for services..." << std::endl;

    // Wait until count reaches zero
    startupLatch.wait();

    std::cout << std::endl << "All services initialized successfully" << std::endl;
    std::cout << "Application is now ready" << std::endl;

    return 0;
}