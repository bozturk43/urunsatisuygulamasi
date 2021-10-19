/********************************************************************************
** Form generated from reading UI file 'exampledlg5.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLEDLG5_H
#define UI_EXAMPLEDLG5_H

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

class Ui_ExampleDlg5
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnClose;

    void setupUi(QDialog *ExampleDlg5)
    {
        if (ExampleDlg5->objectName().isEmpty())
            ExampleDlg5->setObjectName(QStringLiteral("ExampleDlg5"));
        ExampleDlg5->resize(596, 352);
        verticalLayout = new QVBoxLayout(ExampleDlg5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(ExampleDlg5);
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

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrint = new QPushButton(ExampleDlg5);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnClose = new QPushButton(ExampleDlg5);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ExampleDlg5);
        QObject::connect(btnClose, SIGNAL(clicked()), ExampleDlg5, SLOT(close()));

        QMetaObject::connectSlotsByName(ExampleDlg5);
    } // setupUi

    void retranslateUi(QDialog *ExampleDlg5)
    {
        ExampleDlg5->setWindowTitle(QApplication::translate("ExampleDlg5", "Dialog", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExampleDlg5", "Goods", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ExampleDlg5", "Quant", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ExampleDlg5", "Price", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ExampleDlg5", "Sum", 0));
        btnPrint->setText(QApplication::translate("ExampleDlg5", "Print", 0));
        btnClose->setText(QApplication::translate("ExampleDlg5", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ExampleDlg5: public Ui_ExampleDlg5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLEDLG5_H
