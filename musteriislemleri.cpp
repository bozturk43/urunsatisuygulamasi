#include "musteriislemleri.h"
#include "ui_musteriislemleri.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QtSql/QSqlError>
#include<QMessageBox>
#include<QDebug>

musteriislemleri::musteriislemleri(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::musteriislemleri)
{
    ui->setupUi(this);
    const QStringList baslik{"ID","Adi","Telefonu","Borcu"};
    ui->tableWidget->setColumnCount(baslik.size());
    ui->tableWidget->setHorizontalHeaderLabels(baslik);
    musteriCekme();
}

musteriislemleri::~musteriislemleri()
{
    delete ui;
}

void musteriislemleri::musteriCekme()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT rowid,mAd,mTel,mBorc FROM musteribilgi");
    while(qry.next()){
        QString Id=qry.value(0).toString();
        QString mAdi=qry.value(1).toString();
        QString mTeli=qry.value(2).toString();
        QString mBorcu=qry.value(3).toString();
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,ID, new QTableWidgetItem(Id));
        ui->tableWidget->setItem(row,MusteriAd, new QTableWidgetItem(mAdi));
        ui->tableWidget->setItem(row,MusteriTel, new QTableWidgetItem(mTeli));
        ui->tableWidget->setItem(row,MusteriBorc, new QTableWidgetItem(mBorcu));

    }
    db.close();
}

void musteriislemleri::on_tableWidget_clicked(const QModelIndex &index)
{
    int row=ui->tableWidget->currentRow();
    QString id=ui->tableWidget->item(row,ID)->text();
    QString ad=ui->tableWidget->item(row,MusteriAd)->text();
    QString tel=ui->tableWidget->item(row,MusteriTel)->text();
    double borc=ui->tableWidget->item(row,MusteriBorc)->text().toDouble();
    ui->lineEdit->setText(ad);
    ui->lineEdit_2->setText(tel);
    ui->doubleSpinBox->setValue(borc);
}

void musteriislemleri::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()==true){
        QMessageBox msg;
        msg.setText("Eksiksiz Bilgi Girin");
        msg.exec();
    }
   else if(ui->lineEdit_2->text().isEmpty()==true){
        QMessageBox msg;
        msg.setText("Eksiksiz Bilgi Girin");
        msg.exec();
    }
    else{
    QString mAd=ui->lineEdit->text();
    QString mTek=ui->lineEdit_2->text();
    double mBorc=ui->doubleSpinBox->value();
    QSqlDatabase dtb= QSqlDatabase::addDatabase("QSQLITE");
    dtb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    dtb.open();
    QSqlQuery qry(dtb);
    qry.prepare("INSERT INTO musteribilgi(mAd,mTel,mBorc)"
                "VALUES(:AD,:TL,:BR)");
    qry.bindValue(":AD",mAd);
    qry.bindValue(":TL",mTek);
    qry.bindValue(":BR",mBorc);
    qry.exec();
    qDebug()<<qry.lastError();
    if(!qry.next()){
        QMessageBox MsgBox;
        MsgBox.setText("İslem Tamamlandı");
        MsgBox.exec();
    }
    dtb.close();
    tabloTemizle();
    musteriCekme();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->doubleSpinBox->setValue(0.00);
    }
}

void musteriislemleri::tabloTemizle()
{
    int sayi=ui->tableWidget->rowCount();
    for(int i=sayi;i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
}

void musteriislemleri::on_pushButton_2_clicked()
{
    int row=ui->tableWidget->currentRow();
    QString id=ui->tableWidget->item(row,ID)->text();
    QSqlDatabase fb=QSqlDatabase::addDatabase("QSQLITE");
    fb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    fb.open();
    QSqlQuery qry(fb);
    qry.exec("DELETE FROM musteribilgi where rowid='"+id+"'");
    qDebug()<<qry.lastError();
    fb.close();

    QMessageBox MsgBox;
    MsgBox.setText("Silindi");
    MsgBox.exec();
    tabloTemizle();
    musteriCekme();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->doubleSpinBox->setValue(0.00);
}

void musteriislemleri::on_pushButton_3_clicked()
{
    if(ui->lineEdit->text().isEmpty()==true){
        QMessageBox msg;
        msg.setText("Müsteri Secmediniz !");
        msg.exec();
    }
   else if(ui->lineEdit_2->text().isEmpty()==true){
        QMessageBox msg;
        msg.setText("Müsteri Secmediniz !");
        msg.exec();
    }
    else{
    int row=ui->tableWidget->currentRow();
    QString id=ui->tableWidget->item(row,ID)->text();
    QString mAdi=ui->lineEdit->text();
    QString mTel=ui->lineEdit_2->text();
    double mBorc=ui->doubleSpinBox->value();
    QString fyt=QString::number(mBorc);
    QSqlDatabase fb=QSqlDatabase::addDatabase("QSQLITE");
    fb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    fb.open();
    QSqlQuery qry(fb);
    qry.exec("UPDATE musteribilgi SET mAd='"+mAdi+"',mTel='"+mTel+"',mBorc='"+fyt+"' where rowid='"+id+"'");
    qDebug()<<qry.lastError();
    fb.close();

    QMessageBox MsgBox;
    MsgBox.setText("Güncellendi");
    MsgBox.exec();
    tabloTemizle();
    musteriCekme();
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->doubleSpinBox->setValue(0.00);
}
