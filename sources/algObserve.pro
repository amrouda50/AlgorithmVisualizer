# -EXPLANATION-
#this is a platform independent project file
#this project file is an input to 'qmake' to generate a PLATFORM-DEPENDENT Makefile
#Makefile is an input to 'make' to build our PLATFORM-DEPENDENT qt application
#to set the environment variables you have to install mingw and qt
#in the mingw installation manager > Basic Setup > mingw32-base and mingw32-gcc-g++ must be installed

# -ENVIRONMENT VARIABLES-
#you need to add qmake and g++ to your environment variables in order to make the project from command line
#default locations: 
# 'C:\qt\6.2.0\mingw81_64\bin' where the qmake file is
# 'C:\MinGW\bin' where the g++ file is
# 'C:\MingW\bin' where the make file 
#(if you can't find 'make' in the folder, but you can see 'mingw32-make.exe' file in the same folder ->
#copy and paste 'mingw32-make.exe' into the same folder and rename the file name from 'mingw32-make.exe' to 'make.exe')

# -MAKING THE APPLICATION-
# go to the folder where this XYZ.pro file is located
# qmake XZY.pro -> a Makefile is created from XYZ.pro
# make -> qt.exe is created from Makefile
# qt -> runs qt.exe 
#------------------------------------------------------------------------------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

#produce a debugging version of the application that has the relevant information
CONFIG      += debug
CONFIG      += release console

TEMPLATE    = app

SOURCES += \
    Sorting.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Sorting.h \
    column.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

#this is the name of the exe file
TARGET      = algObserve

!exists( main.cpp ) {
    error( "No main.cpp file found" )
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#win32 {SOURCES += hellowin.cpp} <- platform dependent sources for windows (later development)
#unix {SOURCES += hellounix.cpp} <- platform dependent sources for unix (later development)
