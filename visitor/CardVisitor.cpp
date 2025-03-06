#include "CardVisitor.h"
#include "../modello_logico/Libro.h"
#include "../modello_logico/Rivista.h"
#include "../modello_logico/Film.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"


#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDir>
#include <QCoreApplication>



void CardVisitor::visit(Libro *libro)
{
    
    card = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(card);
    setDefaultAttributes(libro);
    QLabel *pagine = new QLabel(QString::number(libro->getPagine()));
    QLabel *autore = new QLabel(libro->getAutore());

    layout->addWidget(imgLabel);
    layout->addWidget(titolo);
    layout->addWidget(anno);
    layout->addWidget(pagine);
    layout->addWidget(autore);
    layout->addWidget(edit);
    layout->addWidget(remove);
    card->setLayout(layout);
}

void CardVisitor::visit(Rivista *rivista)
{
   
}
void CardVisitor::visit(Film *film)
{
   
}
void CardVisitor::visit(Canzone *canzone)
{
   
}
void CardVisitor::visit(Album *album)
{
   
}







void CardVisitor::setDefaultAttributes(Media* media)
{   
    imgLabel = new QLabel("img",card);
    QDir dir(QCoreApplication::applicationDirPath());
    QString imgPath = dir.filePath(media->getPercorsoImg());
    QPixmap pixmap(imgPath);
    imgLabel->setPixmap(pixmap);
    
    titolo = new QLabel(media->getTitolo(), card);
    anno = new QLabel(QString::number(media->getAnno()), card);
    edit = new QPushButton("MODIFICA", card);
    remove = new QPushButton("MODIFICA", card);
    
    // Collega i segnali dei pulsanti agli slot con l'ID dell'oggetto
    connect(edit, &QPushButton::clicked, [this, media]() { handleEditButtonClicked(media->getID()); });
    connect(remove, &QPushButton::clicked, [this, media]() { handleRemoveButtonClicked(media->getID()); });
}

void CardVisitor::handleEditButtonClicked(int id)
{
    // Emitti il segnale con l'ID
    qWarning("Edit button clicked, id: %d", id);
    // emit editButtonClicked(id);
}

void CardVisitor::handleRemoveButtonClicked(int id)
{
    // Emitti il segnale con l'ID
    // emit removeButtonClicked(id);
    qWarning("id: ");
}

QWidget* CardVisitor::getCard()
{
    return card;
}