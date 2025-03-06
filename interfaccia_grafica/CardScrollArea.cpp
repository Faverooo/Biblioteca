#include"CardScrollArea.h"
#include "../visitor/CardVisitor.h"
#include "../gestioneMedia/StorageManager.h"

CardScrollArea::CardScrollArea(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *cardLayout = new QVBoxLayout();

    // Aggiungi alcune card di esempio
    CardVisitor cardVisitor;
    QList<Media*> mediaList = StorageManager::instance().getStorage();
    
    for (const auto& media : mediaList) {
        media->acceptVisitor(&cardVisitor);
        QWidget *card = cardVisitor.getCard();
        cardLayout->addWidget(card);
    }

    QWidget *contentWidget = new QWidget(this);
    contentWidget->setLayout(cardLayout);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(contentWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet("background-color: white;");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);
}