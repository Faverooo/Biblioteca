#ifndef SONGSELECTIONDIALOG_H
#define SONGSELECTIONDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "../gestioneMedia/StorageManager.h"
#include "../modello_logico/Canzone.h"

class SongSelectionDialog : public QDialog {
    Q_OBJECT

public:
    explicit SongSelectionDialog(QList<int> &albumArchivio, QWidget *parent = nullptr);

private:
    QListWidget *songListWidget;
    QList<int> &albumArchivio; // Riferimento all'archivio dell'album
    void populateSongList();
};

#endif // SONGSELECTIONDIALOG_H