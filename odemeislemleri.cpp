#include "odemeislemleri.h"
#include "ui_odemeislemleri.h"
#include <QtSql/QSqlDatabase>
#include<QTableWidgetItem>
#include <QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include <QDateEdit>
#include <qtrpt.h>
#include<QDebug>
#include<QMessageBox>

odemeislemleri::odemeislemleri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::odemeislemleri)
{
    ui->setupUi(this);
    musteriCekme();

    ui->dateEdit->setDate(QDate::currentDate());
    ui->basTarih->setDate(QDate::currentDate());
    ui->bitTar->setDate(QDate::currentDate());
    const QStringList baslik{"Tarih","Aciklama","AlinanUcret","VerilenOdeme","Bakiye"};
    ui->cariTablo->setColumnCount(baslik.size());
    ui->cariTablo->setHorizontalHeaderLabels(baslik);
    ui->cariTablo->setColumnWidth(Tarih,70);
    ui->cariTablo->setColumnWidth(Aciklama,190);
    ui->cariTablo->setColumnWidth(AlinanUcret,100);
    ui->cariTablo->setColumnWidth(VerilenOdeme,100);
    ui->cariTablo->setColumnWidth(Bakiye,100);
    tabloTemizle();


}

odemeislemleri::~odemeislemleri()
{
    delete ui;
}

void odemeislemleri::musteriCekme()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT mAd FROM musteribilgi");
    while(qry.next()){
        QString mAdi=qry.value(0).toString();
        ui->mAdCmb->addItem(mAdi);
    }
    db.close();
}

void odemeislemleri::cariCekme()
{
   QString ad= ui->mAdCmb->currentText();
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//caridatabase.db");
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT tarih,aciklama,alinan_ucret,verilen_odeme,bakiye FROM caritablo WHERE m_Adi='"+ad+"'");
    while(qry.next()){
        QString tar=qry.value(0).toString();
        QString ac=qry.value(1).toString();
        QString al=qry.value(2).toString();
        QString ver=qry.value(3).toString();
        QString bak=qry.value(4).toString();

        const int row=ui->cariTablo->rowCount();
        ui->cariTablo->insertRow(row);
        ui->cariTablo->setItem(row,Tarih,new QTableWidgetItem(tar));
        ui->cariTablo->setItem(row,Aciklama,new QTableWidgetItem(ac));
        ui->cariTablo->setItem(row,AlinanUcret,new QTableWidgetItem(al));
        ui->cariTablo->setItem(row,VerilenOdeme,new QTableWidgetItem(ver));
        ui->cariTablo->setItem(row,Bakiye,new QTableWidgetItem(bak));
    }
    db.close();
}

void odemeislemleri::faturaYazdir()
{
    QtRPT *report=new QtRPT(this);
    report->loadReport(":/faturarapor.xml");
    report->recordCount.append(1);
    connect(report, &QtRPT::setValue,[&](const int recNo,
            const QString paramName, QVariant &paramValue,
            const int reportPage){
                (void)reportPage;

                if(paramName=="tarih"){
                    QDate dt=ui->dateEdit->date();
                    QString dtv=dt.toString("dd.MM.yyyy");
                    paramValue=dtv;
                }

                if(paramName=="mAdi"){
                    paramValue=ui->mAdCmb->currentText();
                }
                if(paramName=="oBorc"){
                    paramValue=ui->mBorcDsb->value();
                }
                if(paramName=="yOdeme"){
                    paramValue=ui->alinanUcDsb->value();
                }
                if(paramName=="kBorc"){
                    double borc=ui->mBorcDsb->value();
                    double tutar=ui->alinanUcDsb->value();
                    double topborc=borc-tutar;

                    paramValue=topborc;
                }
    });
    report->printExec();
}

