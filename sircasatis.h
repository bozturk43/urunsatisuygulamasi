#ifndef SIRCASATIS_H
#define SIRCASATIS_H

#include <QDialog>

namespace Ui {
class sircasatis;
}

class sircasatis : public QDialog
{
    Q_OBJECT

public:
    explicit sircasatis(QWidget *parent = 0);
    ~sircasatis();
    void musteriCekme();
    void urunTuruCekme();
    void tabloTemizle();
    void cariyeEkle();
    void borcGuncelle();
    void satisYazdir();



private slots:
    void on_UtAraTxt_textChanged(const QString &arg1);

    void on_mAdCmb_currentTextChanged(const QString &arg1);

    void on_UtLw_clicked(const QModelIndex &index);

    void on_ULw_clicked(const QModelIndex &index);

    void on_ekleButon_clicked();

    void on_silButon_clicked();

    void on_TamamButon_clicked();

private:
    enum{
      UrunAdi,
      UrunBirimFiyat,
      UrunAdeti,
      Tutar
    };
    Ui::sircasatis *ui;
};

#endif // SIRCASATIS_H
