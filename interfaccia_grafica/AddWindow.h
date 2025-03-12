#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "../visitor/DeriviedEditVisitor.h"

class AddWindow : public QWidget {
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    void resetComboBox();
    
signals:
    void backButtonClicked();

private slots:
    void onComboBoxChanged(int index);
    void onSaveButtonClicked();

private:
    QVBoxLayout *layout;
    QLabel *banner;
    QComboBox *comboBox;
    QPushButton *backButton;
    QPushButton *saveButton;
    AbsEditWidget *currentEditWidget;
};

#endif // ADDWINDOW_H