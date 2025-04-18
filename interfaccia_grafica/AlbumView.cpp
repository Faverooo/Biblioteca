#include "AlbumView.h"
#include "../gestioneMedia/StorageManager.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"

#include <QLabel>
#include <QDir>
#include <QCoreApplication>


AlbumView::AlbumView(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Pulsante di back
    backButton = new QPushButton("Back", this);
    backButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    connect(backButton, &QPushButton::clicked, this, &AlbumView::backButtonClicked);
    mainLayout->addWidget(backButton, 0, Qt::AlignLeft);

    // Scroll area
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollContent = new QWidget(scrollArea);
    scrollLayout = new QVBoxLayout(scrollContent);

    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);

    setLayout(mainLayout);
}

void AlbumView::show(int id) {
    // Rimuovi tutte le card presenti
    QLayoutItem *item;
    while ((item = scrollLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Ottieni lo storage
    QList<Media*> *storage = StorageManager::instance().getStorage();
    Album *album = nullptr;

    // Trova l'album con l'ID specificato
    for (Media *media : *storage) {
        album = dynamic_cast<Album*>(media);
        if (album && album->getID() == id) {
            break;
        }
    }

    if (!album) {
        // Mostra un messaggio di errore se l'album non viene trovato
        QLabel *errorLabel = new QLabel("Album non trovato.", this);
        scrollLayout->addWidget(errorLabel);
        return;
    }

    // Ottieni la lista degli ID delle canzoni nell'album
    QList<int> archivio = album->getArchivio();

    // Crea le card per ogni canzone nell'archivio
    for (int songId : archivio) {
        for (Media *media : *storage) {
            Canzone *canzone = dynamic_cast<Canzone*>(media);
            if (canzone && canzone->getID() == songId) {
                QWidget *card = createCard(canzone);
                scrollLayout->addWidget(card);
                break;
            }
        }
    }
}

QWidget* AlbumView::createCard(Canzone* canzone) {
    QWidget* card = new QWidget();
    QHBoxLayout *mainLayout = new QHBoxLayout(card);

    // Layout per la foto
    QVBoxLayout *leftLayout = new QVBoxLayout();
    // carica foto
    QLabel* imgLabel = new QLabel(card);
    QDir dir(QCoreApplication::applicationDirPath());
    QString imgPath = dir.filePath(canzone->getPercorsoImg());
    QPixmap pixmap(imgPath);
    imgLabel->setPixmap(pixmap.scaled(QSize(540,540), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    imgLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imgLabel->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(imgLabel);

    // Layout per gli attributi e i pulsanti
    QVBoxLayout *rightLayout = new QVBoxLayout();
    QLabel* titolo = new QLabel("Titolo: " + canzone->getTitolo(), card);
    QLabel* anno = new QLabel("Anno: " + QString::number(canzone->getAnno()), card);
    QLabel *size = new QLabel("Dimensione (MB): " + QString::number(canzone->getSize()));
    QLabel *durata = new QLabel("Durata (sec): " + QString::number(canzone->getDurata()));
    QLabel *artista = new QLabel("Artista: " + canzone->getArtista());

    rightLayout->addWidget(titolo);
    rightLayout->addWidget(anno);
    rightLayout->addWidget(durata);
    rightLayout->addWidget(artista);
    rightLayout->addWidget(size);
    rightLayout->addStretch();

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    rightLayout->addLayout(buttonLayout);

    // Aggiungi i layout al layout principale
    mainLayout->addLayout(leftLayout, 1); // Imposta il fattore di espansione a 1
    mainLayout->addLayout(rightLayout, 1); // Imposta il fattore di espansione a 1

    card->setLayout(mainLayout);

    // Applica i fogli di stile
    card->setStyleSheet("background-color: #f0f0f0; border: 1px solid #ccc; border-radius: 10px; padding: 10px;");
    imgLabel->setStyleSheet("border: 1px solid #ccc; border-radius: 5px;");
    titolo->setStyleSheet("font-weight: bold; font-size: 16px; margin-bottom: 5px;");
    anno->setStyleSheet("color: #666; margin-bottom: 5px;");
    durata->setStyleSheet("color: #666; margin-bottom: 5px;");
    artista->setStyleSheet("color: #666; margin-bottom: 5px;");
    size->setStyleSheet("color: #666; margin-bottom: 5px;");
    return card;
}