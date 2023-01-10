#include "testevent.h"

TestEvent::TestEvent(QObject *parent)
    : QObject{parent}
{

}

void TestEvent::testEvent(){
    QVERIFY(true);
}
