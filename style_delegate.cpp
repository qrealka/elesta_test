#include "style_delegate.h"

QSize TableStyleDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    if (!(1 & (index.row() + 1)))
        size.setHeight(size.height() * 2);
    return size;
}
