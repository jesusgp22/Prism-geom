#-------------------------------------------------
#
# Project created by QtCreator 2013-11-30T18:00:11
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = compiladores
TEMPLATE = app


SOURCES +=\
    mainwindow.cpp \
    main.cpp \
    prism.tab.cpp \
    lex.yy.cpp \
    viewport.cpp \
    viewer.cpp

HEADERS  += mainwindow.h \
    prism.tab.h \
    ast.h \
    ast_declaration.h \
    viewport.h \
    viewer.h \
    drawable.h

FORMS    += mainwindow.ui \
    viewer.ui

RESOURCES += \
    recursos.qrc

OTHER_FILES += \
    prism.y \
    prism.l

LIBS += -L/usr/local/lib -lglut \
        -L/usr/local/lib -lGLU
