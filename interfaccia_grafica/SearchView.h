#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QListWidget>

class SearchView : public QWidget {
    Q_OBJECT

public:
    explicit SearchView(QWidget *parent = nullptr);

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *topBarLayout;
    QVBoxLayout *sideBarLayout;
    QLineEdit *searchBar;
    QComboBox *selector;
    QPushButton *searchButton;
    QListWidget *booksDisplay;

    void setupUI();
};

#endif // SEARCHVIEW_H