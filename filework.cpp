#include "filework.h"
#include <QFileDevice>
#include <QDir>

FileWork::FileWork(QObject *parent) : QObject (parent)
{
     QString path = QDir::homePath();


     player = new QMediaPlayer;
     m_playlist = new QMediaPlaylist(player);  // Инициализируем плейлист
     player->setPlaylist(m_playlist);           // Устанавливаем плейлист в плеер
     m_playlist->setPlaybackMode(QMediaPlaylist::Loop);  // Устанавливаем циклический режим проигрывания плейлиста

     connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));

    m_playlist ->previous();
    m_playlist->next();

}

void FileWork::listen(const QString & path)
{
    player->setMedia(QUrl::fromLocalFile(path));
    player->setVolume(50);
    player->play();
    m_playlist ->previous();
    m_playlist->next();

}

void FileWork::previous()
{
    m_playlist->previous();
}

void FileWork::next()
{
    m_playlist->next();
}

void FileWork::stop()
{
    player->stop();
}

void FileWork::pause()
{
    player->pause();
}


void FileWork::positionChanged(qint64 s)
{
   qDebug() <<  static_cast<int>(s);
}
