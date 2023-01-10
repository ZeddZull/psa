#include "testevent.h"

#include <QApplication>
#include <QMap>
#include <QDebug>

#include <memory>
#include <map>

int main(int argc, char *argv[])
{
    QApplication q(argc, argv);
    QStringList arguments = QCoreApplication::arguments();

    std::map<QString, std::unique_ptr<QObject>> tests;
    tests.emplace("testevent", std::make_unique<TestEvent>());

    int status = 0;
    for(auto& test : tests) {
        QObject* testToDo = test.second.get();
        status |= QTest::qExec(testToDo, arguments);
    }
    return status;
}
