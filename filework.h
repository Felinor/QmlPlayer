#ifndef FILEWORK_H
#define FILEWORK_H

#include <QObject>
#include <sndfile.h>
#include <QAudioOutput>
#include <QFile>
#include <QDir>
#include <QAudio>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaObject>
#include <QUrl>
#include <QMediaPlaylist>


class FileWork : public QObject
{
    Q_OBJECT
public:


    FileWork(QObject * parent = nullptr);

    Q_INVOKABLE void listen(const QString & path);

    Q_INVOKABLE void stop();

    Q_INVOKABLE void pause();

    Q_INVOKABLE void previous();

    Q_INVOKABLE void next();


public slots:
    void positionChanged(qint64 s);

private:
    QMediaPlayer * player;
    QMediaPlaylist *m_playlist;
};

#endif // FILEWORK_H
