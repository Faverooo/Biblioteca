#include "EditWindow.h"
#include "../visitor/EditVisitor.h"
#include "../gestioneMedia/StorageManager.h"
#include <QMessageBox>
#include <QFile>
#include <QCoreApplication>
#include <QShortcut>

EditWindow::EditWindow(QWidget *parent) : QWidget(parent), currentEditWidget(nullptr)
{

    layout = new QVBoxLayout(this);

    
    banner = new QLabel("MODIFICA WIDGET", this);
    banner->setAlignment(Qt::AlignCenter);
    banner->setStyleSheet("font-size: 24px; font-weight: bold; color: black; background-color:rgb(225, 227, 222); border: 2px solid lightgreen; border-radius: 10px; padding: 10px; font-family: 'Arial', sans-serif;");
    
    layout->addWidget(banner);
    
    backButton = new QPushButton("Indietro", this);
    layout->addWidget(backButton);
    connect(backButton, &QPushButton::clicked, this, &EditWindow::backButtonClicked);
    saveButton = new QPushButton("Salva (ctrl+s)", this);
    layout->addWidget(saveButton);
    connect(saveButton, &QPushButton::clicked, this, &EditWindow::save);
    layout->addStretch();
    setLayout(layout);

    //Shortcut oltre al pulsante di salvataggio
    QShortcut *saveShortcut = new QShortcut(QKeySequence("Ctrl+S"), this);
    connect(saveShortcut, &QShortcut::activated, this, &EditWindow::save);

    currentEditWidget = nullptr;

    saveButton->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 10px; border-radius: 5px;");
    backButton->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 5px 10px; border-radius: 5px;");

}



void EditWindow::showEdit(int id){

    QList<Media*>* storage = StorageManager::instance().getStorage();
    Media * editMedia = nullptr;
    for (Media* media : *storage) {
        if (media->getID() == id) {
            editMedia = media;
            break;
        }
    }
    if (editMedia == nullptr)
    {
        QMessageBox::warning(this, "Errore", "Media non trovato");
        emit backButtonClicked();
        return;
    }
    EditVisitor editVisitor;
    editMedia->acceptVisitor(&editVisitor);
    if (currentEditWidget!=nullptr) {
        layout->removeWidget(currentEditWidget);
        delete currentEditWidget;
        currentEditWidget = nullptr;
    }
    currentEditWidget = editVisitor.getCard();
    layout->addWidget(currentEditWidget);
}


void EditWindow::save(){
    if (currentEditWidget)
    {
        Media *media = currentEditWidget->getMedia();
        if (media)
        {
            QList<Media*> *storage = StorageManager::instance().getStorage();
            for (int i = 0; i < storage->size(); ++i) {
                if (storage->at(i)->getID() == media->getID()) {
                    if(currentEditWidget->getPercorso() != (storage->at(i)->getPercorsoImg()))
                    {
                        currentEditWidget->saveImg();
                        media = currentEditWidget->getMedia(); //da risalvare con l'immagine aggiornata
                        QFile::remove(QCoreApplication::applicationDirPath() + "/" + storage->at(i)->getPercorsoImg());
                        delete storage->at(i);
                    }
                    storage->replace(i, media);
                    StorageManager::instance().printToFile();
                    break;
                }
            }
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