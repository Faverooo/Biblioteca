#include "AddWindow.h"
#include "../visitor/EditVisitor.h"
#include "../gestioneMedia/StorageManager.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

AddWindow::AddWindow(QWidget *parent) : QWidget(parent), currentEditWidget(nullptr) {
    banner = new QLabel("AGGIUNTA WIDGET", this);
    banner->setAlignment(Qt::AlignCenter);
    banner->setStyleSheet("font-size: 24px; font-weight: bold; color: blue;");

    layout = new QVBoxLayout(this);
    layout->addWidget(banner);

    comboBox = new QComboBox(this);
    comboBox->addItem("Seleziona tipo");
    comboBox->addItem("Libro");
    comboBox->addItem("Rivista");
    comboBox->addItem("Film");
    layout->addWidget(comboBox);
    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AddWindow::onComboBoxChanged);
    
    backButton = new QPushButton("Indietro", this);
    layout->addWidget(backButton);
    connect(backButton, &QPushButton::clicked, this, &AddWindow::backButtonClicked);

    saveButton = new QPushButton("Salva", this);
    layout->addWidget(saveButton);
    connect(saveButton, &QPushButton::clicked, this, &AddWindow::onSaveButtonClicked);

    setLayout(layout);
}

void AddWindow::resetComboBox() {
    comboBox->setCurrentIndex(0);
}

void AddWindow::onComboBoxChanged(int index) {
    if (currentEditWidget) {
        layout->removeWidget(currentEditWidget);
        delete currentEditWidget;
        currentEditWidget = nullptr;
    }

    switch (index) {
        case 1: // Libro
            currentEditWidget = new LibroEditWidget(this);
            if (auto libroWidget = qobject_cast<LibroEditWidget*>(currentEditWidget)) {
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
            if (auto rivistaWidget = qobject_cast<RivistaEditWidget*>(currentEditWidget)) {
                rivistaWidget->setTitolo("");
                rivistaWidget->setAnno("");
                rivistaWidget->setEditore("");
                rivistaWidget->setPagine("");
                rivistaWidget->setPercorso("");
                rivistaWidget->setID(StorageManager::instance().generateID());
            }
            break;
        case 3: // Film
            // Implementa la creazione di FilmEditWidget
            break;
        default:
            break;
    }

    if (currentEditWidget) {
        layout->addWidget(currentEditWidget);
    }
}


void AddWindow::onSaveButtonClicked() {
    if (currentEditWidget) {
        Media *media = currentEditWidget->getMedia();
        if (media) {
            StorageManager::instance().addToStorage(media);
            emit backButtonClicked(); // Torna alla schermata di ricerca
        } else {
            QMessageBox::warning(this, "Errore", "Errore durante la creazione dell'oggetto media.");
        }
    } else {
        QMessageBox::warning(this, "Errore", "Nessun widget di modifica selezionato.");
    }
}