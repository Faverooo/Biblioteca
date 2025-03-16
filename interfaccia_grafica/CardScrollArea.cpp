#include "CardScrollArea.h"
#include "../gestioneMedia/StorageManager.h"

CardScrollArea::CardScrollArea(QWidget *parent) : QWidget(parent) {
    cardVisitor = new CardVisitor;
    cardLayout = new QVBoxLayout();

    // Aggiungi alcune card di esempio
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

void CardScrollArea::refreshCards() {
    // Rimuovi tutte le card esistenti
    QLayoutItem *item;
    while ((item = cardLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Aggiungi nuove card
    
    QList<Media*> mediaList = *StorageManager::instance().getStorage();
    
    for (const auto& media : mediaList) {
        media->acceptVisitor(cardVisitor);
        QWidget *card = cardVisitor->getCard();
        cardLayout->addWidget(card);
    }
}

void CardScrollArea::ActionOnRemoveButtonClicked(int id) {

    // Elimina l'elemento dallo StorageManager
    StorageManager::instance().removeToStorage(id);
    // Fai il refresh delle card
    refreshCards();
}

void CardScrollArea::ActionOnEditButtonClicked(int id) {
    emit editButtonClicked(id);
}