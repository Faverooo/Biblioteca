#include "EditVisitor.h"
#include <QDebug>

void EditVisitor::visit(Libro *libro) {
    if (editWidget)
        delete editWidget;
    editWidget = new LibroEditWidget();
    LibroEditWidget *libroEditWidget = qobject_cast<LibroEditWidget*>(editWidget);
    libroEditWidget->setTitolo(libro->getTitolo());
    libroEditWidget->setAnno(QString::number(libro->getAnno()));
    libroEditWidget->setAutore(libro->getAutore());
    libroEditWidget->setPagine(QString::number(libro->getPagine()));
    libroEditWidget->setPercorso(libro->getPercorsoImg());
    libroEditWidget->setID(libro->getID());

}

void EditVisitor::visit(Rivista *rivista) {
    if (editWidget)
        delete editWidget;
    editWidget = new RivistaEditWidget();
    RivistaEditWidget *rivistaEditWidget = qobject_cast<RivistaEditWidget*>(editWidget);
    rivistaEditWidget->setTitolo(rivista->getTitolo());
    rivistaEditWidget->setAnno(QString::number(rivista->getAnno()));
    rivistaEditWidget->setEditore(rivista->getEditore());
    rivistaEditWidget->setPagine(QString::number(rivista->getPagine()));
    rivistaEditWidget->setPercorso(rivista->getPercorsoImg());
    rivistaEditWidget->setID(rivista->getID());
}

void EditVisitor::visit(Film *film) {
    // Implementation goes here
}

void EditVisitor::visit(Canzone *canzone) {
    // Implementation goes here
}

void EditVisitor::visit(Album *album) {
    // Implementation goes here
}




AbsEditWidget* EditVisitor::getCard(){
    return editWidget;
}