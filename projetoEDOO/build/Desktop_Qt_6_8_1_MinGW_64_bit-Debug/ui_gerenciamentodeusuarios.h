/********************************************************************************
** Form generated from reading UI file 'gerenciamentodeusuarios.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GERENCIAMENTODEUSUARIOS_H
#define UI_GERENCIAMENTODEUSUARIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GerenciamentoDeUsuarios
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *GerenciamentoDeUsuarios)
    {
        if (GerenciamentoDeUsuarios->objectName().isEmpty())
            GerenciamentoDeUsuarios->setObjectName("GerenciamentoDeUsuarios");
        GerenciamentoDeUsuarios->resize(1280, 720);
        label = new QLabel(GerenciamentoDeUsuarios);
        label->setObjectName("label");
        label->setGeometry(QRect(470, 30, 391, 31));
        QFont font;
        font.setPointSize(23);
        label->setFont(font);
        verticalLayoutWidget = new QWidget(GerenciamentoDeUsuarios);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(210, 110, 911, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName("pushButton_6");

        verticalLayout->addWidget(pushButton_6);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(GerenciamentoDeUsuarios);

        QMetaObject::connectSlotsByName(GerenciamentoDeUsuarios);
    } // setupUi

    void retranslateUi(QDialog *GerenciamentoDeUsuarios)
    {
        GerenciamentoDeUsuarios->setWindowTitle(QCoreApplication::translate("GerenciamentoDeUsuarios", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("GerenciamentoDeUsuarios", "Gerenciamento de  Usu\303\241rios", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GerenciamentoDeUsuarios", "Cadastrar Usu\303\241rio", nullptr));
        pushButton_5->setText(QCoreApplication::translate("GerenciamentoDeUsuarios", "Remover Usu\303\241rio Por CPF", nullptr));
        pushButton_6->setText(QCoreApplication::translate("GerenciamentoDeUsuarios", "Remover Usu\303\241rio Por Nome", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GerenciamentoDeUsuarios", "Editar Usu\303\241rio Existente", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GerenciamentoDeUsuarios", "Listar Usu\303\241rios", nullptr));
        pushButton->setText(QCoreApplication::translate("GerenciamentoDeUsuarios", "Voltar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GerenciamentoDeUsuarios: public Ui_GerenciamentoDeUsuarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GERENCIAMENTODEUSUARIOS_H
