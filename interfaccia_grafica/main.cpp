#include <QApplication>
#include <QDir>
#include <QCoreApplication>
#include "../gestioneMedia/StorageManager.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    qputenv("QT_QPA_PLATFORM", "xcb"); //per evitare warning a causa dell'ambiente grafico 
    QApplication app(argc, argv);

    // Ottieni il percorso della directory corrente dell'applicazione
    QDir dir(QCoreApplication::applicationDirPath());
    // Costruisci il percorso completo per il file Biblioteca.json
    QString relativePath = "salvataggi/Biblioteca.json";
    QString fullPath = dir.filePath(relativePath);
    StorageManager::instance().setPath(dir.filePath(relativePath));
    // Utilizza il percorso completo per aprire il file
    StorageManager::instance().fromFiletoStorage();

    MainWindow mainWindow;
    mainWindow.setWindowTitle("MyArchive");
    mainWindow.show();
    return app.exec();
}