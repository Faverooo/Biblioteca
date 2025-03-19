#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

#include "CardScrollArea.h"

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class SearchView : public QWidget {
    Q_OBJECT

public:
    explicit SearchView(QWidget *parent = nullptr);
    void refresh();

private:
    void setupUI();

    QLineEdit *searchBar;
    QPushButton *searchButton;
    QCheckBox *titleCheckBox;
    QCheckBox *yearCheckBox;
    QCheckBox *authorCheckBox;
    QPushButton *addButton;
    QComboBox *selector;
    QPushButton *resetButton;
    QWidget *sideBarWidget;
    QWidget *topBarWidget;
    QVBoxLayout *contentLayout;
    CardScrollArea *cardScrollArea;

signals:
    void addButtonClicked();
    void editButtonClicked(int id);

private slots:
    void ActionOnEditButtonClicked(int id);
    void onSelectorChanged();
};

#endif // SEARCHVIEW_H