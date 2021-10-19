/********************************************************************************
** Form generated from reading UI file 'exampledlg3.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLEDLG3_H
#define UI_EXAMPLEDLG3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExampleDlg3
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *edtFirstName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *edtLastName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *edtEmail;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnUpdatePreview;
    QPushButton *btnClose;

    void setupUi(QDialog *ExampleDlg3)
    {
        if (ExampleDlg3->objectName().isEmpty())
            ExampleDlg3->setObjectName(QStringLiteral("ExampleDlg3"));
        ExampleDlg3->resize(715, 596);
        verticalLayout_2 = new QVBoxLayout(ExampleDlg3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(ExampleDlg3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        edtFirstName = new QLineEdit(ExampleDlg3);
        edtFirstName->setObjectName(QStringLiteral("edtFirstName"));

        horizontalLayout_2->addWidget(edtFirstName);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(ExampleDlg3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        edtLastName = new QLineEdit(ExampleDlg3);
        edtLastName->setObjectName(QStringLiteral("edtLastName"));

        horizontalLayout_3->addWidget(edtLastName);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(ExampleDlg3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        edtEmail = new QLineEdit(ExampleDlg3);
        edtEmail->setObjectName(QStringLiteral("edtEmail"));

        horizontalLayout_4->addWidget(edtEmail);


        verticalLayout_2->addLayout(horizontalLayout_4);

        widget = new QWidget(ExampleDlg3);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnUpdatePreview = new QPushButton(ExampleDlg3);
        btnUpdatePreview->setObjectName(QStringLiteral("btnUpdatePreview"));

        horizontalLayout->addWidget(btnUpdatePreview);

        btnClose = new QPushButton(ExampleDlg3);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout->addWidget(btnClose);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ExampleDlg3);
        QObject::connect(btnClose, SIGNAL(clicked()), ExampleDlg3, SLOT(close()));

        QMetaObject::connectSlotsByName(ExampleDlg3);
    } // setupUi

    void retranslateUi(QDialog *ExampleDlg3)
    {
        ExampleDlg3->setWindowTitle(QApplication::translate("ExampleDlg3", "Dialog", 0));
        label->setText(QApplication::translate("ExampleDlg3", "First name", 0));
        label_2->setText(QApplication::translate("ExampleDlg3", "Last Name", 0));
        label_3->setText(QApplication::translate("ExampleDlg3", "E-mail", 0));
        btnUpdatePreview->setText(QApplication::translate("ExampleDlg3", "Update preview", 0));
        btnClose->setText(QApplication::translate("ExampleDlg3", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ExampleDlg3: public Ui_ExampleDlg3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLEDLG3_H
