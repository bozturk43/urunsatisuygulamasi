#ifndef ODEMEISLEMLERI_H
#define ODEMEISLEMLERI_H

#include <QDialog>

namespace Ui {
class odemeislemleri;
}

class odemeislemleri : public QDialog
{
    Q_OBJECT

public:
    explicit odemeislemleri(QWidget *parent = 0);
    ~odemeislemleri();
    void musteriCekme();
    void cariCekme();
    void faturaYazdir();
    void cariYazdir();

private slots:
    void on_mAdCmb_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();
    void tabloTemizle();
    void cariyeEkle();
    void borcGuncelle();
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_4_clicked();

private:
    enum{
        Tarih,
        Aciklama,
        AlinanUcret,
        VerilenOdeme,
        Bakiye
    };
    Ui::odemeislemleri *ui;
};

#endif // ODEMEISLEMLERI_H
