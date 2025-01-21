/********************************************************************************
** Form generated from reading UI file 'gerenciamentolivros.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GERENCIAMENTOLIVROS_H
#define UI_GERENCIAMENTOLIVROS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GerenciamentoLivros
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *GerenciamentoLivros)
    {
        if (GerenciamentoLivros->objectName().isEmpty())
            GerenciamentoLivros->setObjectName("GerenciamentoLivros");
        GerenciamentoLivros->resize(1280, 720);
        verticalLayoutWidget = new QWidget(GerenciamentoLivros);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(270, 120, 751, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");

        verticalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        label = new QLabel(GerenciamentoLivros);
        label->setObjectName("label");
        label->setGeometry(QRect(470, 30, 351, 30));
        QFont font;
        font.setPointSize(23);
        label->setFont(font);

        retranslateUi(GerenciamentoLivros);

        QMetaObject::connectSlotsByName(GerenciamentoLivros);
    } // setupUi

    void retranslateUi(QDialog *GerenciamentoLivros)
    {
        GerenciamentoLivros->setWindowTitle(QCoreApplication::translate("GerenciamentoLivros", "Dialog", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GerenciamentoLivros", "Cadastrar Livro", nullptr));
        pushButton_5->setText(QCoreApplication::translate("GerenciamentoLivros", "Remover Livro Por ISBN", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GerenciamentoLivros", "Editar Livro Existente", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GerenciamentoLivros", "Listar Livros", nullptr));
        pushButton->setText(QCoreApplication::translate("GerenciamentoLivros", "Voltar", nullptr));
        label->setText(QCoreApplication::translate("GerenciamentoLivros", "Gerenciamento de Livros", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GerenciamentoLivros: public Ui_GerenciamentoLivros {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GERENCIAMENTOLIVROS_H
