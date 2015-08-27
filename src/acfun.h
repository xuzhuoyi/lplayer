#ifndef ACFUN_H
#define ACFUN_H

#include <QWidget>

class QWebView;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QUrl;
class YouGet;

class Acfun : public QWidget
{
    Q_OBJECT
public:
    explicit Acfun(QWidget *parent = 0);

signals:

public slots:
    void loadLink(const QUrl &url);
    void on_pushButtonPlay_clicked();

private:
    QWebView *view;
    QPushButton *m_pPushButtonPlay;
    QHBoxLayout *m_pHBoxLayout;
    QVBoxLayout *m_pVBoxLayout;

    YouGet *m_pYouGet;

};

#endif // ACFUN_H
