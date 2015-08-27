#include "detailpage.h"
#include "detailitem.h"

#include <QListWidget>
#include <QGridLayout>

DetailPage::DetailPage(QWidget *parent) :
    QWidget(parent)
{
    clipNum = 0;
    m_pListWidget = new QListWidget;
    m_pGridLayout = new QGridLayout;

    m_pGridLayout->addWidget(m_pListWidget);

    setLayout(m_pGridLayout);
}

void DetailPage::displayItems()
{
    QStringList input = sList;
    clipNum = (input.count()) / 9;
    for (qint32 i = 0; i < clipNum; i++)
    {
        QListWidgetItem *p = new QListWidgetItem(m_pListWidget);
        p->setSizeHint(QSize(320,300));
        QString v, t, ty, s, r;
        v = sList.at(8 * i + 0);
        t = sList.at(8 * i + 1);
        ty = sList.at(8 * i + 2);
        s = sList.at(8 * i + 3);
        r = sList.at(8 * i + 6);
        DetailItem *item = new DetailItem(v, t, ty, s, r);
        m_pListWidget->addItem(p);
        m_pListWidget->setItemWidget(p,item);
    }
}

void DetailPage::setsList(QStringList stringList)
{
    sList = stringList;
}
