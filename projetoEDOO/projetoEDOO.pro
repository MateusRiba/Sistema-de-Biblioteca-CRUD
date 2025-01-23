QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cadastrousuarioadm.cpp \
    gerenciamentodeemprestimos.cpp \
    gerenciamentodeusuarios.cpp \
    gerenciamentolivros.cpp \
    main.cpp \
    mainwindow.cpp \
    removerusuariocpf.cpp

HEADERS += \
    cadastrousuarioadm.h \
    gerenciamentodeemprestimos.h \
    gerenciamentodeusuarios.h \
    gerenciamentolivros.h \
    mainwindow.h \
    removerusuariocpf.h

FORMS += \
    cadastrousuarioadm.ui \
    gerenciamentodeemprestimos.ui \
    gerenciamentodeusuarios.ui \
    gerenciamentolivros.ui \
    mainwindow.ui \
    removerusuariocpf.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
