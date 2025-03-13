#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "../visitor/DeriviedEditVisitor.h"

class EditWindow : public QWidget {
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    void showEdit(int id);    
signals:
    void backButtonClicked();

private slots:
    //void onSaveButtonClicked();
private:
    QVBoxLayout *layout;
    QLabel *banner;
    QPushButton *backButton;
    QPushButton *saveButton;
    AbsEditWidget *currentEditWidget;
};

#endif // EDITWINDOW_H