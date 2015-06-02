#ifndef STYLEDELEGATE_H
#define STYLEDELEGATE_H

#include <QStyledItemDelegate>

class TableStyleDelegate : public QStyledItemDelegate
{
protected:
   virtual QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const Q_DECL_OVERRIDE;
};

#endif // STYLEDELEGATE_H
