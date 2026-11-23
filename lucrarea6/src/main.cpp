#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <mutex>
#include <thread>
#include <chrono>
#include <stdexcept>


class MutexLock {
private:
    std::mutex* mtxPtr;

public:
    explicit MutexLock(std::mutex* mtx) : mtxPtr(mtx) {
        if (mtxPtr) {
            mtxPtr->lock();
            std::cout << "[MUTEX] Resource locked.\n";
        }
    }

    ~MutexLock() {
        if (mtxPtr) {
            mtxPtr->unlock();
            std::cout << "[MUTEX] Resource unlocked automatically.\n";
        }
    }

    // interzicem copierea pentru a evita double unlock
    MutexLock(const MutexLock&) = delete;
    MutexLock& operator=(const MutexLock&) = delete;
};


class LogFile {
private:
    std::unique_ptr<std::ofstream> fileStream;
    std::mutex logMutex;

public:
    explicit LogFile(const std::string& filename)
        : fileStream(std::make_unique<std::ofstream>(filename, std::ios::app)) {

        if (!fileStream->is_open()) {
            throw std::runtime_error("Failed to open log file!");
        }

        std::cout << "[LOG FILE] File opened: " << filename << "\n";
    }

    ~LogFile() {
        std::cout << "[LOG FILE] Logger destroyed. File will be closed automatically.\n";
    }

    void write(const std::string& message) {
        MutexLock lock(&logMutex);

        if (!fileStream || !(*fileStream)) {
            throw std::runtime_error("Log file is not available!");
        }

        *fileStream << message << "\n";

        if (!(*fileStream)) {
            throw std::runtime_error("Failed to write to log file!");
        }

        std::cout << "[WRITE] " << message << "\n";
    }

    // interzicem copierea obiectului care gestioneaza resurse
    LogFile(const LogFile&) = delete;
    LogFile& operator=(const LogFile&) = delete;
};


class ModulRetea {
private:
    std::shared_ptr<LogFile> logger;

public:
    explicit ModulRetea(std::shared_ptr<LogFile> sharedLog)
        : logger(sharedLog) {
    }

    void executaTask() {
        if (logger) {
            logger->write("Network module: Data received.");
        }
    }
};


class ModulBazaDeDate {
private:
    std::shared_ptr<LogFile> logger;

public:
    explicit ModulBazaDeDate(std::shared_ptr<LogFile> sharedLog)
        : logger(sharedLog) {
    }

    void executaTask() {
        if (logger) {
            logger->write("Database module: Query executed.");
        }
    }
};


int main() {

    try {
        // cream un logger gestionat prin shared_ptr
        std::shared_ptr<LogFile> sharedLogger =
            std::make_shared<LogFile>("execution.log");

        std::cout << "Owners after creating logger: "
                  << sharedLogger.use_count() << "\n";

        {
            // cele doua module primesc acelasi logger
            ModulRetea networkModule(sharedLogger);
            ModulBazaDeDate databaseModule(sharedLogger);

            std::cout << "Owners after creating modules: "
                      << sharedLogger.use_count() << "\n";

            std::cout << "\n----- Concurrent File Writing -----\n";

            std::thread t1([&networkModule]() {
                for (int i = 0; i < 3; ++i) {
                    networkModule.executaTask();
                    std::this_thread::sleep_for(
                        std::chrono::milliseconds(50)
                    );
                }
            });

            std::thread t2([&databaseModule]() {
                for (int i = 0; i < 3; ++i) {
                    databaseModule.executaTask();
                    std::this_thread::sleep_for(
                        std::chrono::milliseconds(50)
                    );
                }
            });

            t1.join();
            t2.join();

            std::cout << "\nAll threads finished.\n";

        } // modulele sunt distruse

        std::cout << "\nOwners after destroying modules: "
                  << sharedLogger.use_count() << "\n";

        std::cout << "The logger is still alive because sharedLogger owns it.\n";

        // eliberam ultimul proprietar
        sharedLogger.reset();

        std::cout << "Owners after reset: "
                  << sharedLogger.use_count() << "\n";

        std::cout << "The logger has been destroyed.\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    std::cout << "\nProgram finished successfully.\n";

    return 0;
}