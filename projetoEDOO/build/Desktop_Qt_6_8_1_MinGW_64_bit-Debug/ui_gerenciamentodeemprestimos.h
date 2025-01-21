/********************************************************************************
** Form generated from reading UI file 'gerenciamentodeemprestimos.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GERENCIAMENTODEEMPRESTIMOS_H
#define UI_GERENCIAMENTODEEMPRESTIMOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GerenciamentodeEmprestimos
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *GerenciamentodeEmprestimos)
    {
        if (GerenciamentodeEmprestimos->objectName().isEmpty())
            GerenciamentodeEmprestimos->setObjectName("GerenciamentodeEmprestimos");
        GerenciamentodeEmprestimos->resize(1280, 720);
        verticalLayoutWidget = new QWidget(GerenciamentodeEmprestimos);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(200, 120, 861, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName("pushButton_6");

        verticalLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");

        verticalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        label = new QLabel(GerenciamentodeEmprestimos);
        label->setObjectName("label");
        label->setGeometry(QRect(410, 30, 451, 51));
        QFont font;
        font.setPointSize(23);
        label->setFont(font);

        retranslateUi(GerenciamentodeEmprestimos);

        QMetaObject::connectSlotsByName(GerenciamentodeEmprestimos);
    } // setupUi

    void retranslateUi(QDialog *GerenciamentodeEmprestimos)
    {
        GerenciamentodeEmprestimos->setWindowTitle(QCoreApplication::translate("GerenciamentodeEmprestimos", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GerenciamentodeEmprestimos", "Visualizar Empr\303\251stimos Ativos", nullptr));
        pushButton_6->setText(QCoreApplication::translate("GerenciamentodeEmprestimos", "Criar Empr\303\251stimo", nullptr));
        pushButton_5->setText(QCoreApplication::translate("GerenciamentodeEmprestimos", "Encerrar Empr\303\251stimos", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GerenciamentodeEmprestimos", "Modificar Empr\303\251stimos por CPF e ISBN", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GerenciamentodeEmprestimos", "Listar Todos os Empr\303\251stimos", nullptr));
        pushButton->setText(QCoreApplication::translate("GerenciamentodeEmprestimos", "Voltar", nullptr));
        label->setText(QCoreApplication::translate("GerenciamentodeEmprestimos", "Gerenciamento de Empr\303\251stimos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GerenciamentodeEmprestimos: public Ui_GerenciamentodeEmprestimos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GERENCIAMENTODEEMPRESTIMOS_H
