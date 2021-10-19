/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPrint;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rBtn1;
    QRadioButton *rBtn2;
    QRadioButton *rBtn3;
    QRadioButton *rBtn4;
    QRadioButton *rBtn5;
    QRadioButton *rBtn6a;
    QRadioButton *rBtn6b;
    QRadioButton *rBtn7;
    QRadioButton *rBtn8;
    QRadioButton *rBtn9;
    QRadioButton *rBtn10;
    QRadioButton *rBtn11;
    QRadioButton *rBtn12;
    QRadioButton *rBtnRussian;
    QRadioButton *rBtn13;
    QRadioButton *rBtn14;
    QRadioButton *rBtn15;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *btnShow;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(517, 494);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionPrint->setCheckable(false);
        actionPrint->setChecked(false);
        actionPrint->setEnabled(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rBtn1 = new QRadioButton(groupBox);
        rBtn1->setObjectName(QStringLiteral("rBtn1"));
        rBtn1->setChecked(true);

        verticalLayout_2->addWidget(rBtn1);

        rBtn2 = new QRadioButton(groupBox);
        rBtn2->setObjectName(QStringLiteral("rBtn2"));

        verticalLayout_2->addWidget(rBtn2);

        rBtn3 = new QRadioButton(groupBox);
        rBtn3->setObjectName(QStringLiteral("rBtn3"));

        verticalLayout_2->addWidget(rBtn3);

        rBtn4 = new QRadioButton(groupBox);
        rBtn4->setObjectName(QStringLiteral("rBtn4"));

        verticalLayout_2->addWidget(rBtn4);

        rBtn5 = new QRadioButton(groupBox);
        rBtn5->setObjectName(QStringLiteral("rBtn5"));

        verticalLayout_2->addWidget(rBtn5);

        rBtn6a = new QRadioButton(groupBox);
        rBtn6a->setObjectName(QStringLiteral("rBtn6a"));

        verticalLayout_2->addWidget(rBtn6a);

        rBtn6b = new QRadioButton(groupBox);
        rBtn6b->setObjectName(QStringLiteral("rBtn6b"));

        verticalLayout_2->addWidget(rBtn6b);

        rBtn7 = new QRadioButton(groupBox);
        rBtn7->setObjectName(QStringLiteral("rBtn7"));

        verticalLayout_2->addWidget(rBtn7);

        rBtn8 = new QRadioButton(groupBox);
        rBtn8->setObjectName(QStringLiteral("rBtn8"));

        verticalLayout_2->addWidget(rBtn8);

        rBtn9 = new QRadioButton(groupBox);
        rBtn9->setObjectName(QStringLiteral("rBtn9"));

        verticalLayout_2->addWidget(rBtn9);

        rBtn10 = new QRadioButton(groupBox);
        rBtn10->setObjectName(QStringLiteral("rBtn10"));

        verticalLayout_2->addWidget(rBtn10);

        rBtn11 = new QRadioButton(groupBox);
        rBtn11->setObjectName(QStringLiteral("rBtn11"));

        verticalLayout_2->addWidget(rBtn11);

        rBtn12 = new QRadioButton(groupBox);
        rBtn12->setObjectName(QStringLiteral("rBtn12"));

        verticalLayout_2->addWidget(rBtn12);

        rBtnRussian = new QRadioButton(groupBox);
        rBtnRussian->setObjectName(QStringLiteral("rBtnRussian"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        rBtnRussian->setFont(font);
        rBtnRussian->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        verticalLayout_2->addWidget(rBtnRussian);

        rBtn13 = new QRadioButton(groupBox);
        rBtn13->setObjectName(QStringLiteral("rBtn13"));

        verticalLayout_2->addWidget(rBtn13);

        rBtn14 = new QRadioButton(groupBox);
        rBtn14->setObjectName(QStringLiteral("rBtn14"));

        verticalLayout_2->addWidget(rBtn14);

        rBtn15 = new QRadioButton(groupBox);
        rBtn15->setObjectName(QStringLiteral("rBtn15"));

        verticalLayout_2->addWidget(rBtn15);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/Logo128.png")));

        verticalLayout->addWidget(label);

        btnShow = new QPushButton(groupBox);
        btnShow->setObjectName(QStringLiteral("btnShow"));

        verticalLayout->addWidget(btnShow);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 517, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QtRPT examples", 0));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Select example", 0));
        rBtn1->setText(QApplication::translate("MainWindow", "Invoice report (data from grid)", 0));
        rBtn2->setText(QApplication::translate("MainWindow", "Two datasource report", 0));
        rBtn3->setText(QApplication::translate("MainWindow", "Embedded report widget", 0));
        rBtn4->setText(QApplication::translate("MainWindow", "Report with condition (Printable and highlighting fields)", 0));
        rBtn5->setText(QApplication::translate("MainWindow", "Report with mathematics and aggregate functions", 0));
        rBtn6a->setText(QApplication::translate("MainWindow", "Report with grouping data in Master Data Band 1", 0));
        rBtn6b->setText(QApplication::translate("MainWindow", "Report with grouping data in Master Data Band 2", 0));
        rBtn7->setText(QApplication::translate("MainWindow", "Report with Diagram", 0));
        rBtn8->setText(QApplication::translate("MainWindow", "Report with AutoHeight", 0));
        rBtn9->setText(QApplication::translate("MainWindow", "Report with Drawing", 0));
        rBtn10->setText(QApplication::translate("MainWindow", "Report with SQL query to SQLITE DB", 0));
        rBtn11->setText(QApplication::translate("MainWindow", "Barcode generator", 0));
        rBtn12->setText(QApplication::translate("MainWindow", "Report with RichText Fields", 0));
        rBtnRussian->setText(QApplication::translate("MainWindow", "Russian invaders", 0));
        rBtn13->setText(QApplication::translate("MainWindow", "Report's control from user application", 0));
        rBtn14->setText(QApplication::translate("MainWindow", "Creation of the report from the user application without XML file", 0));
        rBtn15->setText(QApplication::translate("MainWindow", "Generate PDF file", 0));
        label->setText(QString());
        btnShow->setText(QApplication::translate("MainWindow", "Show", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
