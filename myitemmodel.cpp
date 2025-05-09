#include "myitemmodel.h"
#include<QString>

MyItemModel::MyItemModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    modeldatalistl <<"Apple" <<
        "Banana" <<
        "Orange" <<
        "Mango" <<
        "Dragon Fruit" <<
        "Amla";

    qDebug()<<modeldatalistl;
}

QModelIndex MyItemModel::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
    // if (!hasIndex(row, column, parent))
    //     return QModelIndex();
    return createIndex(row, column);
}

QModelIndex MyItemModel::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
    Q_UNUSED(index);
    return QModelIndex();
}

int MyItemModel::rowCount(const QModelIndex &parent) const
{
    // if (!parent.isValid())
    //     return 0;
    qDebug()<<modeldatalistl.size()<<modeldatalistl.at(0);
    return modeldatalistl.size();

    // FIXME: Implement me!
}

int MyItemModel::columnCount(const QModelIndex &parent) const
{
    // if (!parent.isValid())
    //     return 0;

    // FIXME: Implement me!
    return 1;
}

QVariant MyItemModel::data(const QModelIndex &index, int role) const
{
    // if (!index.isValid())
    //     return QVariant();
    if(role == NameRole){
        return modeldatalistl.at(index.row());
    }
    // switch (role) {
    // case NameRole:{
    //     return modeldatalistl.at(index.row());
    //     break;
    // }
    // default:{
    //     return QVariant();
    //     break;
    // }
    // }
    return QVariant();
}

QString MyItemModel::myname()
{
    return "suyambu";
}

QHash<int, QByteArray> MyItemModel::roleNames() const
{
    QHash<int, QByteArray> rolehash;
    rolehash[NameRole] = "modelvalue";
    return rolehash;
}
