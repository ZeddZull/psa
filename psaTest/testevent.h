#ifndef TESTEVENT_H
#define TESTEVENT_H

#include <QObject>
#include <QTest>

class TestEvent : public QObject
{
    Q_OBJECT
public:
    explicit TestEvent(QObject *parent = nullptr);

private slots:
    void testEvent();

signals:

};

#endif // TESTEVENT_H
