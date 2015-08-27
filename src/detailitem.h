#ifndef DETAILITEM_H
#define DETAILITEM_H

#include <QWidget>

namespace Ui {
class DetailItem;
}

class DetailItem : public QWidget
{
    Q_OBJECT

public:
    explicit DetailItem(QString videoStie, QString title, QString type, QString size, QString realUrls, QWidget *parent = 0);
    ~DetailItem();

public slots:
    void on_pushButtonPlay_clicked();

private:
    Ui::DetailItem *ui;
    QString url;
    QString name;
};

#endif // DETAILITEM_H
