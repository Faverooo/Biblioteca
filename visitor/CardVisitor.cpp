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
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>

CardVisitor::CardVisitor(QObject *parent) : QObject(parent) {}

void CardVisitor::visit(Libro *libro)
{
    card = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(card);

    // Layout per la foto
    QVBoxLayout *leftLayout = new QVBoxLayout();
    setDefaultAttributes(libro);

    imgLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imgLabel->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(imgLabel);

    // Layout per gli attributi e i pulsanti
    QVBoxLayout *rightLayout = new QVBoxLayout();
    QLabel *pagine = new QLabel("Pagine: " + QString::number(libro->getPagine()));
    QLabel *autore = new QLabel("Autore: " + libro->getAutore());

    rightLayout->addWidget(titolo);
    rightLayout->addWidget(anno);
    rightLayout->addWidget(autore);
    rightLayout->addWidget(pagine);
    rightLayout->addStretch();
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    edit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    remove->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    buttonLayout->addWidget(edit);
    buttonLayout->addWidget(remove);
    rightLayout->addLayout(buttonLayout);

    // Aggiungi i layout al layout principale
    mainLayout->addLayout(leftLayout, 1);  // Imposta il fattore di espansione a 1
    mainLayout->addLayout(rightLayout, 1); // Imposta il fattore di espansione a 1

    card->setLayout(mainLayout);

    // Applica i fogli di stile
    card->setStyleSheet("background-color: #f0f0f0; border: 1px solid #ccc; border-radius: 10px; padding: 10px;");
    imgLabel->setStyleSheet("border: 1px solid #ccc; border-radius: 5px;");
    titolo->setStyleSheet("font-weight: bold; font-size: 16px; margin-bottom: 5px;");
    anno->setStyleSheet("color: #666; margin-bottom: 5px;");
    pagine->setStyleSheet("color: #666; margin-bottom: 5px;");
    autore->setStyleSheet("color: #666; margin-bottom: 5px;");
    edit->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    remove->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
}

void CardVisitor::visit(Rivista *rivista)
{
    card = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(card);

    // Layout per la foto
    QVBoxLayout *leftLayout = new QVBoxLayout();
    setDefaultAttributes(rivista);

    imgLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imgLabel->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(imgLabel);

    // Layout per gli attributi e i pulsanti
    QVBoxLayout *rightLayout = new QVBoxLayout();
    QLabel *pagine = new QLabel("Pagine: " + QString::number(rivista->getPagine()));
    QLabel *editore = new QLabel("Editore: " + rivista->getEditore());

    rightLayout->addWidget(titolo);
    rightLayout->addWidget(anno);
    rightLayout->addWidget(editore);
    rightLayout->addWidget(pagine);
    rightLayout->addStretch();

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    edit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    remove->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    buttonLayout->addWidget(edit);
    buttonLayout->addWidget(remove);
    rightLayout->addLayout(buttonLayout);

    // Aggiungi i layout al layout principale
    mainLayout->addLayout(leftLayout, 1);  // Imposta il fattore di espansione a 1
    mainLayout->addLayout(rightLayout, 1); // Imposta il fattore di espansione a 1

    card->setLayout(mainLayout);

    // Applica i fogli di stile
    card->setStyleSheet("background-color: #f0f0f0; border: 1px solid #ccc; border-radius: 10px; padding: 10px;");
    imgLabel->setStyleSheet("border: 1px solid #ccc; border-radius: 5px;");
    titolo->setStyleSheet("font-weight: bold; font-size: 16px; margin-bottom: 5px;");
    anno->setStyleSheet("color: #666; margin-bottom: 5px;");
    pagine->setStyleSheet("color: #666; margin-bottom: 5px;");
    editore->setStyleSheet("color: #666; margin-bottom: 5px;");
    edit->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    remove->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
}

