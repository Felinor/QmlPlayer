#include "modelplayer.h"

#include <QDir>
#include <QDateTime>
#include <QMimeDatabase>
#include <QMimeType>
#include <QDebug>
#include <QTimer>
#include <QObject>

ModelPlayer::ModelPlayer(QObject *parent) : QAbstractListModel (parent)
{
    QDir folderPlayerList(QDir::homePath() + "/Skillet");
    dataModel = folderPlayerList.entryInfoList(QDir::NoDotAndDotDot | QDir::Files );
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,  SLOT(updateCount()));
    timer->start(1000);
}

int ModelPlayer::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return  dataModel.length();
}

QVariant ModelPlayer::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > dataModel.length())
        return QVariant();

    switch (role) {
    case Name:
        return  dataModel[index.row()].fileName();
    case Path:
        return dataModel[index.row()].filePath();
    case DataModified:
        return dataModel[index.row()].lastModified().toString("hh:mm, dd MMMM yyyy");
    case Size:
        return dataModel[index.row()].size();
    case MimeType:
        return dataModel[index.row()].suffix();
    }

    return  QVariant();
}

QHash<int, QByteArray> ModelPlayer::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[Name] = "name";
    roles[Path] = "path";
    roles[DataModified] = "dataModified";
    roles[Size] = "size";
    roles[MimeType] = "mimeType";
    return  roles;
}

void ModelPlayer::updateCount()
{
    count++;
    emit chand();
}

void ModelPlayer::deleter(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    dataModel.removeAt(index);
    endRemoveRows();

    beginInsertRows(QModelIndex(), dataModel.count(), dataModel.count());
    dataModel.append(QFileInfo(QDir::homePath() + "/Skillet/Album/Skillet - Comatose.mp3"));
    endInsertRows();
}

