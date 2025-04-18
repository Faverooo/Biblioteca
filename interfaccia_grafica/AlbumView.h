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
    void show(int id);
private:
    QPushButton *backButton;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *scrollLayout; //le card sono qui dentro


    QWidget *createCard(Canzone *canzone);
signals:
    void backButtonClicked();
};

#endif // ALBUMVIEW_H