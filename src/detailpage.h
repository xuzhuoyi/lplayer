#ifndef DETAILPAGE_H
#define DETAILPAGE_H

#include <QWidget>

class QListWidget;
class QGridLayout;

class DetailPage : public QWidget
{
    Q_OBJECT
public:
    explicit DetailPage(QWidget *parent = 0);
    void setsList(QStringList stringList);
    void displayItems();
signals:

public slots:

private:
    QListWidget * m_pListWidget;
    QGridLayout *m_pGridLayout;
    qint32 clipNum;
    QStringList sList;



};

#endif // DETAILPAGE_H
