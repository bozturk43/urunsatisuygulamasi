/********************************************************************************
** Form generated from reading UI file 'exampledlg2.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLEDLG2_H
#define UI_EXAMPLEDLG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ExampleDlg2
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *table1;
    QTableWidget *table2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnClose;

    void setupUi(QDialog *ExampleDlg2)
    {
        if (ExampleDlg2->objectName().isEmpty())
            ExampleDlg2->setObjectName(QStringLiteral("ExampleDlg2"));
        ExampleDlg2->resize(561, 403);
        gridLayout = new QGridLayout(ExampleDlg2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ExampleDlg2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1, Qt::AlignHCenter);

        label_2 = new QLabel(ExampleDlg2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1, Qt::AlignHCenter);

        table1 = new QTableWidget(ExampleDlg2);
        if (table1->columnCount() < 1)
            table1->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        table1->setObjectName(QStringLiteral("table1"));
        table1->horizontalHeader()->setVisible(false);
        table1->verticalHeader()->setVisible(false);

        gridLayout->addWidget(table1, 2, 0, 1, 2);

        table2 = new QTableWidget(ExampleDlg2);
        if (table2->columnCount() < 1)
            table2->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table2->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        table2->setObjectName(QStringLiteral("table2"));
        table2->horizontalHeader()->setVisible(false);
        table2->verticalHeader()->setVisible(false);

        gridLayout->addWidget(table2, 2, 2, 1, 1);

        label_3 = new QLabel(ExampleDlg2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 0, 1, 3, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrint = new QPushButton(ExampleDlg2);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnClose = new QPushButton(ExampleDlg2);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout->addWidget(btnClose);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 3);


        retranslateUi(ExampleDlg2);
        QObject::connect(btnClose, SIGNAL(clicked()), ExampleDlg2, SLOT(close()));

        QMetaObject::connectSlotsByName(ExampleDlg2);
    } // setupUi

    void retranslateUi(QDialog *ExampleDlg2)
    {
        ExampleDlg2->setWindowTitle(QApplication::translate("ExampleDlg2", "Dialog", 0));
        label->setText(QApplication::translate("ExampleDlg2", "First data source", 0));
        label_2->setText(QApplication::translate("ExampleDlg2", "Second data source", 0));
        QTableWidgetItem *___qtablewidgetitem = table1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExampleDlg2", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table2->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("ExampleDlg2", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        label_3->setText(QApplication::translate("ExampleDlg2", "Two datasource example", 0));
        btnPrint->setText(QApplication::translate("ExampleDlg2", "Print", 0));
        btnClose->setText(QApplication::translate("ExampleDlg2", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ExampleDlg2: public Ui_ExampleDlg2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLEDLG2_H
