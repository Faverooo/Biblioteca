#ifndef MAINWNDOW_H
#define MAINWNDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QStackedWidget *stackedWidget;

private slots:
    

};

#endif // MAINWNDOW_H
