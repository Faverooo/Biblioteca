#include "CardScrollArea.h"
#include "../gestioneMedia/StorageManager.h"
#include "../modello_logico/Libro.h"
#include "../modello_logico/Rivista.h"
#include "../modello_logico/Film.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"

CardScrollArea::CardScrollArea(QWidget *parent) : QWidget(parent)
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
    for (const auto &media : mediaList)
    {
        if ((lastFilter == "TUTTO" ||
            (lastFilter == "Libri" && dynamic_cast<Libro*>(media)) ||
            (lastFilter == "Riviste" && dynamic_cast<Rivista*>(media)) ||
            (lastFilter == "Film" && dynamic_cast<Film*>(media)) ||
            (lastFilter == "Canzoni" && dynamic_cast<Canzone*>(media))
            ) &&
            (
                searchText.isEmpty() ||
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

}

void CardScrollArea::refreshView(const QString &filterType)
{
    lastFilter = filterType;
    refreshCards();
}

void CardScrollArea::refreshSearch(const QString &key, bool newSearchByTitle, bool newSearchByYear, bool newSearchByAuthor)
{
    searchText = key;
    searchByTitle = newSearchByTitle;
    searchByYear = newSearchByYear;
    searchByAuthor = newSearchByAuthor;
    refreshCards();
}

void CardScrollArea::ActionOnRemoveButtonClicked(int id)
{

    // Elimina l'elemento dallo StorageManager
    StorageManager::instance().removeToStorage(id);
    // Fai il refresh delle card
    refreshCards();
}

void CardScrollArea::ActionOnEditButtonClicked(int id)
{
    emit editButtonClicked(id);
}