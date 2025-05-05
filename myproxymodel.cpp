#include "myproxymodel.h"


myproxymodel::myproxymodel(QObject *parent)
    : QSortFilterProxyModel{parent}
{

    setSourceModel(&myitemmodel);
    setFilterRegularExpression(QRegularExpression("suyambu", QRegularExpression::CaseInsensitiveOption));
    setFilterKeyColumn(0);
    qDebug()<<"sort model"<<myitemmodel.columnCount()<<sourceModel()<<filterRegularExpression().pattern()<<filterKeyColumn()<<rowCount();


}

bool myproxymodel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
        QModelIndex index = sourceModel()->index(source_row, filterKeyColumn(), source_parent);
    qDebug()<<"filterAcceptsRow"<<source_row<<source_parent<<index<<sourceModel()->data(index).toString().contains(filterRegularExpression());;
        return sourceModel()->data(index).toString().contains(filterRegularExpression());
}
