QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mtcpsocket.cpp


HEADERS += \
    mainwindow.h \
    mtcpsocket.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
