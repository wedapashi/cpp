#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std::chrono_literals;

//#define DUMP_TO_COUT

class Logger {
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance() {
        static Logger logger;
        return logger;
    }

    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_stream << "# " << message << std::endl;
        m_stream.flush();
    }

    const std::filesystem::path& file() const {
        return m_logFile;
    }

private:
    Logger() {
        std::filesystem::create_directories("logs");
        m_stream.open(m_logFile, std::ios::app);
        if (!m_stream) {
            throw std::runtime_error("Failed to open log file");
        }
    }

    inline static const std::filesystem::path m_logFile{"logs/app.log"};
    std::ofstream m_stream;
    std::mutex m_mutex;
};

void dump(const std::string& content) {
    #ifndef DUMP_TO_COUT
    Logger::getInstance().log(content);
    #else
    static int logCount = 1;
    std::cout << "# " << logCount++ << ": " << content << std::endl;
    #endif
}

void t1() {
    while(1) {
        std::this_thread::sleep_for(5000ms);
        dump("In Thread 1");
    }
}

void t2(std::stop_token stopToken) {
    while(!stopToken.stop_requested()) {
        std::this_thread::sleep_for(2000ms);
        dump("In Thread 2");
    }
    dump("Thread 2: Stop Request received.");
}

int main(void) {
    dump("App start!");
    std::jthread thread1 { t1 };
    std::jthread thread2 { t2 };
    int counter { 0 };

    while(1) {
        std::this_thread::sleep_for(1000ms);
        dump("In Main thread");
        if(counter++ == 5) {
            dump("Stopping thread 2");
            thread2.request_stop();
            break;
        }
    }
    dump("App Exit!");
    return EXIT_SUCCESS;
}
