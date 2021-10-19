#ifndef URUNGUNCELLEME_H
#define URUNGUNCELLEME_H

#include <QDialog>

namespace Ui {
class urunguncelleme;
}

class urunguncelleme : public QDialog
{
    Q_OBJECT

public:
    explicit urunguncelleme(QWidget *parent = 0);
    ~urunguncelleme();
    void urunCekme();
    void tabloTemizle();


private slots:
    void on_uAraTxt_textChanged(const QString &arg1);

    void on_guncelleBtn_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_silBtn_clicked();

private:
    enum{
      ID,
      UrunTuru,
      UrunAdi,
      UrunBirimFiyati
    };
    Ui::urunguncelleme *ui;
};

#endif // URUNGUNCELLEME_H
