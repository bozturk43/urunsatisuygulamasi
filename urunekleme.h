#ifndef URUNEKLEME_H
#define URUNEKLEME_H

#include <QDialog>

namespace Ui {
class urunekleme;
}

class urunekleme : public QDialog
{
    Q_OBJECT

public:
    explicit urunekleme(QWidget *parent = 0);
    ~urunekleme();
    void urunTuruCekme();
    void urunCekme();
    void tabloTemizle();


private slots:
    void on_UTLw_clicked(const QModelIndex &index);

    void on_UTAratxt_textChanged(const QString &arg1);

    void on_UAraTxt_textChanged(const QString &arg1);

    void on_EkleBtn_clicked();

    void on_temizBtn_clicked();

private:
    enum{
      UrunTuru,
      UrunAdi,
      UrunBirimFiyati
    };
    Ui::urunekleme *ui;
};

#endif // URUNEKLEME_H
