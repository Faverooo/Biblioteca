#include "CardScrollArea.h"
#include "../gestioneMedia/StorageManager.h"
#include "../modello_logico/Libro.h"
#include "../modello_logico/Rivista.h"
#include "../modello_logico/Film.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"

#include<QMessageBox>

CardScrollArea::CardScrollArea(QWidget *parent) : QWidget(parent) // conterrà tutte le card
{
    cardVisitor = new CardVisitor;
    cardLayout = new QVBoxLayout();

    // Aggiungi alcune card di esempio
    lastFilter = "TUTTO";
    refreshCards();

    contentWidget = new QWidget(this);
    contentWidget->setLayout(cardLayout);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(contentWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("background-color: white;");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);

    // Collega il segnale al slot
    connect(cardVisitor, &CardVisitor::removeButtonClicked, this, &CardScrollArea::ActionOnRemoveButtonClicked);
    connect(cardVisitor, &CardVisitor::editButtonClicked, this, &CardScrollArea::ActionOnEditButtonClicked);
    connect(cardVisitor, &CardVisitor::viewAlbumButtonClicked, this, &CardScrollArea::ActionOnViewAlbumButtonClicked);
}

void CardScrollArea::refreshCards()
{
    // Rimuovi tutte le card esistenti
    QLayoutItem *item;
    while ((item = cardLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }
    // Aggiungi nuove card
    QList<Media *> mediaList = *StorageManager::instance().getStorage();
    bool match = false;
    QString fields;
    //ricerca case-insensitive
    for (const auto &media : mediaList)
    {
        fields = media->getFields();
        QStringList searchWords = searchText.split(' ', Qt::SkipEmptyParts);
        match = true;
        for (const QString &word : searchWords) {
            if (!fields.contains(word, Qt::CaseInsensitive)) {
            match = false;
            break;
            }
        }
        //applica i vari filtri in base al tipo di media richiesto
        if ((lastFilter == "TUTTO" ||
            (lastFilter == "Libri" && dynamic_cast<Libro*>(media)) ||
            (lastFilter == "Riviste" && dynamic_cast<Rivista*>(media)) ||
            (lastFilter == "Film" && dynamic_cast<Film*>(media)) ||
            (lastFilter == "Canzoni" && dynamic_cast<Canzone*>(media)) ||
            (lastFilter == "Album" && dynamic_cast<Album*>(media))
            ) &&
            (
                searchText.isEmpty() ||
                (!searchByTitle && !searchByYear && !searchByAuthor && match) ||
                (
                    (searchByTitle && media->getTitolo().contains(searchText, Qt::CaseInsensitive))
                    || (searchByYear && QString::number(media->getAnno()).contains(searchText, Qt::CaseInsensitive))
                    || (searchByAuthor && ((dynamic_cast<Libro*>(media) && (dynamic_cast<Libro*>(media)->getAutore().contains(searchText, Qt::CaseInsensitive)))
                                            || (dynamic_cast<Rivista*>(media) && (dynamic_cast<Rivista*>(media)->getEditore().contains(searchText, Qt::CaseInsensitive)))
                                            || (dynamic_cast<Film*>(media) && (dynamic_cast<Film*>(media)->getRegista().contains(searchText, Qt::CaseInsensitive)))
                                            || (dynamic_cast<Canzone*>(media) && (dynamic_cast<Canzone*>(media)->getArtista().contains(searchText, Qt::CaseInsensitive)))
                                            )
                        )
                )
            )
        )
        {
            // Mostra il media
            media->acceptVisitor(cardVisitor);
            QWidget *card = cardVisitor->getCard();
            cardLayout->addWidget(card);
        }
    }
    cardLayout->addStretch(); // Aggiungi uno spazio vuoto alla fine per il layout
}


//salvano i filtri in maniera tale da "incrociare" filtri e visualizzazione solo di un tipo di media

void CardScrollArea::refreshView(const QString &filterType)
{
    //salvo il filtro di visualizzazione
    lastFilter = filterType;
    refreshCards();
}

void CardScrollArea::refreshSearch(const QString &key, bool newSearchByTitle, bool newSearchByYear, bool newSearchByAuthor)
{ 
    //salvo i filtri di ricerca
    searchText = key;
    searchByTitle = newSearchByTitle;
    searchByYear = newSearchByYear;
    searchByAuthor = newSearchByAuthor;
    refreshCards();
}

void CardScrollArea::ActionOnRemoveButtonClicked(int id)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Conferma eliminazione",
                                  "Sei sicuro di voler eliminare questo media?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Elimina l'elemento dallo StorageManager
        StorageManager::instance().removeToStorage(id);
        // Fai il refresh delle card
        refreshCards();
    }
}

void CardScrollArea::ActionOnEditButtonClicked(int id)
{
    emit editButtonClicked(id);
}
void CardScrollArea::ActionOnViewAlbumButtonClicked(int id)
{
    emit viewAlbumButtonClicked(id);
}