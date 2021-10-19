#include "urunturuekleme.h"
#include "ui_urunturuekleme.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include<QDebug>
#include<QMessageBox>

urunturuekleme::urunturuekleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::urunturuekleme)
{
    ui->setupUi(this);
    const QStringList baslik{"ID","Urun Turu"};
    ui->tableWidget->setColumnCount(baslik.size());
    ui->tableWidget->setHorizontalHeaderLabels(baslik);
    urunTuruCekme();
}

urunturuekleme::~urunturuekleme()
{
    delete ui;
}

void urunturuekleme::urunTuruCekme()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT rowid,UTuruAdi FROM urunturleri");
    while(qry.next()){
        QString id=qry.value(0).toString();
        QString ad=qry.value(1).toString();
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,ID,new QTableWidgetItem(id));
        ui->tableWidget->setItem(row,UrunTuru,new QTableWidgetItem(ad));
    }
    db.close();

}

void urunturuekleme::tabloTemizle()
{
    int sayi=ui->tableWidget->rowCount();
    for(int i=sayi;i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
}

void urunturuekleme::on_tableWidget_clicked(const QModelIndex &index)
{
    int row=ui->tableWidget->currentRow();
    QString ad=ui->tableWidget->item(row,UrunTuru)->text();
    ui->lineEdit->setText(ad);
}

void urunturuekleme::on_pushButton_3_clicked()
{
    int row=ui->tableWidget->currentRow();
    QString id=ui->tableWidget->item(row,ID)->text();
    QString uTuru=ui->lineEdit->text();
    QSqlDatabase fb=QSqlDatabase::addDatabase("QSQLITE");
    fb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    fb.open();
    QSqlQuery qry(fb);
    qry.exec("UPDATE urunturleri SET UTuruAdi='"+uTuru+"' where rowid='"+id+"'");
    qDebug()<<qry.lastError();
    fb.close();

    QMessageBox MsgBox;
    MsgBox.setText("Güncellendi");
    MsgBox.exec();
    tabloTemizle();
    urunTuruCekme();
}

void urunturuekleme::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()==true){
        QMessageBox msg;
        msg.setText("Eksiksiz Bilgi Girin");
        msg.exec();
    }

    else{
    QString uTuru=ui->lineEdit->text();
    QSqlDatabase dtb= QSqlDatabase::addDatabase("QSQLITE");
    dtb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    dtb.open();
    QSqlQuery qry(dtb);
    qry.prepare("INSERT INTO urunturleri(UTuruAdi)"
                "VALUES(:UT)");
    qry.bindValue(":UT",uTuru);
    qry.exec();
    qDebug()<<qry.lastError();
    if(!qry.next()){
        QMessageBox MsgBox;
        MsgBox.setText("Eklendi !");
        MsgBox.exec();
    }
    dtb.close();

}
    tabloTemizle();
    urunTuruCekme();
}

void urunturuekleme::on_pushButton_2_clicked()
{
    int row=ui->tableWidget->currentRow();
    QString id=ui->tableWidget->item(row,ID)->text();
    QSqlDatabase fb=QSqlDatabase::addDatabase("QSQLITE");
    fb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    fb.open();
    QSqlQuery qry(fb);
    qry.exec("DELETE FROM urunturleri where rowid='"+id+"'");
    qDebug()<<qry.lastError();
    fb.close();

    QMessageBox MsgBox;
    MsgBox.setText("Silindi");
    MsgBox.exec();
    tabloTemizle();
    urunTuruCekme();

}
