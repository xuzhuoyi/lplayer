#ifndef YOUGET_H
#define YOUGET_H

#include <QObject>

class QString;
class QProcess;
class QStringList;

class YouGet : public QObject
{
    Q_OBJECT
public:
    explicit YouGet(QObject *parent = 0);
    void getRealUrl(QString url);
public slots:
    void on_process_finished();
    void on_process_failed();
signals:
    void parsingFinished(QStringList*);
private:
    QProcess *m_pProcess;
};

#endif // YOUGET_H