void CardVisitor::visit(Film *film)
{
    card = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(card);

    // Layout per la foto
    QVBoxLayout *leftLayout = new QVBoxLayout();
    setDefaultAttributes(film);

    imgLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imgLabel->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(imgLabel);

    // Layout per gli attributi e i pulsanti
    QVBoxLayout *rightLayout = new QVBoxLayout();
    QLabel *size = new QLabel("Dimensione (MB): " + QString::number(film->getSize()));
    QLabel *durata = new QLabel("Durata (min): " + QString::number(film->getDurata()));
    QLabel *regista = new QLabel("Regista: " + film->getRegista());
    QLabel *lingua = new QLabel("Lingua: " + film->getLingua());

    rightLayout->addWidget(titolo);
    rightLayout->addWidget(anno);
    rightLayout->addWidget(durata);
    rightLayout->addWidget(regista);
    rightLayout->addWidget(lingua);
    rightLayout->addWidget(size);
    rightLayout->addStretch();

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    edit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    remove->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    buttonLayout->addWidget(edit);
    buttonLayout->addWidget(remove);
    rightLayout->addLayout(buttonLayout);

    // Aggiungi i layout al layout principale
    mainLayout->addLayout(leftLayout, 1);  // Imposta il fattore di espansione a 1
    mainLayout->addLayout(rightLayout, 1); // Imposta il fattore di espansione a 1

    card->setLayout(mainLayout);

    // Applica i fogli di stile
    card->setStyleSheet("background-color: #f0f0f0; border: 1px solid #ccc; border-radius: 10px; padding: 10px;");
    imgLabel->setStyleSheet("border: 1px solid #ccc; border-radius: 5px;");
    titolo->setStyleSheet("font-weight: bold; font-size: 16px; margin-bottom: 5px;");
    anno->setStyleSheet("color: #666; margin-bottom: 5px;");
    durata->setStyleSheet("color: #666; margin-bottom: 5px;");
    lingua->setStyleSheet("color: #666; margin-bottom: 5px;");
    regista->setStyleSheet("color: #666; margin-bottom: 5px;");
    size->setStyleSheet("color: #666; margin-bottom: 5px;");
    edit->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    remove->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
}

void CardVisitor::visit(Canzone *canzone)
{
    card = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(card);

    // Layout per la foto
    QVBoxLayout *leftLayout = new QVBoxLayout();
    setDefaultAttributes(canzone);

    imgLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imgLabel->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(imgLabel);

    // Layout per gli attributi e i pulsanti
    QVBoxLayout *rightLayout = new QVBoxLayout();
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
    buttonLayout->addWidget(edit);
    buttonLayout->addWidget(remove);
    rightLayout->addLayout(buttonLayout);

    // Aggiungi i layout al layout principale
    mainLayout->addLayout(leftLayout, 1);  // Imposta il fattore di espansione a 1
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
    edit->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    remove->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
}

