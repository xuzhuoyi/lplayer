#include "youget.h"
#include "acfun.h"

#include <QString>
#include <QProcess>
#include <QByteArray>
#include <QDebug>
#include <QStringList>
#include <QMessageBox>

YouGet::YouGet(QObject *parent) :
    QObject(parent)
{
}

void YouGet::getRealUrl(QString url)
{
    m_pProcess = new QProcess;
    connect(m_pProcess, SIGNAL(finished(int)), this, SLOT(on_process_finished()));
    connect(m_pProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(on_process_failed()));
    m_pProcess->start("python3 /usr/share/lplayer/you-get/you-get -u " + url);
    acfun->setStausText(tr("Parsing..."));
}

void YouGet::on_process_finished()
{
    acfun->setStausText(tr("Parsed"));
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
    if (strList.at(0) == "")
    {
        QMessageBox::warning(NULL, tr("Warning"), tr("Please click the play button on the player page."));
        return;
    }

    if (strList.at(0).contains("Youku"))
    {
        QMessageBox::warning(NULL, tr("Warning"), tr("This version does not support Youku source analysis, the function will be realized in the next version."));
        return;
    }

    emit parsingFinished(&strList);

}

void YouGet::on_process_failed()
{
    QMessageBox::warning(NULL, tr("Warning"), tr("Parsed unsuccessfully, please retry."));
}
