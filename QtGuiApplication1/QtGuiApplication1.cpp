#include "QtGuiApplication1.h"
#include <iostream>
#include <QTreeWidgetItem>
#include <QFile>

using namespace std;

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QFile File("E:/dev/treeview-test/QtGuiApplication1/QtGuiApplication1/stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    qApp->setStyleSheet(StyleSheet);

    connect(ui.AddItemPB, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(ui.removeItemPB, SIGNAL(clicked()), this, SLOT(removeItem()));
    connect(ui.addBranchPB, SIGNAL(clicked()), this, SLOT(addBranch()));
    connect(ui.treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(itemSelected(QTreeWidgetItem *, int)));
}


void QtGuiApplication1::addItem()
{
    cout << "addItem" << endl;
    if (!currentItem)
        return;
    QString itemName = QString("child item %1").arg(currentItem->childCount());
    auto item = new QTreeWidgetItem(QStringList({ itemName }));
    currentItem->addChild(item);
    currentItem->setExpanded(true);
}

void QtGuiApplication1::removeItem()
{
    cout << "removeItem" << endl;
    if (!currentItem || !currentItem->parent())
        return;
    currentItem->parent()->removeChild(currentItem);
    currentItem = nullptr;
}

void QtGuiApplication1::addBranch()
{
    cout << "addBranch" << endl;
    auto count = ui.treeWidget->topLevelItemCount();
    QString itemName = QString("Top Level Item %1").arg(ui.treeWidget->topLevelItemCount());

    ui.treeWidget->addTopLevelItem(new QTreeWidgetItem({ itemName }));
}

void QtGuiApplication1::itemSelected(QTreeWidgetItem *item, int column)
{
    cout << "itemSelected" << endl;
    currentItem = item;
}