void CardVisitor::visit(Album *album)
{
    card = new QWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(card);

    // Layout per la foto
    QVBoxLayout *leftLayout = new QVBoxLayout();
    imgLabel = new QLabel(card);
    QDir dir(QCoreApplication::applicationDirPath());
    QString imgPath = dir.filePath(album->getPercorsoImg());
    QPixmap pixmap(imgPath);
    if (pixmap.isNull())
    {
        // Set a default placeholder image if the image is missing or invalid
        QDir dir(QCoreApplication::applicationDirPath() + "/salvataggi");
        pixmap = QPixmap(dir.filePath("placeholder.png")); // Ensure placeholder.png exists in the specified directory
    }

    // Ottieni la risoluzione dello schermo
    QSize screenSize = QGuiApplication::primaryScreen()->size();
    int maxWidth = screenSize.width() / 5;   // Adatta la larghezza massima (1/5 della larghezza dello schermo)
    int maxHeight = screenSize.height() / 5; // Adatta l'altezza massima (1/5 dell'altezza dello schermo)

    // Ridimensiona l'immagine
    imgLabel->setPixmap(pixmap.scaled(QSize(maxWidth, maxHeight), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // attributi di base di album
    titolo = new QLabel("Nome Playlist: " + album->getTitolo(), card);
    anno = new QLabel("Anno: " + QString::number(album->getAnno()), card);
    edit = new QPushButton("MODIFICA", card);
    remove = new QPushButton("RIMUOVI", card);

    // Collega i segnali dei pulsanti agli slot con l'ID dell'oggetto
    connect(edit, &QPushButton::clicked, [this, album]()
            { handleEditButtonClicked(album->getID()); });
    connect(remove, &QPushButton::clicked, [this, album]()
            { handleRemoveButtonClicked(album->getID()); });

    imgLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    imgLabel->setAlignment(Qt::AlignCenter);
    leftLayout->addWidget(imgLabel);

    // Layout per gli attributi e i pulsanti
    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->addWidget(titolo);
    rightLayout->addWidget(anno);

    // Aggiungi altri widget specifici per Album

    QPushButton *visualizzaAlbum = new QPushButton("Vedi Contenuto", card);
    rightLayout->addWidget(visualizzaAlbum);
    connect(visualizzaAlbum, &QPushButton::clicked, [this, album]()
            { handleViewAlbumButtonClicked(album->getID()); });

    rightLayout->addStretch();

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(edit);
    buttonLayout->addWidget(remove);
    rightLayout->addLayout(buttonLayout);

    // Aggiungi i layout al layout principale
    mainLayout->addLayout(leftLayout, 1);  // Imposta il fattore di espansione a 1
    mainLayout->addLayout(rightLayout, 1); // Imposta il fattore di espansione a 1

    card->setLayout(mainLayout);

    // Applica i fogli di stile
    card->setStyleSheet("background-color: #f0f0f0; border: 1px solid #ccc; border-radius: 10px; padding: 10px;");
    imgLabel->setStyleSheet("border: 1px solid #ccc; border-radius: 5px;");
    titolo->setStyleSheet("font-weight: bold; font-size: 16px; margin-bottom: 5px;");
    anno->setStyleSheet("color: #666; margin-bottom: 5px;");
    visualizzaAlbum->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    edit->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    remove->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
}

void CardVisitor::setDefaultAttributes(const Media *media) // funzione ausiliaria comune
{
    // carica foto
    imgLabel = new QLabel(card);
    QDir dir(QCoreApplication::applicationDirPath());
    QString imgPath = dir.filePath(media->getPercorsoImg());
    QPixmap pixmap(imgPath);

    if (pixmap.isNull())
    {
        // Set a default placeholder image if the image is missing or invalid
        QDir dir(QCoreApplication::applicationDirPath() + "/salvataggi");
        pixmap = QPixmap(dir.filePath("placeholder.png")); // Ensure placeholder.png exists in the specified directory
    }

    // Ottieni la risoluzione dello schermo
    QSize screenSize = QGuiApplication::primaryScreen()->size();
    int maxWidth = screenSize.width() / 5;   // Adatta la larghezza massima (1/5 della larghezza dello schermo)
    int maxHeight = screenSize.height() / 5; // Adatta l'altezza massima (1/5 dell'altezza dello schermo)

    // Ridimensiona l'immagine
    imgLabel->setPixmap(pixmap.scaled(QSize(maxWidth, maxHeight), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // attributi di base di media
    titolo = new QLabel("Titolo: " + media->getTitolo(), card);
    anno = new QLabel("Anno: " + QString::number(media->getAnno()), card);
    edit = new QPushButton("MODIFICA", card);
    remove = new QPushButton("RIMUOVI", card);

    // Collega i segnali dei pulsanti agli slot con l'ID dell'oggetto
    connect(edit, &QPushButton::clicked, [this, media]()
            { handleEditButtonClicked(media->getID()); });
    connect(remove, &QPushButton::clicked, [this, media]()
            { handleRemoveButtonClicked(media->getID()); });
}

void CardVisitor::handleEditButtonClicked(int id)
{
    // Emitti il segnale con l'ID
    emit editButtonClicked(id);
}

void CardVisitor::handleRemoveButtonClicked(int id)
{
    // Emitti il segnale con l'ID
    emit removeButtonClicked(id);
}

void CardVisitor::handleViewAlbumButtonClicked(int id)
{
    // Emitti il segnale con l'ID
    emit viewAlbumButtonClicked(id);
}

QWidget *CardVisitor::getCard()
{
    return card;
}