#include <QApplication>
#include <QDir>
#include <QCoreApplication>
#include "../gestioneMedia/StorageManager.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Ottieni il percorso della directory corrente dell'applicazione
    QDir dir(QCoreApplication::applicationDirPath());

    // Costruisci il percorso completo per il file Biblioteca.json
    QString relativePath = "salvataggi/Biblioteca.json";
    QString fullPath = dir.filePath(relativePath);

    // Utilizza il percorso completo per aprire il file
    StorageManager::instance().fromFiletoStorage(fullPath);

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}