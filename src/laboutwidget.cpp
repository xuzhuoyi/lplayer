#include "laboutwidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QDebug>

LAboutWidget::LAboutWidget(QString name, QString version, QString info, QWidget *parent) : QWidget(parent)
{
    __SetUi(name, version, info);
    m_pTabWidgetContent->addTab(m_pLabelAbout, tr("关于"));
    m_pVBoxLayoutMain->addLayout(m_pVBoxLayoutTitle);
    m_pVBoxLayoutMain->addWidget(m_pTabWidgetContent);
    setLayout(m_pVBoxLayoutMain);
}

LAboutWidget::LAboutWidget(QString name, QString version, QPixmap *icon, QString info, QWidget *parent) : QWidget(parent)
{
    __SetUi(name, version, info);
    m_pTabWidgetContent->addTab(m_pLabelAbout, tr("关于"));
    m_pLabelIcon = new QLabel;
    m_pLabelIcon->setPixmap(*icon);
    m_pHBoxLayoutTitle = new QHBoxLayout;
    m_pHBoxLayoutTitle->addWidget(m_pLabelIcon);
    m_pHBoxLayoutTitle->addLayout(m_pVBoxLayoutTitle);
    m_pVBoxLayoutMain->addLayout(m_pHBoxLayoutTitle);
    m_pVBoxLayoutMain->addWidget(m_pTabWidgetContent);
    setLayout(m_pVBoxLayoutMain);

}

void LAboutWidget::__SetUi(QString name, QString version, QString info)
{
    m_pVBoxLayoutMain = new QVBoxLayout;
    m_pVBoxLayoutTitle = new QVBoxLayout;
    m_pLabelName = new QLabel(name);
    QFont *font = new QFont;
    font->setPointSize(14);
    m_pLabelName->setFont(*font);
    m_pLabelVersion = new QLabel(tr("版本") + " " + version);
    font = new QFont;
    font->setBold(true);
    m_pLabelVersion->setFont(*font);
    m_pLabelLDEVersion = new QLabel(tr("LDE 版本") + " " + LDE_VERSION);
    m_pVBoxLayoutTitle->addStretch();
    m_pVBoxLayoutTitle->addWidget(m_pLabelName);
    m_pVBoxLayoutTitle->addWidget(m_pLabelVersion);
    m_pVBoxLayoutTitle->addWidget(m_pLabelLDEVersion);
    m_pVBoxLayoutTitle->addStretch();
    m_pTabWidgetContent = new QTabWidget;

    m_pLabelAbout = new QLabel(tr("Compiled in") + " " + QString(QLatin1String(__DATE__)) + " " + QString(QLatin1String(__TIME__)) + info);
    m_pLabelAbout->setAlignment(Qt::AlignCenter);
    resize(250, 350);
}

