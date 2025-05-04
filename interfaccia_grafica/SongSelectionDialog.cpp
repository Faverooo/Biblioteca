#include "SongSelectionDialog.h"
#include <QLabel>

SongSelectionDialog::SongSelectionDialog(QList<int> &albumArchivio, QWidget *parent)
    : QDialog(parent), albumArchivio(albumArchivio) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    songListWidget = new QListWidget(this);
    mainLayout->addWidget(songListWidget);

    populateSongList();

    QPushButton *closeButton = new QPushButton("Chiudi", this);
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addWidget(closeButton);

    setLayout(mainLayout);
    setWindowTitle("Gestione Canzoni");
}

void SongSelectionDialog::populateSongList() {
    const QList<Media*> *storage = StorageManager::instance().getStorage();

    for (Media *media : *storage) {
        const Canzone *canzone = dynamic_cast<Canzone*>(media);
        if (canzone) {
            QPushButton *addRemoveButton = new QPushButton(this);

            // Controlla se la canzone è già nell'album
            if (albumArchivio.contains(canzone->getID())) {
            addRemoveButton->setText("Rimuovi");
            } else {
            addRemoveButton->setText("Aggiungi");
            }

            // Collega il pulsante alla funzione di aggiunta/rimozione
            connect(addRemoveButton, &QPushButton::clicked, [=]() {
            if (albumArchivio.contains(canzone->getID())) {
                albumArchivio.removeAll(canzone->getID());
                addRemoveButton->setText("Aggiungi");
            } else {
                albumArchivio.append(canzone->getID());
                addRemoveButton->setText("Rimuovi");
            }
            });

            // Aggiungi il pulsante accanto all'elemento della lista
            QWidget *widget = new QWidget(this);
            QHBoxLayout *layout = new QHBoxLayout(widget);
            layout->addWidget(new QLabel(canzone->getTitolo(), this));
            layout->addWidget(addRemoveButton);
            layout->setContentsMargins(0, 0, 0, 0);
            widget->setLayout(layout);

            QListWidgetItem *listItem = new QListWidgetItem(songListWidget);
            songListWidget->setItemWidget(listItem, widget);
        }
    }
}