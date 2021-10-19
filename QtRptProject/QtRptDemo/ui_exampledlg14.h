/********************************************************************************
** Form generated from reading UI file 'exampledlg14.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLEDLG14_H
#define UI_EXAMPLEDLG14_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExampleDlg14
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnClose;

    void setupUi(QDialog *ExampleDlg14)
    {
        if (ExampleDlg14->objectName().isEmpty())
            ExampleDlg14->setObjectName(QStringLiteral("ExampleDlg14"));
        ExampleDlg14->resize(617, 531);
        verticalLayout_2 = new QVBoxLayout(ExampleDlg14);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(ExampleDlg14);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setTextFormat(Qt::PlainText);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit = new QTextEdit(ExampleDlg14);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(textEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ExampleDlg14);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/Logo128.png")));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnPrint = new QPushButton(ExampleDlg14);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnClose = new QPushButton(ExampleDlg14);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout->addWidget(btnClose);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ExampleDlg14);
        QObject::connect(btnClose, SIGNAL(clicked()), ExampleDlg14, SLOT(close()));

        QMetaObject::connectSlotsByName(ExampleDlg14);
    } // setupUi

    void retranslateUi(QDialog *ExampleDlg14)
    {
        ExampleDlg14->setWindowTitle(QApplication::translate("ExampleDlg14", "Dialog", 0));
        label_2->setText(QApplication::translate("ExampleDlg14", "Creation of the report from user application without XML file", 0));
        textEdit->setHtml(QApplication::translate("ExampleDlg14", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; font-style:italic;\">This example shows how user can create a report from own application without using XML file.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; font-style:italic;\">The part of the code</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt"
                        ";\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#800080;\">QtRPT</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#000000;\">*report</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#000000;\">=</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#808000;\">new</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#800080;\">QtRPT</span><span style=\" font-size:8pt; color:#000000;\">(</span><span style=\" font-size:8pt; color:#808000;\">this</span><span style=\" font-size:8pt; color:#000000;\">);</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier'; font-size:8pt;\">"
                        "<br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">//Make</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">a</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">page</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">of</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">report</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">RptPageObject</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">*page</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#808000;\">new</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">RptPageObject</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">();</span></p>\n"
"<p style=\" margin-"
                        "top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">page-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">pageNo</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000080;\">0</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">report-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">pageList</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">.append(page);</span><span style=\" font-family:'Co"
                        "urier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">//Append</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">page</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">to</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">the</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">report</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; t"
                        "ext-indent:0px; font-family:'Courier New,courier'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">//Make</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">a</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">ReportTitleBand</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">RptBandObject</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Co"
                        "urier New,courier'; font-size:8pt; color:#000000;\">*band1</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#808000;\">new</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">RptBandObject</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">();</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">band1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">nam"
                        "e</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">&quot;ReportTitle&quot;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">band1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">height</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,c"
                        "ourier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000080;\">80</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">band1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">type</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">ReportTitle</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p s"
                        "tyle=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">page-&gt;addBand(band1);</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">//Append</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">band</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">to</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">the</span><span style=\" font-family:'Courier New,courier'; font-size:8p"
                        "t; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">page</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier'; font-size:8pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">//Make</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">a</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">field</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">RptFieldObject</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">*field1</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#808000;\">new</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">RptFieldObject</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">();</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-"
                        "left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">name</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">&quot;field1&quot;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; col"
                        "or:#800000;\">fieldType</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">Text</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">rect</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">.setTop(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000080;\">0</span><span style=\" font-family:'Cour"
                        "ier New,courier'; font-size:8pt; color:#000000;\">);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">rect</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">.setLeft(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000080;\">0</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">rect</span><span style=\" font-family:'Courier New,c"
                        "ourier'; font-size:8pt; color:#000000;\">.setHeight(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000080;\">60</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">rect</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">.setWidth(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000080;\">700</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';"
                        " font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">font</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">.setBold(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#808000;\">true</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">font</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">.setPointSize(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000080;\">24</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">"
                        ");</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">aligment</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">Qt</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">::</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">AlignCenter</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bot"
                        "tom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">textWrap</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000080;\">1</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; "
                        "color:#800000;\">value</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">&quot;Creation</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">of</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">the</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">report</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c"
                        "0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">from</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">user</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">application</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">without</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">XML</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">file"
                        "&quot;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">borderLeft</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">Qt</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">::</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">white</span><span style=\" font-family:'Courier New,courier"
                        "'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">borderRight</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">Qt</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">::</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">white</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p styl"
                        "e=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">borderBottom</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">Qt</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">::</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">white</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; m"
                        "argin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">field1-&gt;</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800000;\">borderTop</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">=</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">Qt</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">::</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">white</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span"
                        " style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">band1-&gt;addField(field1);</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\">  </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">//Append</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">field</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">to</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">the</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#008000;\">ReportT"
                        "itleBand</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier'; font-size:8pt; color:#008000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#000000;\">report-&gt;</span><span style=\" font-size:8pt; color:#800000;\">recordCount</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#000000;\">&lt;&lt;</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#000080;\">4</span><span style=\" font-size:8pt; color:#000000;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">QObject</span><span style=\" f"
                        "ont-family:'Courier New,courier'; font-size:8pt; color:#000000;\">::connect(report,</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#808000;\">SIGNAL</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt;\">setField</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">RptFieldObject</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">&amp;)),</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#808000;\">this</span><span style=\" "
                        "font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">,</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#808000;\">SLOT</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt;\">setField</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">(</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#800080;\">RptFieldObject</span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">&amp;)));</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New,courier'; font-size:8pt;\"><br /></p"
                        ">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier'; font-size:8pt; color:#000000;\">report-&gt;printExec();</span></p></body></html>", 0));
        label->setText(QString());
        btnPrint->setText(QApplication::translate("ExampleDlg14", "Print", 0));
        btnClose->setText(QApplication::translate("ExampleDlg14", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ExampleDlg14: public Ui_ExampleDlg14 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLEDLG14_H
