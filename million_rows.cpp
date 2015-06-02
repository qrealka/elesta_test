#include "million_rows.h"

MillionRows::MillionRows(QObject *parent)
    : QAbstractItemModel(parent)
    , m_data(1)
{
}

QModelIndex MillionRows::parent(const QModelIndex& index) const
{
    Q_UNUSED(index);

    return m_emptyIndex;
}

QModelIndex MillionRows::index(int row, int column, const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return column == 0 && row >= 0 && row < RowCount
            ? QAbstractItemModel::createIndex(row, column, Q_NULLPTR)
            : m_emptyIndex;
}

int MillionRows::rowCount(const QModelIndex & parent) const
{
   Q_UNUSED(parent);
   return RowCount;
}

int MillionRows::columnCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return 1;
}

QVariant MillionRows::data(const QModelIndex &index, int role) const
{
    /*
     * DON'T use Qt::BackgroundRole & Qt::SizeHintRole.
     * Iti is only DATA model not ViewModel
     */
    if (role == Qt::DisplayRole)
    {
        m_data.setValue(index.row() + 1);
        return m_data;
    }

    return m_emptyVariant;
}

