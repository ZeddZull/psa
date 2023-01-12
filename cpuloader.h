#ifndef CPULOADER_H
#define CPULOADER_H

#include <windows.h>

class CPULoader
{
public:
    CPULoader();
    float getCPULoad();
private:
    float calculateCPULoad(unsigned long long, unsigned long long);
    unsigned long long fileTimeToInt64(const FILETIME&);
};

#endif // CPULOADER_H
