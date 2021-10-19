/********************************************************************************
** Form generated from reading UI file 'exampledlg13.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLEDLG13_H
#define UI_EXAMPLEDLG13_H

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

class Ui_ExampleDlg13
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

    void setupUi(QDialog *ExampleDlg13)
    {
        if (ExampleDlg13->objectName().isEmpty())
            ExampleDlg13->setObjectName(QStringLiteral("ExampleDlg13"));
        ExampleDlg13->resize(580, 392);
        ExampleDlg13->setWindowTitle(QStringLiteral("Example #13"));
        verticalLayout_2 = new QVBoxLayout(ExampleDlg13);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(ExampleDlg13);
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
        textEdit = new QTextEdit(ExampleDlg13);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(textEdit);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ExampleDlg13);
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

        btnPrint = new QPushButton(ExampleDlg13);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnClose = new QPushButton(ExampleDlg13);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout->addWidget(btnClose);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ExampleDlg13);
        QObject::connect(btnClose, SIGNAL(clicked()), ExampleDlg13, SLOT(close()));

        QMetaObject::connectSlotsByName(ExampleDlg13);
    } // setupUi

    void retranslateUi(QDialog *ExampleDlg13)
    {
        label_2->setText(QApplication::translate("ExampleDlg13", "Control fields and bands properties from user application", 0));
        textEdit->setHtml(QApplication::translate("ExampleDlg13", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">This example shows how user can control and change properties of fields and bands from own application during the report building.<br /><br />For custom processing, user must connect the following signal<br /></span><span style=\" font-size:8pt; color:#800080;\">QObject</span><span style=\" font-size:8pt; color:#000000;\">::connect(report,</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#808000;\">SIGNAL</span><span style=\" font-size:8pt; color:#000000;\">(</span><span styl"
                        "e=\" font-size:8pt;\">setField</span><span style=\" font-size:8pt; color:#000000;\">(</span><span style=\" font-size:8pt; color:#800080;\">RptFieldObject</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#000000;\">&amp;)),</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#808000;\">this</span><span style=\" font-size:8pt; color:#000000;\">,</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#808000;\">SLOT</span><span style=\" font-size:8pt; color:#000000;\">(</span><span style=\" font-size:8pt;\">setField</span><span style=\" font-size:8pt; color:#000000;\">(</span><span style=\" font-size:8pt; color:#800080;\">RptFieldObject</span><span style=\" font-size:8pt; color:#c0c0c0;\"> </span><span style=\" font-size:8pt; color:#000000;\">&amp;)));</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px; font-size:8pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#000000;\">Then you may change the property of the </span><span style=\" font-size:8pt; color:#800080;\">RptFieldObject.<br /><br /></span><span style=\" font-size:8pt; color:#000000;\">For more information please take a look at documentation or at example code.</span></p></body></html>", 0));
        label->setText(QString());
        btnPrint->setText(QApplication::translate("ExampleDlg13", "Print", 0));
        btnClose->setText(QApplication::translate("ExampleDlg13", "Close", 0));
        Q_UNUSED(ExampleDlg13);
    } // retranslateUi

};

namespace Ui {
    class ExampleDlg13: public Ui_ExampleDlg13 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLEDLG13_H
