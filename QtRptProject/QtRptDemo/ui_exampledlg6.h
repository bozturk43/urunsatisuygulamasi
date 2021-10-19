/********************************************************************************
** Form generated from reading UI file 'exampledlg6.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLEDLG6_H
#define UI_EXAMPLEDLG6_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExampleDlg6
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnPrint;
    QPushButton *btnClose;

    void setupUi(QDialog *ExampleDlg6)
    {
        if (ExampleDlg6->objectName().isEmpty())
            ExampleDlg6->setObjectName(QStringLiteral("ExampleDlg6"));
        ExampleDlg6->resize(938, 448);
        verticalLayout = new QVBoxLayout(ExampleDlg6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(ExampleDlg6);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btnPrint = new QPushButton(ExampleDlg6);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));

        horizontalLayout_4->addWidget(btnPrint);

        btnClose = new QPushButton(ExampleDlg6);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout_4->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(ExampleDlg6);
        QObject::connect(btnClose, SIGNAL(clicked()), ExampleDlg6, SLOT(close()));

        QMetaObject::connectSlotsByName(ExampleDlg6);
    } // setupUi

    void retranslateUi(QDialog *ExampleDlg6)
    {
        ExampleDlg6->setWindowTitle(QApplication::translate("ExampleDlg6", "Example 6", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExampleDlg6", "Market", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ExampleDlg6", "Goods", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ExampleDlg6", "Quantity", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ExampleDlg6", "Price", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ExampleDlg6", "Sum", 0));
        btnPrint->setText(QApplication::translate("ExampleDlg6", "Print", 0));
        btnClose->setText(QApplication::translate("ExampleDlg6", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ExampleDlg6: public Ui_ExampleDlg6 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLEDLG6_H
