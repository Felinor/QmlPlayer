#ifndef MODELPLAYER_H
#define MODELPLAYER_H


#include <QAbstractListModel>
#include <QFileInfo>
#include <QObject>

class ModelPlayer : public QAbstractListModel
{
    Q_OBJECT
public:
    ModelPlayer(QObject* parent = nullptr);

    Q_PROPERTY(int count MEMBER count NOTIFY chand)

    enum Roles { // роли модели
        Name,
        Path,
        DataModified,
        Size,
        MimeType
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const; // сказать модели сколько у нее элементов
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const; // привязать данные модели к ролям
    QHash<int, QByteArray> roleNames() const; // указать как в qml будут называться роли

signals:
    void chand();

public slots:
    void updateCount();
    void deleter(int index);
private:
    QList<QFileInfo> dataModel; //данные модели
    int count{0};
};

#endif // MODELPLAYER_H
