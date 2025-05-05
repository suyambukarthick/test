#ifndef MYITEMMODEL_H
#define MYITEMMODEL_H

#include <QAbstractItemModel>

class MyItemModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    enum Roles{
        NameRole = Qt::UserRole + 1
    };
    explicit MyItemModel(QObject *parent = nullptr);

    // Basic functionality:
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE QString myname();

private:
    QList<QString> modeldatalistl;

    // QAbstractItemModel interface
protected:
     QHash<int, QByteArray> roleNames() const override;
};

#endif // MYITEMMODEL_H
