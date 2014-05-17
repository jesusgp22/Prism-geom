#-------------------------------------------------
#
# Project created by QtCreator 2013-11-30T18:00:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = compiladores
TEMPLATE = app


SOURCES +=\
    mainwindow.cpp \
    main.cpp \
    prism.tab.cpp \
    lex.yy.cpp

HEADERS  += mainwindow.h \
    prism.tab.h \
    ast.h \
    ast_declaration.h

FORMS    += mainwindow.ui

RESOURCES += \
    recursos.qrc

OTHER_FILES += \
    prism.y \
    prism.l
