#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

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

signals:
    void addButtonClicked();
};

#endif // SEARCHVIEW_H