void odemeislemleri::cariYazdir()
{
    QtRPT *report=new QtRPT(this);
    report->loadReport(":/caridokum.xml");
    report->recordCount.append(ui->cariTablo->rowCount());
    connect(report, &QtRPT::setValue,[&](const int recNo,
            const QString paramName, QVariant &paramValue,
            const int reportPage){
                (void)reportPage;

                   if(paramName=="guntarih"){
                       QDate dt=ui->dateEdit->date();
                       QString dtv=dt.toString("dd.MM.yyyy");
                       paramValue=dtv;
                }
                if(paramName=="tarih"){
                    paramValue=ui->cariTablo->item(recNo,Tarih)->text();
                }
                if(paramName=="aciklama"){
                    paramValue=ui->cariTablo->item(recNo,Aciklama)->text();
                }
                if(paramName=="alinanucret"){
                    paramValue=ui->cariTablo->item(recNo,AlinanUcret)->text();
                }
                if(paramName=="verilenodeme"){
                    paramValue=ui->cariTablo->item(recNo,VerilenOdeme)->text();
                }
                if(paramName=="bakiye"){
                    paramValue=ui->cariTablo->item(recNo,Bakiye)->text();
                }
                if(paramName=="mAd"){
                    paramValue=ui->mAdCmb->currentText();
                }
                if(paramName=="mBorc"){
                    paramValue=ui->mBorcDsb->value();
                }

    });
    report->printExec();
}

void odemeislemleri::on_mAdCmb_currentTextChanged(const QString &arg1)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    QString Ad=ui->mAdCmb->currentText();
    qry.exec("SELECT mBorc FROM musteribilgi where mAd='"+Ad+"'");
    if(qry.next()){
        double mBorcu=qry.value(0).toDouble();
        ui->mBorcDsb->setValue(mBorcu);
    }
    db.close();
    ui->doubleSpinBox->setValue(0.00);
    ui->alinanUcDsb->setValue(0.00);
    tabloTemizle();
}

void odemeislemleri::on_pushButton_3_clicked()
{
    QString ad= ui->mAdCmb->currentText();
    QDate bas=ui->basTarih->date();
    QDate bit=ui->bitTar->date().addDays(1);
     QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//caridatabase.db");
     db.open();
     QSqlQuery qry(db);
     qry.prepare("SELECT * FROM caritablo WHERE m_Adi=:AD and tarih>=:BAS and tarih<:BIT ");
     qry.bindValue(":AD",ad);
     qry.bindValue(":BAS",bas);
     qry.bindValue(":BIT",bit);
     qry.exec();
     tabloTemizle();
     qDebug()<<qry.lastError();
     while(qry.next()){
         QString tar=qry.value(1).toString();
         QString ac=qry.value(2).toString();
         QString al=qry.value(3).toString();
         QString ver=qry.value(4).toString();
         QString bak=qry.value(5).toString();

         const int row=ui->cariTablo->rowCount();
         ui->cariTablo->insertRow(row);
         ui->cariTablo->setItem(row,Tarih,new QTableWidgetItem(tar));
         ui->cariTablo->setItem(row,Aciklama,new QTableWidgetItem(ac));
         ui->cariTablo->setItem(row,AlinanUcret,new QTableWidgetItem(al));
         ui->cariTablo->setItem(row,VerilenOdeme,new QTableWidgetItem(ver));
         ui->cariTablo->setItem(row,Bakiye,new QTableWidgetItem(bak));
     }
     db.close();
}

void odemeislemleri::tabloTemizle()
{
    int sayi=ui->cariTablo->rowCount();
    for(int i=sayi;i>=0;i--){
        ui->cariTablo->removeRow(i);
    }
}

