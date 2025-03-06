#ifndef CARDVISITOR_H
#define CARDVISITOR_H

#include "Visitor.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QObject>

class CardVisitor: public QWidget, public Visitor{
    Q_OBJECT

private: 
    QWidget* card;
    QLabel* imgLabel;
    QLabel* titolo;
    QLabel* anno;
    QPushButton* edit;
    QPushButton* remove;

public:
    virtual void visit(Libro *libro);
    virtual void visit(Rivista *rivista);
    virtual void visit(Film *film);
    virtual void visit(Canzone *canzone);
    virtual void visit(Album *album);

    QWidget* getCard();
    void setDefaultAttributes(Media* media);

signals:
    void editButtonClicked(int id);
    void removeButtonClicked(int id);

private slots:
    void handleEditButtonClicked(int id);
    void handleRemoveButtonClicked(int id);
};

#endif // CARDVISITOR_H