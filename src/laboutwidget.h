#ifndef LABOUTWIDGET_H
#define LABOUTWIDGET_H

#include <QWidget>

#define LDE_VERSION "2.1"

class QVBoxLayout;
class QLabel;
class QPushButton;
class QTabWidget;
class QGraphicsView;
class QGraphicsScene;
class QHBoxLayout;

class LAboutWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LAboutWidget(QString name, QString version, QString info = "", QWidget *parent = 0);
    explicit LAboutWidget(QString name, QString version, QPixmap *icon, QString info = "", QWidget *parent = 0);
signals:

public slots:

private:
    QVBoxLayout *m_pVBoxLayoutMain;
    QVBoxLayout *m_pVBoxLayoutTitle;
    QHBoxLayout *m_pHBoxLayoutTitle;
    QLabel *m_pLabelName;
    QLabel *m_pLabelVersion;
    QLabel *m_pLabelLDEVersion;
    QTabWidget *m_pTabWidgetContent;
    QLabel *m_pLabelAbout;
    QVBoxLayout *m_pVBoxLayoutAbout;
    QLabel* m_pLabelIcon;

    void __SetUi(QString name, QString version, QString info);
};

#endif // LABOUTWIDGET_H
