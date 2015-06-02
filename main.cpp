#include "million_rows.h"
#include "style_delegate.h"
#include <QApplication>
#include <QTableView>
#include <QHeaderView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QListView view;
    QTableView view;
    view.setSortingEnabled(false);
    view.horizontalHeader()->setStretchLastSection(true);
    view.horizontalHeader()->setVisible(false);
    view.verticalHeader()->setVisible(false);

    MillionRows model(nullptr);

    view.setModel(&model);
    view.setAlternatingRowColors(true);
    view.setStyleSheet("alternate-background-color: green;background-color: white;");
    view.setItemDelegateForColumn(0, new TableStyleDelegate());

    view.resizeRowsToContents(); // impact performance - force call sizeHint
    view.show();

    return a.exec();
}
