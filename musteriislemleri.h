#ifndef MUSTERIISLEMLERI_H
#define MUSTERIISLEMLERI_H

#include <QDialog>

namespace Ui {
class musteriislemleri;
}

class musteriislemleri : public QDialog
{
    Q_OBJECT

public:
    explicit musteriislemleri(QWidget *parent = 0);
    ~musteriislemleri();
    void musteriCekme();

private slots:
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();
    void tabloTemizle();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    enum{
        ID,
        MusteriAd,
        MusteriTel,
        MusteriBorc
    };
    Ui::musteriislemleri *ui;
};

#endif // MUSTERIISLEMLERI_H
