QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Actions.cpp \
    CountryList.cpp \
    Demon.cpp \
    Family.cpp \
    CountryList.cpp \
    Heaven.cpp \
    HeavenTree.cpp \
    Hell.cpp \
    Human.cpp \
    HumanList.cpp \
    ListCountry.cpp \
    PeopleTree.cpp \
    TheWorld.cpp \
    Universe.cpp \
    helper.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    estructurasHumanos.h \
    helper.h \
    mainwindow.h \
    structs.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
