/********************************************************************************
** Form generated from reading UI file 'exampledlg8.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLEDLG8_H
#define UI_EXAMPLEDLG8_H

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

class Ui_ExampleDlg8
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnClose;

    void setupUi(QDialog *ExampleDlg8)
    {
        if (ExampleDlg8->objectName().isEmpty())
            ExampleDlg8->setObjectName(QStringLiteral("ExampleDlg8"));
        ExampleDlg8->resize(697, 382);
        verticalLayout = new QVBoxLayout(ExampleDlg8);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(ExampleDlg8);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrint = new QPushButton(ExampleDlg8);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnClose = new QPushButton(ExampleDlg8);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ExampleDlg8);
        QObject::connect(btnClose, SIGNAL(clicked()), ExampleDlg8, SLOT(close()));

        QMetaObject::connectSlotsByName(ExampleDlg8);
    } // setupUi

    void retranslateUi(QDialog *ExampleDlg8)
    {
        ExampleDlg8->setWindowTitle(QApplication::translate("ExampleDlg8", "Dialog", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExampleDlg8", "No", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ExampleDlg8", "Text", 0));
        btnPrint->setText(QApplication::translate("ExampleDlg8", "Print", 0));
        btnClose->setText(QApplication::translate("ExampleDlg8", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ExampleDlg8: public Ui_ExampleDlg8 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLEDLG8_H
