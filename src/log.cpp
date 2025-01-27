#include "log.h"
std::shared_ptr<Log> Log::m_instance{nullptr};


void Log::init(std::string file)
{
    m_fileName = file;
    
    fp = fopen(m_fileName.c_str(), "w");
    if(fp == NULL)
    {
        std::cout << "Failed to open file: " << m_fileName <<" for logging." << "\n";
        exit(1);
    }

    std::cout << "Opened file: " << m_fileName << " for logging." << "\n";
}

void Log::logStmt(const char* stmt)
{
    
    std::lock_guard<std::mutex> lock(m_mutex);
    fprintf(fp,"%s",stmt); //treating the string as argument to avoid this 
    
}

void Log::endLogging(std::string closeStmt)
{

    flush();
    std::cout << closeStmt <<" : " << m_fileName << "\n";
    fclose(fp);
}

void Log::flush()
{
    
    if(fflush(fp))
    {
        std::cout << "Failed to flush file: " << m_fileName << "\n";
        exit(1);
    }
    std::cout << "Flushed file: " << m_fileName << "\n";
}

//the reference should be returned not the value
std::shared_ptr<Log> Log::getInstance()
{

    if(m_instance == nullptr)
    {
        m_instance.reset(new Log());
    }
    return m_instance;
}

