#include "youget.h"

#include <QString>
#include <QProcess>
#include <QByteArray>
#include <QDebug>
#include <QStringList>

YouGet::YouGet(QObject *parent) :
    QObject(parent)
{
}

void YouGet::getRealUrl(QString url)
{
    m_pProcess = new QProcess;
    connect(m_pProcess, SIGNAL(finished(int)), this, SLOT(on_process_finished()));
    m_pProcess->start("you-get -u " + url);
}

void YouGet::on_process_finished()
{
    qint32 i = 0;
    QStringList stringList;
    QByteArray byteArray = m_pProcess->readAllStandardOutput();

    /*while (byteArray.data()[i] != '\0')
    {
        QString string = "";
        while (byteArray.data()[i] != '\n')
        {
            if (byteArray.data()[i] != '\0')
                string.append(byteArray.at(i));
            else
                break;
            i++;
        }
        stringList.append(string);
        if (byteArray.data()[i] == '\0')
            break;
        i++;
    }*/
    QString string(byteArray);
    QStringList strList = string.split('\n');
    qDebug() << strList;
    emit parsingFinished(&strList);

}
