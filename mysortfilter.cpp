#include "mysortfilter.h"
#include <QDirModel>
#include <QtDebug>

mySortFilter::mySortFilter()
{

}

mySortFilter::~mySortFilter()
{

}

bool mySortFilter::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if(!sourceModel()) return false;

    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);
    QDirModel *model = static_cast<QDirModel*>(sourceModel());
    QString str = model->fileName(index);

    if (model->fileInfo(index).isDir()) return true;

    else if (model->fileInfo(index).isFile() && (str.endsWith(".cpp") || (str.endsWith(".h")))) return true;

    return false;

}
