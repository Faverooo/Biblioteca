#ifndef EDITVISITOR_H
#define EDITVISITOR_H

#include "DeriviedEditVisitor.h"


class EditVisitor: public Visitor{
private: 
    // da restituire con il getter
    AbsEditWidget* editWidget;

public:
    EditVisitor();
    void visit(Libro *libro);
    void visit(Rivista *rivista);
    void visit(Film *film);
    void visit(Canzone *canzone);
    void visit(Album *album);

    //getter
    AbsEditWidget* getCard();

};

#endif // EDITVISITOR_H
