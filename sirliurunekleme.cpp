#include "sirliurunekleme.h"
#include "ui_sirliurunekleme.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include <QDateEdit>
#include<QDebug>
#include<QMessageBox>

sirliurunekleme::sirliurunekleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sirliurunekleme)
{
    ui->setupUi(this);
    const QStringList baslik{"Urun Turu","Urun Adi","Birim Fiyati"};
    ui->tableWidget->setColumnCount(baslik.size());
    ui->tableWidget->setHorizontalHeaderLabels(baslik);
    ui->tableWidget->setColumnWidth(UrunTuru,172);
    ui->tableWidget->setColumnWidth(UrunAdi,172);
    ui->tableWidget->setColumnWidth(UrunBirimFiyati,169);
    urunCekme();
    urunTuruCekme();
}

sirliurunekleme::~sirliurunekleme()
{
    delete ui;
}

void sirliurunekleme::urunTuruCekme()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT UTuruAdi FROM urunturleri");
    while(qry.next()){
        QString turAdi=qry.value(0).toString();
        ui->UTLw->addItem(turAdi);
    }
    db.close();
}

void sirliurunekleme::urunCekme()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT UTuru,UAdi,UBirimFiyat FROM sirliurunler");
    while(qry.next()){
        QString turAdi=qry.value(0).toString();
        QString urunAdi=qry.value(1).toString();
        QString uBirimFiyat=qry.value(2).toString();
        const int row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,UrunTuru,new QTableWidgetItem(turAdi));
        ui->tableWidget->setItem(row,UrunAdi,new QTableWidgetItem(urunAdi));
        ui->tableWidget->setItem(row,UrunBirimFiyati,new QTableWidgetItem(uBirimFiyat));
        ui->tableWidget->setRowHeight(row,25);

    }
    db.close();
}

void sirliurunekleme::tabloTemizle()
{
    int sayi=ui->tableWidget->rowCount();
    for(int i=sayi;i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
}

void sirliurunekleme::on_UTAratxt_textChanged(const QString &arg1)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    QString Ad=ui->UTAratxt->text();
    qry.prepare("SELECT UTuruAdi FROM urunturleri where UTuruAdi LIKE ?");
    qDebug()<<QString("%1%%").arg(Ad);
    qry.addBindValue(QString("%1%%").arg(Ad));
    if(qry.exec()){
        ui->UTLw->clear();
    while(qry.next()){
            QString uTAdi=qry.value(0).toString();
            ui->UTLw->addItem(uTAdi);
    }
    }
    db.close();
}

void sirliurunekleme::on_UAraTxt_textChanged(const QString &arg1)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    QString Ad=ui->UAraTxt->text();
    qry.prepare("SELECT UTuru,UAdi,UBirimFiyat FROM sirliurunler where UAdi LIKE ?");
    qDebug()<<QString("%1%%").arg(Ad);
    qry.addBindValue(QString("%1%%").arg(Ad));
    if(qry.exec()){
            tabloTemizle();
    while(qry.next()){
        QString turAdi=qry.value(0).toString();
        QString urunAdi=qry.value(1).toString();
        QString uBirimFiyat=qry.value(2).toString();
        const int row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,UrunTuru,new QTableWidgetItem(turAdi));
        ui->tableWidget->setItem(row,UrunAdi,new QTableWidgetItem(urunAdi));
        ui->tableWidget->setItem(row,UrunBirimFiyati,new QTableWidgetItem(uBirimFiyat));
        ui->tableWidget->setRowHeight(row,25);

    }
    }
    db.close();
}

void sirliurunekleme::on_EkleBtn_clicked()
{
    if(ui->UTtxt->text().isEmpty()==true){
        QMessageBox msg;
        msg.setText("Eksiksiz Bilgi Girin");
        msg.exec();
    }
   else if(ui->UAditxt->text().isEmpty()==true){
        QMessageBox msg;
        msg.setText("Eksiksiz Bilgi Girin");
        msg.exec();
    }
    else{
    QString uTuru=ui->UTtxt->text();
    QString uAdi=ui->UAditxt->text();
    double uBf=ui->BFiyatDsb->value();
    QSqlDatabase dtb= QSqlDatabase::addDatabase("QSQLITE");
    dtb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    dtb.open();
    QSqlQuery qry(dtb);
    qry.prepare("INSERT INTO sirliurunler(UTuru,UAdi,UBirimFiyat)"
                "VALUES(:UT,:UA,:BF)");
    qry.bindValue(":UT",uTuru);
    qry.bindValue(":UA",uAdi);
    qry.bindValue(":BF",uBf);
    qry.exec();
    qDebug()<<qry.lastError();
    if(!qry.next()){
        QMessageBox MsgBox;
        MsgBox.setText("İslem Tamamlandı");
        MsgBox.exec();
    }
    dtb.close();
    tabloTemizle();
    urunCekme();
    }
}

void sirliurunekleme::on_UTLw_clicked(const QModelIndex &index)
{
    QString tur=ui->UTLw->currentItem()->text();
    ui->UTtxt->setText(tur);
}

void sirliurunekleme::on_temizBtn_clicked()
{
    ui->UAditxt->clear();
    ui->UTtxt->clear();
    ui->BFiyatDsb->setValue(0.00);
}
