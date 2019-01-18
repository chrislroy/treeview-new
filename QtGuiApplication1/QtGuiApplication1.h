#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication1.h"
class QTreeWidgetItem;
class QtGuiApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtGuiApplication1(QWidget *parent = Q_NULLPTR);

public slots:
    void addItem();
    void removeItem();
    void addBranch();
    void itemSelected(QTreeWidgetItem *, int);
private:
    Ui::QtGuiApplication1Class ui;

    QTreeWidgetItem* currentItem = {};
};

