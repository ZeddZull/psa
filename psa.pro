QT       += core gui location quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airport.cpp \
    authoriseduser.cpp \
    cpuloader.cpp \
    loadchart.cpp \
    main.cpp \
    mainwindow.cpp \
    mapwidget.cpp \
    ramloader.cpp \
    user.cpp

HEADERS += \
    airport.h \
    authoriseduser.h \
    cpuloader.h \
    loadchart.h \
    mainwindow.h \
    mapwidget.h \
    ramloader.h \
    user.h

FORMS += \
    loadchart.ui \
    mainwindow.ui \
    mapwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
