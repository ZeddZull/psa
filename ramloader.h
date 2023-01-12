#ifndef RAMLOADER_H
#define RAMLOADER_H

#include "windows.h"

class RAMLoader
{
public:
    RAMLoader();
    int getRAMLoad();
private:
    MEMORYSTATUSEX memInfo;
};

#endif // RAMLOADER_H
