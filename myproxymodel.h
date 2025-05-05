#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H

#include <QSortFilterProxyModel>

#include"myitemmodel.h"

class myproxymodel : public QSortFilterProxyModel
{
public:
    explicit myproxymodel(QObject *parent = nullptr);
private:
    MyItemModel myitemmodel;

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
};

// inline bool myproxymodel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
// {
//     QModelIndex index = sourceModel()->index(source_row, filterKeyColumn(), source_parent);
//     return sourceModel()->data(index).toString().contains(filterRegularExpression());
// }

#endif // MYPROXYMODEL_H
