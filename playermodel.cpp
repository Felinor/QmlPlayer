//#include "playermodel.h"

//#include <QDir>
//#include <QDateTime>
//#include <QMimeDatabase>
//#include <QMimeType>
//#include <QDebug>
//#include <QTimer>

//PlayerModel::PlayerModel(QObject *parent) : QAbstractListModel (parent)
//{
//    QDir folderPlayerList(QDir::homePath() + "/Skillet");
//    dataModel = folderPlayerList.entryInfoList(QDir::NoDotAndDotDot | QDir::Files );
//    QTimer timer;
//    connect(&timer, SIGNAL(timeout()), this,  SLOT(updateCount()));
//    timer.start (1000);
//}

//int PlayerModel::rowCount(const QModelIndex &parent) const
//{
//    Q_UNUSED(parent)
//    return  dataModel.length();
//}

//QVariant PlayerModel::data(const QModelIndex &index, int role) const
//{
//    if (index.row() < 0 || index.row() > dataModel.length())
//        return QVariant();

//    switch (role) {
//    case Name:
//        return  dataModel[index.row()].fileName();
//    case Path:
//        return dataModel[index.row()].filePath();
//    case DataModified:
//        return dataModel[index.row()].lastModified().toString("hh:mm, dd MMMM yyyy");
//    case Size:
//        return dataModel[index.row()].size();
//    case MimeType:
//        return dataModel[index.row()].suffix();
//    }

//    return  QVariant();
//}

//QHash<int, QByteArray> PlayerModel::roleNames() const
//{
//    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
//    roles[Name] = "name";
//    roles[Path] = "path";
//    roles[DataModified] = "dataModified";
//    roles[Size] = "size";
//    roles[MimeType] = "mimeType";
//    return  roles;
//}

//void PlayerModel::updateCount()
//{
//    count++;
//    qDebug() << count;
//}
