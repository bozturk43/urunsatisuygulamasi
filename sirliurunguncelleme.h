#ifndef SIRLIURUNGUNCELLEME_H
#define SIRLIURUNGUNCELLEME_H

#include <QDialog>

namespace Ui {
class sirliurunguncelleme;
}

class sirliurunguncelleme : public QDialog
{
    Q_OBJECT

public:
    explicit sirliurunguncelleme(QWidget *parent = 0);
    ~sirliurunguncelleme();
    void urunCekme();
    void tabloTemizle();

private slots:
    void on_uAraTxt_textChanged(const QString &arg1);

    void on_guncelleBtn_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_silBtn_clicked();

private:
    Ui::sirliurunguncelleme *ui;
    enum{
      ID,
      UrunTuru,
      UrunAdi,
      UrunBirimFiyati
    };
};

#endif // SIRLIURUNGUNCELLEME_H
