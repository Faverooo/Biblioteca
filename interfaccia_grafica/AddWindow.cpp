#include "AddWindow.h"
#include "../visitor/EditVisitor.h"
#include "../gestioneMedia/StorageManager.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QShortcut>

AddWindow::AddWindow(QWidget *parent) : QWidget(parent), currentEditWidget(nullptr)
{

    layout = new QVBoxLayout(this); //layout principale

    
    banner = new QLabel("AGGIUNTA WIDGET", this);
    banner->setAlignment(Qt::AlignCenter);
    banner->setStyleSheet("font-size: 24px; font-weight: bold; color: black; background-color:rgb(225, 227, 222); border: 2px solid lightgreen; border-radius: 10px; padding: 10px; font-family: 'Arial', sans-serif;");
    
    layout->addWidget(banner);
    
    backButton = new QPushButton("Indietro", this);
    layout->addWidget(backButton);
    connect(backButton, &QPushButton::clicked, this, &AddWindow::backButtonClicked);
    
    saveButton = new QPushButton("Salva (ctrl+s)", this);
    layout->addWidget(saveButton);
    connect(saveButton, &QPushButton::clicked, this, &AddWindow::onSaveButtonClicked);
    
    comboBox = new QComboBox(this);
    comboBox->addItem("Seleziona tipo");
    comboBox->addItem("Libro");
    comboBox->addItem("Rivista");
    comboBox->addItem("Film");
    comboBox->addItem("Canzone");
    comboBox->addItem("Playlist");
    layout->addWidget(comboBox);
    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AddWindow::onComboBoxChanged);
    layout->addStretch();

    // Shortcut oltre al pulsante di salvataggio
    const QShortcut *saveShortcut = new QShortcut(QKeySequence("Ctrl+S"), this);
    connect(saveShortcut, &QShortcut::activated, this, &AddWindow::onSaveButtonClicked);

    setLayout(layout);
    saveButton->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    backButton->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
}

void AddWindow::resetComboBox()
{
    comboBox->setCurrentIndex(0);
}

void AddWindow::onComboBoxChanged(int index)
{
    if (currentEditWidget) //se un widget é caricato lo elimina
    {
        layout->removeWidget(currentEditWidget);
        delete currentEditWidget;
        currentEditWidget = nullptr;
    }

    //a seconda dell'indice carica un widget diverso vuoto a seconda del media scelto,
    switch (index)
    {
    case 1: // Libro
        currentEditWidget = new LibroEditWidget(this);
        if (auto libroWidget = qobject_cast<LibroEditWidget *>(currentEditWidget))
        {
            libroWidget->setTitolo("");
            libroWidget->setAnno("");
            libroWidget->setAutore("");
            libroWidget->setPagine("");
            libroWidget->setPercorso("");
            libroWidget->setID(StorageManager::instance().generateID());
        }
        break;
    case 2: // Rivista
        currentEditWidget = new RivistaEditWidget(this);
        if (auto rivistaWidget = qobject_cast<RivistaEditWidget *>(currentEditWidget))
        {
            rivistaWidget->setTitolo("");
            rivistaWidget->setAnno("");
            rivistaWidget->setEditore("");
            rivistaWidget->setPagine("");
            rivistaWidget->setPercorso("");
            rivistaWidget->setID(StorageManager::instance().generateID());
        }
        break;
    case 3: // Film
        currentEditWidget = new FilmEditWidget(this);
        if (auto filmEditWidget = qobject_cast<FilmEditWidget *>(currentEditWidget))
        {
            filmEditWidget->setTitolo("");
            filmEditWidget->setAnno("");
            filmEditWidget->setSize("");
            filmEditWidget->setDurata("");
            filmEditWidget->setDurata("");
            filmEditWidget->setRegista("");
            filmEditWidget->setLingua("");
            filmEditWidget->setID(StorageManager::instance().generateID());
        }
        break;
    case 4: // Canzone
        currentEditWidget = new CanzoneEditWidget(this);
        if (auto canzoneEditWidget = qobject_cast<CanzoneEditWidget *>(currentEditWidget))
        {
            canzoneEditWidget->setTitolo("");
            canzoneEditWidget->setAnno("");
            canzoneEditWidget->setSize("");
            canzoneEditWidget->setDurata("");
            canzoneEditWidget->setDurata("");
            canzoneEditWidget->setArtista("");
            canzoneEditWidget->setID(StorageManager::instance().generateID());
        }
        break;
    case 5: // Playlist
        currentEditWidget = new AlbumEditWidget(this);
        if (auto albumEditWidget = qobject_cast<AlbumEditWidget *>(currentEditWidget))
        {
            albumEditWidget->setTitolo("");
            albumEditWidget->setAnno("");
            albumEditWidget->setID(StorageManager::instance().generateID());
        }
        break;
    default:
        break;
    }

    if (currentEditWidget)
    {
        // layout->insertWidget(layout->count() - 2, currentEditWidget); // Inserisce sopra il pulsante "Salva", salva in basso
        layout->addWidget(currentEditWidget);
    }
}

void AddWindow::onSaveButtonClicked()
{
    if (currentEditWidget)
    {
        currentEditWidget->saveImg(); //gestisce in maniera inteligente l'eliminazione/aggiunta di foto con stesso nome, refresh ecc...
        Media *media = currentEditWidget->getMedia();
        if (media)
        {
            StorageManager::instance().addToStorage(media);
            emit backButtonClicked(); // Torna alla schermata di ricerca
        }
        else
        {
            QMessageBox::warning(this, "Errore", "Errore durante la creazione dell'oggetto media.");
        }
    }
    else
    {
        QMessageBox::warning(this, "Errore", "Nessun widget di modifica selezionato.");
    }
}