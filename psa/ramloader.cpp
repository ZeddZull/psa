#include "ramloader.h"

RAMLoader::RAMLoader()
{
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
}
int RAMLoader::getPourcentageUse()
{
    GlobalMemoryStatusEx(&memInfo);
    return (memInfo.ullTotalPageFile-memInfo.ullAvailPageFile)*100/memInfo.ullTotalPageFile;
}
