#ifndef CARDVISITOR_H
#define CARDVISITOR_H

#include "Visitor.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QObject>

class CardVisitor: public QObject, public Visitor{
    Q_OBJECT

private: 
    // da restituire con il getter
    QWidget* card;

    //attributi comuni per ogni media
    QLabel* imgLabel;
    QLabel* titolo;
    QLabel* anno;
    QPushButton* edit;
    QPushButton* remove;

public:
    explicit CardVisitor(QObject* parent = nullptr);
    virtual void visit(Libro *libro);
    virtual void visit(Rivista *rivista);
    virtual void visit(Film *film);
    virtual void visit(Canzone *canzone);
    virtual void visit(Album *album);

    //getter
    QWidget* getCard();

    //set atributi per ogni media nella card
    void setDefaultAttributes(const Media* media);

signals:
    //segnale associato al id della card chiamante
    void editButtonClicked(int id);
    void removeButtonClicked(int id);
    void viewAlbumButtonClicked(int id);
private slots:
    //slots che associano la pressione al bottone e genera un segnale
    void handleEditButtonClicked(int id);
    void handleRemoveButtonClicked(int id);
    void handleViewAlbumButtonClicked(int id);
};

#endif // CARDVISITOR_H