#include "EditVisitor.h"

void EditVisitor::visit(Libro *libro) {
    editWidget = new LibroEditWidget();
    LibroEditWidget *libroEditWidget = qobject_cast<LibroEditWidget*>(editWidget);
    if (libro != nullptr) {
        libroEditWidget->setTitolo(libro->getTitolo());
        libroEditWidget->setAnno(QString::number(libro->getAnno()));
        libroEditWidget->setAutore(libro->getAutore());
        libroEditWidget->setPagine(QString::number(libro->getPagine()));
        libroEditWidget->setPercorso(libro->getPercorsoImg());
        libroEditWidget->setID(libro->getID());
    } else {
        libroEditWidget->setTitolo("");
        libroEditWidget->setAnno("");
        libroEditWidget->setAutore("");
        libroEditWidget->setPagine("");
        libroEditWidget->setPercorso("");
        libroEditWidget->setID(-1);
    }
}
