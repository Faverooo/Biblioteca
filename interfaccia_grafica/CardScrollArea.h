#ifndef CARDSCROLLAREA_H
#define CARDSCROLLAREA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "../visitor/CardVisitor.h"

class CardScrollArea : public QWidget
{
    Q_OBJECT

public:
    explicit CardScrollArea(QWidget *parent = nullptr);
    void refreshCards();
    void refreshView(const QString &filterType); //aggiornamento vista, salvataggio vista
    void refreshSearch(const QString &key, bool newSearchByTitle, bool newSearchByYear, bool newSearchByAuthor); // aggiornamento filtri, salvataggio filtri

private:
    //gestione filtri
    QString searchText;
    bool searchByTitle;
    bool searchByYear;
    bool searchByAuthor;
    QString lastFilter;
    
    //gestione layout
    QVBoxLayout *cardLayout;
    QWidget *contentWidget;
    CardVisitor *cardVisitor;

signals:
    void editButtonClicked(int id);
    void viewAlbumButtonClicked(int id);

private slots:
    void ActionOnRemoveButtonClicked(int id);
    void ActionOnEditButtonClicked(int id); // propagazione alla mainwindow dalla card
    void ActionOnViewAlbumButtonClicked(int id); // propagazione alla mainwindow dalla card
};

#endif // CARDSCROLLAREA_H