#ifndef ALBUMVIEW_H
#define ALBUMVIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "../modello_logico/Canzone.h"

class AlbumView : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumView(QWidget *parent = nullptr);
    void showID(int id);
private:
    QPushButton *backButton;
    QScrollArea *scrollArea; //scrollarea per le card (!!!diversa dalla scrollarea di CardScrollArea, riferita a tutte le card)
    QWidget *scrollContent; //contenuto della scrollarea
    QVBoxLayout *scrollLayout; //le card sono qui dentro


    QWidget *createCard(const Canzone *canzone); //per creare le card da visualizzare nella albumview
signals:
    void backButtonClicked();
};

#endif // ALBUMVIEW_H