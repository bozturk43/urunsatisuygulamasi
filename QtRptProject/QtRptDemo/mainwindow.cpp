/*
Name: QtRpt
Version: 1.5.2
Programmer: Aleksey Osipov
E-mail: aliks-os@ukr.net
2012-2015

Copyright 2012-2015 Aleksey Osipov

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->btnShow, SIGNAL(clicked()), this, SLOT(showReport()));
}

void MainWindow::showReport() {
    QDialog *dlg = 0;
    if (ui->rBtn1->isChecked()) {
        dlg = new ExampleDlg1(this);
    } else if (ui->rBtn2->isChecked()) {
        dlg = new ExampleDlg2(this);
    } else if (ui->rBtn3->isChecked()) {
        dlg = new ExampleDlg3(this);
    } else if (ui->rBtn4->isChecked()) {
        dlg = new ExampleDlg4(this);
    } else if (ui->rBtn5->isChecked()) {
        dlg = new ExampleDlg5(this);
    } else if (ui->rBtn6a->isChecked()) {
        dlg = new ExampleDlg6(this,1);
    } else if (ui->rBtn6b->isChecked()) {
        dlg = new ExampleDlg6(this,2);
    } else if (ui->rBtn7->isChecked()) {
        dlg = new ExampleDlg7(this);
    } else if (ui->rBtn8->isChecked()) {
        dlg = new ExampleDlg8(this);
    } else if (ui->rBtn9->isChecked()) {
        QString fileName = "./examples_report/example9.xml";
        QtRPT *report = new QtRPT(this);
        if (report->loadReport(fileName) == false) {
            qDebug()<<"Report's file not found";
        }
        report->printExec();
    } else if (ui->rBtn10->isChecked()) {
        QString fileName = "./examples_report/example10.xml";
        QtRPT *report = new QtRPT(this);
        if (report->loadReport(fileName) == false) {
            qDebug()<<"Report's file not found";
        }
        report->printExec();
    } else if (ui->rBtn11->isChecked()) {
        QString fileName = "./examples_report/example11.xml";
        QtRPT *report = new QtRPT(this);
        report->recordCount << 10;
        QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
                         this, SLOT(setValue(const int, const QString, QVariant&, const int)));
        if (report->loadReport(fileName) == false) {
            qDebug()<<"Report's file not found";
        }
        report->printExec();
    } else if (ui->rBtn12->isChecked()) {
        QString fileName = "./examples_report/example12.xml";
        QtRPT *report = new QtRPT(this);
        report->recordCount << 3;
        QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
                         this, SLOT(setValue(const int, const QString, QVariant&, const int)));
        if (report->loadReport(fileName) == false) {
            qDebug()<<"Report's file not found";
        }
        report->printExec();
    } else if (ui->rBtn13->isChecked()) {
        dlg = new ExampleDlg13(this);
    } else if (ui->rBtn14->isChecked()) {
        dlg = new ExampleDlg14(this);
    } else if (ui->rBtn15->isChecked()) {
        QString fileName = "./examples_report/example9.xml";
        QtRPT *report = new QtRPT(this);
        if (report->loadReport(fileName) == false) {
            qDebug()<<"Report's file not found";
        }
        report->printPDF("./example9.pdf",true);
    } else if (ui->rBtnRussian->isChecked()) {
        QString fileName = "./examples_report/RussianInvaders.xml";
        QtRPT *report = new QtRPT(this);
        QObject::connect(report, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
                         this, SLOT(setValue(const int, const QString, QVariant&, const int)));
        if (report->loadReport(fileName) == false) {
            qDebug()<<"Report's file not found";
        }
        report->printExec();
    }
    if (dlg != 0) {
        dlg->exec();
    }
    delete dlg;
}

void MainWindow::setValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage) {
    Q_UNUSED(reportPage);
    if (ui->rBtn11->isChecked()) {
        if (paramName == "bar1") {
            QString tmp;
            if (recNo*2+1 < 10)
                tmp = "0"+QString::number(recNo*2+1);
            else
                tmp = QString::number(recNo*2+1);
            paramValue = "L261250000"+tmp;
        }
        if (paramName == "bar2") {
            QString tmp;
            if (recNo*2+2 < 10)
                tmp = "0"+QString::number(recNo*2+2);
            else
                tmp = QString::number(recNo*2+2);
            paramValue = "L261250000"+tmp;
        }
    }
    if (ui->rBtn12->isChecked()) {
        if (paramName == "text1") {
            if (recNo == 0)
                paramValue = "Mary";
            if (recNo == 1)
                paramValue = "Ella";
            if (recNo == 2)
                paramValue = "Vera";
        }
        if (paramName == "text2") {
            if (recNo == 0)
                paramValue = "chocolate";
            if (recNo == 1)
                paramValue = "banana";
            if (recNo == 2)
                paramValue = "apple";
        }
        if (paramName == "text4") {
            paramValue = "<body><font size=5>This ???????? is formatted by the user by means of HTML tags. You can do the text <b>bold</b>, "
                         "<i>italics</i>, <u>underline</u>. To allocate separate words in various color, as example: <font color=#0000FF>blue</font>, "
                         "<font color=#FF0000>red</font>, <font color=#CC6633>brown</font>, <font color=#00FF00>green</font> etc</font></body>";
        }
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
