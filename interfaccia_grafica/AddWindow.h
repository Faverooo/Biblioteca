#ifndef ADD_WINDOW_H
#define ADD_WINDOW_H

#include <QWidget>
#include<QLabel>
#include<QVBoxLayout>

class AddWindow : public QWidget {
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    
private:
    QLabel *banner;
    QWidget* editwidget;
    QVBoxLayout *layout;
    
};

#endif // ADD_WINDOW_H