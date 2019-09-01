//
// Created by johnm on 9/1/2019.
//

#ifndef TRAFFIC_PROGRAM_MEMORYTOOLS_H
#define TRAFFIC_PROGRAM_MEMORYTOOLS_H

#include "windows.h"
#include "psapi.h"
#include <iostream>
#define GIGABYTES_DIV (1024*1024*1024)
#define MEGABYTES_DIV (1024*1024)
#define KILABYTES_DIV (1024)


class MemoryTools {
public:
    /**
     * Returns total virtual memory being used
     */
    int VirtualMemoryProfile() {

        MEMORYSTATUSEX mem_info;
        mem_info.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&mem_info);
        DWORDLONG totalVirtualMemory = mem_info.ullTotalPageFile;
        DWORDLONG virtualMemoryInUse = totalVirtualMemory - mem_info.ullAvailPageFile;
        PROCESS_MEMORY_COUNTERS_EX pmc;
        GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
        SIZE_T current_process_memory = pmc.PrivateUsage;
        std::cout << "Total Memory Usage including available memory: " << totalVirtualMemory  << " bytes" << std::endl;
        std::cout << "Total active  memory: " << virtualMemoryInUse << " bytes" << std::endl;
        std::cout << "Total memory used by current process: " << current_process_memory  << " bytes" << std::endl;


    }
};


#endif //TRAFFIC_PROGRAM_MEMORYTOOLS_H
