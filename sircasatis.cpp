#include "sircasatis.h"
#include "ui_sircasatis.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDateEdit>
#include <qtrpt.h>
#include<QDebug>
#include<QMessageBox>

sircasatis::sircasatis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sircasatis)
{
    ui->setupUi(this);
    musteriCekme();
    urunTuruCekme();
    ui->dateEdit->setDate(QDate::currentDate());
    const QStringList baslik{"Urun Adi","Birim Fiyati","Adet","Tutar"};
    ui->tableWidget->setColumnCount(baslik.size());
    ui->tableWidget->setHorizontalHeaderLabels(baslik);
    ui->tableWidget->setColumnWidth(UrunAdi,150);
    ui->tableWidget->setColumnWidth(Tutar,118);
    ui->tableWidget->setColumnWidth(UrunBirimFiyat,108);
    ui->tableWidget->setColumnWidth(UrunAdeti,108);
}

sircasatis::~sircasatis()
{
    delete ui;
}

void sircasatis::musteriCekme()
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

void sircasatis::urunTuruCekme()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    qry.exec("SELECT UTuruAdi FROM urunturleri");
    while(qry.next()){
        QString turAdi=qry.value(0).toString();
        ui->UtLw->addItem(turAdi);
    }
    db.close();
}

void sircasatis::tabloTemizle()
{
    int sayi=ui->tableWidget->rowCount();
    for(int i=sayi;i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
}

void sircasatis::cariyeEkle()
{
    QString mAdi=ui->mAdCmb->currentText();
    QDate tarih=ui->dateEdit->date();
    QString Acik="SIRÇALI SATIŞ";
    double Aucret=0;
    double Verodeme=ui->topTutarDsb->value();
    double borc=ui->mBorcDsb->value();
    double bakiye=Verodeme+borc;
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

void sircasatis::borcGuncelle()
{
    QString Ad=ui->mAdCmb->currentText();
    double borc=ui->mBorcDsb->value();
    double tutar=ui->topTutarDsb->value();
    double topborc=borc+tutar;
    QString topborcstr=QString::number(topborc);
    QSqlDatabase fb=QSqlDatabase::addDatabase("QSQLITE");
    fb.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    fb.open();
    QSqlQuery qry(fb);
    qry.exec("UPDATE musteribilgi SET mBorc='"+topborcstr+"' where mAd='"+Ad+"'");
    qDebug()<<qry.lastError();
    fb.close();
}

void sircasatis::satisYazdir()
{
    QtRPT *report=new QtRPT(this);
    report->loadReport(":/sirsatisrapor.xml");
    report->recordCount.append(ui->tableWidget->rowCount());

    connect(report, &QtRPT::setValue,[&](const int recNo,
            const QString paramName, QVariant &paramValue,
            const int reportPage){
                (void)reportPage;

                if(paramName=="tarih"){
                    QDate dt=ui->dateEdit->date();
                    QString dtv=dt.toString("dd.MM.yyyy");
                    paramValue=dtv;
                }
                if(paramName=="adi"){
                    paramValue=ui->tableWidget->item(recNo,UrunAdi)->text();
                }
                if(paramName=="birimFiyat"){
                    paramValue=ui->tableWidget->item(recNo,UrunBirimFiyat)->text();
                }
                if(paramName=="adet"){
                    paramValue=ui->tableWidget->item(recNo,UrunAdeti)->text();
                }
                if(paramName=="tutar"){
                    paramValue=ui->tableWidget->item(recNo,Tutar)->text();
                }
                if(paramName=="mAd"){
                    paramValue=ui->mAdCmb->currentText();
                }
                if(paramName=="oBorc"){
                    paramValue=ui->mBorcDsb->value();
                }
                if(paramName=="tTutar"){
                    paramValue=ui->topTutarDsb->value();
                }
                if(paramName=="yBorc"){
                    double borc=ui->mBorcDsb->value();
                    double tutar=ui->topTutarDsb->value();
                    double topborc=borc+tutar;

                    paramValue=topborc;
                }
    });
    report->printExec();
}

void sircasatis::on_UtAraTxt_textChanged(const QString &arg1)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    QString Ad=ui->UtAraTxt->text();
    qry.prepare("SELECT UTuruAdi FROM urunturleri where UTuruAdi LIKE ?");
    qDebug()<<QString("%1%%").arg(Ad);
    qry.addBindValue(QString("%1%%").arg(Ad));
    if(qry.exec()){
        ui->UtLw->clear();
    while(qry.next()){
            QString uTAdi=qry.value(0).toString();
            ui->UtLw->addItem(uTAdi);
    }
    }
    db.close();
}

void sircasatis::on_mAdCmb_currentTextChanged(const QString &arg1)
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
}

