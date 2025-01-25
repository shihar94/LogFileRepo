# LogFileRepo
A C++ log file class to log statements for debugging purpose. 

A Singleton design pattern is used as there should be only one logging file for the process irrespective of the number of threads. 

Mutexes are utilized in order for each thread to utilize the logging resource without cauing any deadlock.

Smart Pointers are used in order to preven memory leaks.