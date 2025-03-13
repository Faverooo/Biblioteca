#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SearchView.h"
#include "AddWindow.h"

#include <QMainWindow>
#include <QStackedWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void showAddView();
    void showSearchView();

private:
    QStackedWidget *stackedWidget;
    SearchView *searchView;
    AddWindow *addWindow;
};

#endif // MAINWINDOW_H