#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <mutex>
#include <memory>
#include <string>

class Log 
{
    public:
        Log& operator= (const Log&) = delete;
        void init(std::string file);
        void logStmt(const char* stmt);
        void endLogging(std::string closeStmt);
    
        static std::shared_ptr<Log> getInstance();

        std::string m_fileName;
        std::mutex m_mutex;
        FILE *fp = nullptr;

    private:
        Log(){
            std::cout << "Singleton Logging File object created" << std::endl;
        };
        void flush();

        static std::shared_ptr<Log> m_instance ;

};




#endif

