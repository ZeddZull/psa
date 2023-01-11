#ifndef CPULOADER_H
#define CPULOADER_H

#include <windows.h>

class CPULoader
{
public:
    CPULoader();
    float GetCPULoad();
private:
    float CalculateCPULoad(unsigned long long, unsigned long long);
    unsigned long long FileTimeToInt64(const FILETIME&);
};

#endif // CPULOADER_H
