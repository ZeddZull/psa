#include "cpuloader.h"

CPULoader::CPULoader()
{
}
float CPULoader::calculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
    static unsigned long long _previousTotalTicks = 0;
    static unsigned long long _previousIdleTicks = 0;

    unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
    unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;


    float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

    _previousTotalTicks = totalTicks;
    _previousIdleTicks = idleTicks;
    return ret;
}
unsigned long long CPULoader::fileTimeToInt64(const FILETIME & ft)
{
    return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime);
}
float CPULoader::getCPULoad()
{
    FILETIME idleTime, kernelTime, userTime;
    return (GetSystemTimes(&idleTime, &kernelTime, &userTime) ? calculateCPULoad(fileTimeToInt64(idleTime), fileTimeToInt64(kernelTime) + fileTimeToInt64(userTime)) : -1.0f)*100;
}
