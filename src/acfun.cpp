#include "acfun.h"
#include "youget.h"

#include <QWebView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QUrl>

Acfun::Acfun(QWidget *parent) :
    QWidget(parent)
{
    view = new QWebView(parent);
    m_pPushButtonPlay = new QPushButton(tr("Play"));
    m_pHBoxLayout = new QHBoxLayout;
    m_pVBoxLayout = new QVBoxLayout;
    m_pYouGet  = new YouGet;

    m_pHBoxLayout->addWidget(m_pPushButtonPlay);
    m_pHBoxLayout->addStretch();
    m_pVBoxLayout->addWidget(view);
    m_pVBoxLayout->addLayout(m_pHBoxLayout);

    setLayout(m_pVBoxLayout);

    view->load(QUrl("http://www.acfun.tv/"));

    connect(view,SIGNAL(linkClicked(QUrl)),this,SLOT(loadLink(QUrl)));
    connect(m_pPushButtonPlay, SIGNAL(clicked()), SLOT(on_pushButtonPlay_clicked()));
    connect(m_pYouGet, SIGNAL(parsingFinished(QStringList*)), parent, SLOT(onYouGetParsingFinished(QStringList*)));

    view->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
}

void Acfun::loadLink(const QUrl &url)
{
    view->load(url);
}

void Acfun::on_pushButtonPlay_clicked()
{
    m_pYouGet->getRealUrl(view->url().toString());
}
