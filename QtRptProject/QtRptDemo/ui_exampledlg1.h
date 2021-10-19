/********************************************************************************
** Form generated from reading UI file 'exampledlg1.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLEDLG1_H
#define UI_EXAMPLEDLG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExampleDlg1
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *edtCustomer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDateEdit *dtp;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnPrint;
    QPushButton *btnClose;

    void setupUi(QDialog *ExampleDlg1)
    {
        if (ExampleDlg1->objectName().isEmpty())
            ExampleDlg1->setObjectName(QStringLiteral("ExampleDlg1"));
        ExampleDlg1->resize(659, 454);
        verticalLayout = new QVBoxLayout(ExampleDlg1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(ExampleDlg1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        edtCustomer = new QLineEdit(ExampleDlg1);
        edtCustomer->setObjectName(QStringLiteral("edtCustomer"));

        horizontalLayout_2->addWidget(edtCustomer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(ExampleDlg1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        dtp = new QDateEdit(ExampleDlg1);
        dtp->setObjectName(QStringLiteral("dtp"));
        dtp->setCalendarPopup(true);

        horizontalLayout->addWidget(dtp);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(ExampleDlg1);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btnPrint = new QPushButton(ExampleDlg1);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));

        horizontalLayout_4->addWidget(btnPrint);

        btnClose = new QPushButton(ExampleDlg1);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout_4->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(ExampleDlg1);
        QObject::connect(btnClose, SIGNAL(clicked()), ExampleDlg1, SLOT(close()));

        QMetaObject::connectSlotsByName(ExampleDlg1);
    } // setupUi

    void retranslateUi(QDialog *ExampleDlg1)
    {
        ExampleDlg1->setWindowTitle(QApplication::translate("ExampleDlg1", "Dialog", 0));
        label->setText(QApplication::translate("ExampleDlg1", "Customer", 0));
        label_2->setText(QApplication::translate("ExampleDlg1", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExampleDlg1", "Goods", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ExampleDlg1", "Quantity", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ExampleDlg1", "Price", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ExampleDlg1", "Sum", 0));
        btnPrint->setText(QApplication::translate("ExampleDlg1", "Print", 0));
        btnClose->setText(QApplication::translate("ExampleDlg1", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ExampleDlg1: public Ui_ExampleDlg1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLEDLG1_H
