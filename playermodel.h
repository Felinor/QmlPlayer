//#ifndef PLAYERMODEL_H
//#define PLAYERMODEL_H

////#include <QAbstractListModel>
////#include <QFileInfo>
////#include <QObject>

////class PlayerModel : public QAbstractListModel
////{
////    Q_OBJECT
////public:
////    PlayerModel(QObject* parent = nullptr);


////    enum Roles { // роли модели
////        Name,
////        Path,
////        DataModified,
////        Size,
////        MimeType
////    };

////    int rowCount(const QModelIndex &parent = QModelIndex()) const; // сказать модели сколько у нее элементов
////    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const; // привязать данные модели к ролям
////    QHash<int, QByteArray> roleNames() const; // указать как в qml будут называться роли
////public slots:
////    void updateCount();
////private:
////    QList<QFileInfo> dataModel; //данные модели
////    int count{0};
////};

//#endif // PLAYERMODEL_H
