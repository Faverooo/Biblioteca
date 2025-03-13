#include "EditWindow.h"
#include "../visitor/EditVisitor.h"
#include "../gestioneMedia/StorageManager.h"
#include <QMessageBox>

EditWindow::EditWindow(QWidget *parent) : QWidget(parent), currentEditWidget(nullptr)
{

    layout = new QVBoxLayout(this);

    backButton = new QPushButton("Indietro", this);
    layout->addWidget(backButton);
    connect(backButton, &QPushButton::clicked, this, &EditWindow::backButtonClicked);

    banner = new QLabel("MODIFICA WIDGET", this);
    banner->setAlignment(Qt::AlignCenter);
    banner->setStyleSheet("font-size: 24px; font-weight: bold; color: blue;");

    layout->addWidget(banner);

    saveButton = new QPushButton("Salva", this);
    layout->addWidget(saveButton);
    //connect(saveButton, &QPushButton::clicked, this, &EditWindow::onSaveButtonClicked);
    setLayout(layout);

    currentEditWidget = nullptr;
}



void EditWindow::showEdit(int id){

    QList<Media*> storage = StorageManager::instance().getStorage();
    Media * editMedia = nullptr;
    for (Media* media : storage) {
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