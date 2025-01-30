QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cadastro.cpp \
    digitalbookslist.cpp \
    emprestimosativos.cpp \
    emprestimosfinalizados.cpp \
    fmadicionaremprestimo.cpp \
    fmadicionarlivros.cpp \
    fmadicionarlivrosfisicos.cpp \
    fmeditaremprestimo.cpp \
    fmeditarlivros.cpp \
    fmeditarlivrosfisicos.cpp \
    fmeditarusuario.cpp \
    fmgerenciaremprestimos.cpp \
    gerenciamentolivros.cpp \
    gerenciamentolivrosfisicos.cpp \
    gerenciamentousuarios.cpp \
    listagememprestimos.cpp \
    listagemlivrosfisicos.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menuadministradorlogado.cpp \
    menuleitorlogado.cpp \
    menulivros.cpp \
    sessao.cpp

HEADERS += \
    cadastro.h \
    digitalbookslist.h \
    emprestimosativos.h \
    emprestimosfinalizados.h \
    fmadicionaremprestimo.h \
    fmadicionarlivros.h \
    fmadicionarlivrosfisicos.h \
    fmeditaremprestimo.h \
    fmeditarlivros.h \
    fmeditarlivrosfisicos.h \
    fmeditarusuario.h \
    fmgerenciaremprestimos.h \
    gerenciamentolivros.h \
    gerenciamentolivrosfisicos.h \
    gerenciamentousuarios.h \
    listagememprestimos.h \
    listagemlivrosfisicos.h \
    login.h \
    mainwindow.h \
    menuadministradorlogado.h \
    menuleitorlogado.h \
    menulivros.h \
    sessao.h

FORMS += \
    cadastro.ui \
    digitalbookslist.ui \
    emprestimosativos.ui \
    emprestimosfinalizados.ui \
    fmadicionaremprestimo.ui \
    fmadicionarlivros.ui \
    fmadicionarlivrosfisicos.ui \
    fmeditaremprestimo.ui \
    fmeditarlivros.ui \
    fmeditarlivrosfisicos.ui \
    fmeditarusuario.ui \
    fmgerenciaremprestimos.ui \
    gerenciamentolivros.ui \
    gerenciamentolivrosfisicos.ui \
    gerenciamentousuarios.ui \
    listagememprestimos.ui \
    listagemlivrosfisicos.ui \
    login.ui \
    mainwindow.ui \
    menuadministradorlogado.ui \
    menuleitorlogado.ui \
    menulivros.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
