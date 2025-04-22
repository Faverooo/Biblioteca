#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SearchView.h"
#include "AddWindow.h"
#include "EditWindow.h"
#include "AlbumView.h"

#include <QMainWindow>
#include <QStackedWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void showAddView();
    void showSearchView();
    void showEditView(int id);
    void showAlbum(int id);
private:
    QStackedWidget *stackedWidget;
    SearchView *searchView;
    AddWindow *addWindow;
    EditWindow *editWindow;
    AlbumView *albumView;
};

#endif // MAINWINDOW_H