void odemeislemleri::cariyeEkle()
{
    QString mAdi=ui->mAdCmb->currentText();
    QDate tarih=ui->dateEdit->date();
    QString Acik="ÖDEME";
    double Aucret=ui->alinanUcDsb->value();
    double Verodeme=0;
    double borc=ui->mBorcDsb->value();
    double bakiye=borc-Aucret;
    QSqlDatabase dtb= QSqlDatabase::addDatabase("QSQLITE");
    dtb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//caridatabase.db");
    dtb.open();
    QSqlQuery qry(dtb);
    qry.prepare("INSERT INTO caritablo(m_Adi,tarih,aciklama,alinan_ucret,verilen_odeme,bakiye)"
                "VALUES(:AD,:TAR,:AC,:AU,:VO,:BK)");
    qry.bindValue(":AD",mAdi);
    qry.bindValue(":TAR",tarih);
    qry.bindValue(":AC",Acik);
    qry.bindValue(":AU",Aucret);
    qry.bindValue(":VO",Verodeme);
    qry.bindValue(":BK",bakiye);
    qry.exec();
    qDebug()<<qry.lastError();
    if(!qry.next()){

    }
}

void odemeislemleri::borcGuncelle()
{
    QString Ad=ui->mAdCmb->currentText();
    double borc=ui->doubleSpinBox->value();
    QString borcu=QString::number(borc);
    QSqlDatabase fb=QSqlDatabase::addDatabase("QSQLITE");
    fb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    fb.open();
    QSqlQuery qry(fb);
    qry.exec("UPDATE musteribilgi SET mBorc='"+borcu+"' where mAd='"+Ad+"'");
    qDebug()<<qry.lastError();
    fb.close();
}

void odemeislemleri::on_pushButton_clicked()
{
    double borc=ui->mBorcDsb->value();
    double alinan=ui->alinanUcDsb->value();
    double kalan=borc-alinan;
    ui->doubleSpinBox->setValue(kalan);

}

void odemeislemleri::on_pushButton_5_clicked()
{
    QString ad= ui->mAdCmb->currentText();

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//caridatabase.db");
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT * FROM caritablo WHERE m_Adi='"+ad+"' ");
    tabloTemizle();
    qDebug()<<qry.lastError();
    while(qry.next()){
        QDate tar=qry.value(1).toDate();
        QString tari=tar.toString("dd.MM.yyyy");
        QString ac=qry.value(2).toString();
        QString al=qry.value(3).toString();
        QString ver=qry.value(4).toString();
        QString bak=qry.value(5).toString();

        const int row=ui->cariTablo->rowCount();
        ui->cariTablo->insertRow(row);
        ui->cariTablo->setItem(row,Tarih,new QTableWidgetItem(tari));
        ui->cariTablo->setItem(row,Aciklama,new QTableWidgetItem(ac));
        ui->cariTablo->setItem(row,AlinanUcret,new QTableWidgetItem(al));
        ui->cariTablo->setItem(row,VerilenOdeme,new QTableWidgetItem(ver));
        ui->cariTablo->setItem(row,Bakiye,new QTableWidgetItem(bak));
    }
    db.close();
}

void odemeislemleri::on_pushButton_2_clicked()
{
    if(ui->doubleSpinBox->value()==0.00){
    QMessageBox msg;
    msg.setText("Ödemeyi Hesaplamadınız !");
    msg.exec();
    }
    else
    {
     QMessageBox msgBox;
     msgBox.setText("Ödemeyi Onaylıyormusunuz ?");
     QPushButton *okButton=msgBox.addButton(tr("Onayla"),QMessageBox::ActionRole);
     QPushButton *ipButton=msgBox.addButton(tr("İptal"),QMessageBox::ActionRole);
     msgBox.exec();
     if(msgBox.clickedButton()==okButton){
         cariyeEkle();
         borcGuncelle();
         faturaYazdir();
         ui->doubleSpinBox->setValue(0.00);
         ui->alinanUcDsb->setValue(0.00);
         on_mAdCmb_currentTextChanged(ui->mAdCmb->currentText());
     }
     else if(msgBox.clickedButton()==ipButton){
         msgBox.close();
     }
    }
}

void odemeislemleri::on_pushButton_4_clicked()
{
    cariYazdir();
}
