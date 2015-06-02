#ifndef MILLIONROWS_H
#define MILLIONROWS_H

#include <QAbstractItemModel>

/*
 * Use QAbstractItemModel bcause model can be used in defferent Views
 */
class MillionRows : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit MillionRows(QObject *parent);
    static const int RowCount = 100000;

private:
    virtual QModelIndex parent(const QModelIndex& index) const Q_DECL_OVERRIDE;
    virtual QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
private:
    const QModelIndex m_emptyIndex;
    const QVariant m_emptyVariant;
};

#endif // MILLIONROWS_H
