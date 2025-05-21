#include "EditVisitor.h"
#include <QDebug>


EditVisitor::EditVisitor() : editWidget(nullptr) {}

//UTILIZZANO LE CLASSI CREATE IN DeriviedEditVisitor E NE SETTANO GLI ATTRIBUTI PER LA MODIFICA

void EditVisitor::visit(Libro *libro) {
    if (editWidget!=nullptr){
        delete editWidget;}
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
    if (editWidget!=nullptr)
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
    if (editWidget!=nullptr)
        delete editWidget;
    editWidget = new FilmEditWidget();
    FilmEditWidget *filmEditWidget = qobject_cast<FilmEditWidget*>(editWidget);
    filmEditWidget->setTitolo(film->getTitolo());
    filmEditWidget->setAnno(QString::number(film->getAnno()));
    filmEditWidget->setSize(QString::number(film->getSize()));
    filmEditWidget->setDurata(QString::number(film->getDurata()));
    filmEditWidget->setPercorso(film->getPercorsoImg());
    filmEditWidget->setID(film->getID());
    filmEditWidget->setRegista(film->getRegista());
    filmEditWidget->setLingua(film->getLingua());
}

void EditVisitor::visit(Canzone *canzone) {
    if (editWidget!=nullptr)
        delete editWidget;
    editWidget = new CanzoneEditWidget();
    CanzoneEditWidget *canzoneEditWidget = qobject_cast<CanzoneEditWidget*>(editWidget);
    canzoneEditWidget->setTitolo(canzone->getTitolo());
    canzoneEditWidget->setAnno(QString::number(canzone->getAnno()));
    canzoneEditWidget->setSize(QString::number(canzone->getSize()));
    canzoneEditWidget->setDurata(QString::number(canzone->getDurata()));
    canzoneEditWidget->setPercorso(canzone->getPercorsoImg());
    canzoneEditWidget->setID(canzone->getID());
    canzoneEditWidget->setArtista(canzone->getArtista());
}

void EditVisitor::visit(Album *album) {
    if (editWidget!=nullptr)
        delete editWidget;
    editWidget = new AlbumEditWidget();
    AlbumEditWidget *albumEditWidget = qobject_cast<AlbumEditWidget*>(editWidget);
    albumEditWidget->setTitolo(album->getTitolo());
    if (album->getAnno() == std::numeric_limits<int>::min()) // se è vuoto scrivi vuoto
        albumEditWidget->setAnno("");
    else
        albumEditWidget->setAnno(QString::number(album->getAnno()));
    albumEditWidget->setPercorso(album->getPercorsoImg());
    albumEditWidget->setID(album->getID());
    albumEditWidget->setArchivio(album->getArchivio());

}




AbsEditWidget* EditVisitor::getCard(){
    return editWidget;
}