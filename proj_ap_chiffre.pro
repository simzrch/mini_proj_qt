QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    projet.cpp

HEADERS += \
    projet.h

FORMS += \
    interface.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/../../biblio/chiftrementLIB/ -lchiffrement1

INCLUDEPATH += $$PWD/../../biblio/chiftrementLIB
DEPENDPATH += $$PWD/../../biblio/chiftrementLIB

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../biblio/chiftrementLIB/chiffrement1.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../biblio/chiftrementLIB/libchiffrement1.a

win32: LIBS += -L$$PWD/../../biblio/cryptopp/ -lcryptlib

INCLUDEPATH += $$PWD/../../biblio/cryptopp
DEPENDPATH += $$PWD/../../biblio/cryptopp

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../biblio/cryptopp/cryptlib.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../biblio/cryptopp/libcryptlib.a
