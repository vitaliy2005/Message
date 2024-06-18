QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

CONFIG += c++20

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qrunnablethread.cpp

HEADERS += \
    mainwindow.h \
    qrunnablethread.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
