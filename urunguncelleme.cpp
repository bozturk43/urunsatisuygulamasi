#include "urunguncelleme.h"
#include "ui_urunguncelleme.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include <QDateEdit>
#include<QDebug>
#include<QMessageBox>


urunguncelleme::urunguncelleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::urunguncelleme)
{
    ui->setupUi(this);
    const QStringList baslik{"ID","Urun Turu","Urun Adi","Birim Fiyati"};
    ui->tableWidget->setColumnCount(baslik.size());
    ui->tableWidget->setHorizontalHeaderLabels(baslik);
    ui->tableWidget->setColumnWidth(ID,30);
    ui->tableWidget->setColumnWidth(UrunTuru,100);
    ui->tableWidget->setColumnWidth(UrunAdi,172);
    ui->tableWidget->setColumnWidth(UrunBirimFiyati,120);
    urunCekme();
}

urunguncelleme::~urunguncelleme()
{
    delete ui;
}

void urunguncelleme::urunCekme()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT rowid,UTuru,UAdi,UBirimFiyat FROM urunler");
    while(qry.next()){
        QString id=qry.value(0).toString();
        QString turAdi=qry.value(1).toString();
        QString urunAdi=qry.value(2).toString();
        QString uBirimFiyat=qry.value(3).toString();
        const int row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,ID,new QTableWidgetItem(id));
        ui->tableWidget->setItem(row,UrunTuru,new QTableWidgetItem(turAdi));
        ui->tableWidget->setItem(row,UrunAdi,new QTableWidgetItem(urunAdi));
        ui->tableWidget->setItem(row,UrunBirimFiyati,new QTableWidgetItem(uBirimFiyat));
        ui->tableWidget->setRowHeight(row,25);

    }
    db.close();
}

void urunguncelleme::tabloTemizle()
{
    int sayi=ui->tableWidget->rowCount();
    for(int i=sayi;i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
}

void urunguncelleme::on_uAraTxt_textChanged(const QString &arg1)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    QString Ad=ui->uAraTxt->text();
    qry.prepare("SELECT rowid,UTuru,UAdi,UBirimFiyat FROM urunler where UAdi LIKE ?");
    qDebug()<<QString("%1%%").arg(Ad);
    qry.addBindValue(QString("%1%%").arg(Ad));
    if(qry.exec()){
            tabloTemizle();
    while(qry.next()){
        QString id=qry.value(0).toString();
        QString turAdi=qry.value(1).toString();
        QString urunAdi=qry.value(2).toString();
        QString uBirimFiyat=qry.value(3).toString();
        const int row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,ID,new QTableWidgetItem(id));
        ui->tableWidget->setItem(row,UrunTuru,new QTableWidgetItem(turAdi));
        ui->tableWidget->setItem(row,UrunAdi,new QTableWidgetItem(urunAdi));
        ui->tableWidget->setItem(row,UrunBirimFiyati,new QTableWidgetItem(uBirimFiyat));
        ui->tableWidget->setRowHeight(row,25);

    }
    }
    db.close();
}

void urunguncelleme::on_guncelleBtn_clicked()
{

        int row=ui->tableWidget->currentRow();
        QString id=ui->tableWidget->item(row,ID)->text();
        QString uTuru=ui->UTtxt->text();
        QString uAd=ui->UAdtxt->text();
        double bFiyat=ui->bFiyatdsb->value();
        QString fyt=QString::number(bFiyat);
        QSqlDatabase fb=QSqlDatabase::addDatabase("QSQLITE");
        fb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
        fb.open();
        QSqlQuery qry(fb);
        qry.exec("UPDATE urunler SET UTuru='"+uTuru+"',UAdi='"+uAd+"',UBirimFiyat='"+fyt+"' where rowid='"+id+"'");
        qDebug()<<qry.lastError();
        fb.close();

        QMessageBox MsgBox;
        MsgBox.setText("Güncellendi");
        MsgBox.exec();
        tabloTemizle();
        urunCekme();



}

void urunguncelleme::on_tableWidget_clicked(const QModelIndex &index)
{
    int row=ui->tableWidget->currentRow();
   QString tur=ui->tableWidget->item(row,UrunTuru)->text();
   QString ad= ui->tableWidget->item(row,UrunAdi)->text();
   double fyt=ui->tableWidget->item(row,UrunBirimFiyati)->text().toDouble();
   ui->UTtxt->setText(tur);
   ui->UAdtxt->setText(ad);
   ui->bFiyatdsb->setValue(fyt);

}

void urunguncelleme::on_silBtn_clicked()
{
    int row=ui->tableWidget->currentRow();
    QString id=ui->tableWidget->item(row,ID)->text();
    QSqlDatabase fb=QSqlDatabase::addDatabase("QSQLITE");
    fb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    fb.open();
    QSqlQuery qry(fb);
    qry.exec("DELETE FROM urunler where rowid='"+id+"'");
    qDebug()<<qry.lastError();
    fb.close();

    QMessageBox MsgBox;
    MsgBox.setText("Silindi");
    MsgBox.exec();
    tabloTemizle();
    urunCekme();
    ui->UAdtxt->clear();
    ui->UTtxt->clear();
    ui->bFiyatdsb->setValue(0.00);

}
