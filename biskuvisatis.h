#ifndef BISKUVISATIS_H
#define BISKUVISATIS_H

#include <QMainWindow>

namespace Ui {
class BiskuviSatis;
}

class BiskuviSatis : public QMainWindow
{
    Q_OBJECT

public:
    explicit BiskuviSatis(QWidget *parent = 0);
    ~BiskuviSatis();
    void musteriCekme();
    void urunTuruCekme();
    void cariyeEkle();
    void borcGuncelle();
    void satisYazdir();
    void tabloTemizle();
    void Cekme();

private slots:
    void on_mAdCmb_currentTextChanged(const QString &arg1);

    void on_UtAraTxt_textEdited(const QString &arg1);

    void on_UtAraTxt_textChanged(const QString &arg1);

    void on_UtLw_clicked(const QModelIndex &index);

    void on_ULw_clicked(const QModelIndex &index);

    void on_ekleButon_clicked();

    void on_silButon_clicked();

    void on_actionBisk_vi_Sati_triggered();

    void on_action_r_n_Ekleme_triggered();

    void on_action_r_n_G_ncelleme_triggered();

    void on_action_r_n_Ekleme_S_r_al_triggered();

    void on_action_r_n_Ekleme_S_al_triggered();

    void on_TamamButon_clicked();

    void on_action_deme_lemleri_triggered();

    void on_action_r_n_T_r_Ekleme_triggered();

    void on_actionM_teri_Ekleme_triggered();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    enum{
      UrunAdi,
      UrunBirimFiyat,
      UrunAdeti,
      Tutar
    };
    Ui::BiskuviSatis *ui;
};

#endif // BISKUVISATIS_H
