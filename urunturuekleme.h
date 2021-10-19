#ifndef URUNTURUEKLEME_H
#define URUNTURUEKLEME_H

#include <QDialog>

namespace Ui {
class urunturuekleme;
}

class urunturuekleme : public QDialog
{
    Q_OBJECT

public:
    explicit urunturuekleme(QWidget *parent = 0);
    ~urunturuekleme();
    void urunTuruCekme();
    void tabloTemizle();

private slots:
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    enum{
        ID,
        UrunTuru
    };
    Ui::urunturuekleme *ui;
};

#endif // URUNTURUEKLEME_H
