#ifndef SIRLIURUNEKLEME_H
#define SIRLIURUNEKLEME_H

#include <QDialog>

namespace Ui {
class sirliurunekleme;
}

class sirliurunekleme : public QDialog
{
    Q_OBJECT

public:
    explicit sirliurunekleme(QWidget *parent = 0);
    ~sirliurunekleme();
    void urunTuruCekme();
    void urunCekme();
    void tabloTemizle();

private slots:
    void on_UTAratxt_textChanged(const QString &arg1);

    void on_UAraTxt_textChanged(const QString &arg1);

    void on_EkleBtn_clicked();

    void on_UTLw_clicked(const QModelIndex &index);

    void on_temizBtn_clicked();

private:
    enum{
      UrunTuru,
      UrunAdi,
      UrunBirimFiyati
    };
    Ui::sirliurunekleme *ui;
};

#endif // SIRLIURUNEKLEME_H
