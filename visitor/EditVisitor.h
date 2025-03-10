#ifndef EDITVISITOR_H
#define EDITVISITOR_H

#include "Visitor.h"
#include "DeriviedEditVisitor.h"
#include <QWidget>


class EditVisitor: public Visitor{
private: 
    // da restituire con il getter
    AbsEditWidget* editWidget;

public:
    virtual void visit(Libro *libro);
    virtual void visit(Rivista *rivista);
    virtual void visit(Film *film);
    virtual void visit(Canzone *canzone);
    virtual void visit(Album *album);

    //getter
    QWidget* getCard();

};

#endif // EDITVISITOR_H
