TEMPLATE = app
TARGET = PlatformServer

QT = core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network widgets

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

HEADERS += \
    platformserver.h \
    iothread.h \
    platformservergui.h \
    logger.h \
    tag.h \
    quote.h \
    platformclient.h \
    movie.h \
    book.h

SOURCES += \
    platformserver.cpp \
    iothread.cpp \
    main.cpp \
    platformservergui.cpp \
    logger.cpp \
    tag.cpp \
    quote.cpp \
    platformclient.cpp \
    movie.cpp \
    book.cpp

FORMS += \
    platformservergui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