void sircasatis::on_UtLw_clicked(const QModelIndex &index)
{
    ui->ULw->clear();
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    QString Ad=ui->UtLw->currentItem()->text();
    qry.exec("SELECT UAdi FROM sirliurunler where uTuru='"+Ad+"'");
    while(qry.next()){
        QString uAdi=qry.value(0).toString();
        ui->ULw->addItem(uAdi);
    }
    db.close();
}

void sircasatis::on_ULw_clicked(const QModelIndex &index)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C://Users//reupp//Desktop//Otomasyon//veritabani//database.db");
    db.open();
    QSqlQuery qry(db);
    QString Ad=ui->ULw->currentItem()->text();
    qry.exec("SELECT UTuru,UAdi,UBirimFiyat FROM sirliurunler where UAdi='"+Ad+"'");
    while(qry.next()){
        QString uTuru=qry.value(0).toString();
        QString uAdi=qry.value(1).toString();
        double bFiyat=qry.value(2).toDouble();
        ui->UTBilgiTxt->setText(uTuru);
        ui->UAdBilgiTxt->setText(uAdi);
        ui->BFiyatDsb->setValue(bFiyat);
    }
    db.close();
}

void sircasatis::on_ekleButon_clicked()
{
    if(ui->UAdBilgiTxt->text().isEmpty()==true){
        QMessageBox msg;
        msg.setText("Ürün Secilmedi Kontrol Edin");
        msg.exec();
    }
    else{
    QString ad=ui->UAdBilgiTxt->text();
    int adet=ui->AdetSb->value();
    double bfiyat=ui->BFiyatDsb->value();
    double tutar=adet*bfiyat;
    QString adettablo=QString::number(adet);
    QString bfiyattablo=QString::number(bfiyat);
    QString tutartablo=QString::number(tutar);
    const int row=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,UrunAdi,new QTableWidgetItem(ad));
    ui->tableWidget->setItem(row,UrunBirimFiyat,new QTableWidgetItem(bfiyattablo+" TL"));
    ui->tableWidget->setItem(row,UrunAdeti,new QTableWidgetItem(adettablo));
    ui->tableWidget->setItem(row,Tutar,new QTableWidgetItem(tutartablo));
    ui->tableWidget->setRowHeight(row,25);
    double toplam=ui->topTutarDsb->value();
    double toplamtutar=toplam+tutar;
    ui->topTutarDsb->setValue(toplamtutar);

}
    ui->UTBilgiTxt->clear();
    ui->UAdBilgiTxt->clear();
    ui->BFiyatDsb->setValue(0.00);
    ui->AdetSb->setValue(1);
}

void sircasatis::on_silButon_clicked()
{
    int row=ui->tableWidget->currentRow();
    double tutar=ui->tableWidget->item(row,Tutar)->text().toDouble();
    double toplam=ui->topTutarDsb->value();
    double toplamtutar=toplam-tutar;
    ui->topTutarDsb->setValue(toplamtutar);
    double borc=ui->mBorcDsb->value();
    double toplamborc=borc-tutar;
    ui->mBorcDsb->setValue(toplamborc);
    ui->tableWidget->removeRow(row);

}

void sircasatis::on_TamamButon_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Satışı Onaylıyormusunuz ?");
    QPushButton *okButton=msgBox.addButton(tr("Onayla"),QMessageBox::ActionRole);
    QPushButton *ipButton=msgBox.addButton(tr("İptal"),QMessageBox::ActionRole);
    msgBox.exec();
    if(msgBox.clickedButton()==okButton){
        cariyeEkle();
        borcGuncelle();
        satisYazdir();
        tabloTemizle();
        on_mAdCmb_currentTextChanged(ui->mAdCmb->currentText());
        ui->topTutarDsb->setValue(0.00);
    }
    else if(msgBox.clickedButton()==ipButton){
        msgBox.close();
    }
}
