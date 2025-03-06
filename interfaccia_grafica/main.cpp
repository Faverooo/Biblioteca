#include<QApplication>

#include"../gestioneMedia/StorageManager.h"
#include"MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString path = "../salvataggi/Biblioteca.json";
    StorageManager storageManager;
    storageManager.fromFiletoStorage(path);

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}

