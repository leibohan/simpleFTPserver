#ifndef MYSORTFILTER_H
#define MYSORTFILTER_H

#include <QObject>
#include <QSortFilterProxyModel>

class mySortFilter : public QSortFilterProxyModel
{
public:
    mySortFilter();
    ~mySortFilter();

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

};

#endif // MYSORTFILTER_H
