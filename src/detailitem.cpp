#include "detailitem.h"
#include "ui_detailitem.h"
#include "playlist.h"
#include "settings_plugins.h"
#include "webvideo.h"
#include <QDebug>

DetailItem::DetailItem(QString videoStie, QString title, QString type, QString size, QString realUrls, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailItem)
{
    ui->setupUi(this);
    ui->labelVideoSite->setText(videoStie);
    ui->labelTitle->setText(title);
    ui->labelType->setText(type);
    ui->labelSize->setText(size);
    ui->labelRealUrl->setText(tr("Real URLs:") + " " + realUrls);
    //connect(ui->pushButtonPlay, SIGNAL(clicked()), this, SLOT(on_pushButtonPlay_clicked()));
    url = realUrls;
    name = title;
}

DetailItem::~DetailItem()
{
    delete ui;
}

void DetailItem::on_pushButtonPlay_clicked()
{
    playlist->addFileAndPlay(name, url);
    qDebug() << "hhhh";
if (Settings::autoCloseWindow)
    webvideo->close();
}
