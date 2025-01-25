#include <iostream>
#include "log.h"
#include <thread>

void logCheck(int i )
{ 
    std::shared_ptr<Log> log = Log::getInstance();
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "Hello, from logFile from threadID %d\n", i);
    log->logStmt(buffer);

}

int main(int, char**){

    //if its a shared ptr no need of move but ownership transfer has to be done 
    //to prevent the error of copying.
    std::shared_ptr<Log> log = Log::getInstance();
    log->init("log.txt");
    
    std::thread th1(logCheck , 1);
    std::thread th2(logCheck , 2);

    th1.join();
    th2.join();
    log->endLogging("Closing log file");




    return 0;
}
