#include "../json_manager/StorageManager.h"
#include <QCoreApplication>
#include <QDebug>

void testStorageManager() {
    StorageManager manager;

    // Percorso del file JSON di input
    QString inputFilePath = "/home/marco/Biblioteca/test/input.json";
    // Percorso del file JSON di output
    QString outputFilePath = "/home/marco/Biblioteca/test/output.json";

    // Popola lo storage dal file JSON
    manager.fromFiletoStorage(inputFilePath);

    // Stampa il contenuto dello storage su un altro file JSON
    manager.printToFile(outputFilePath);

    qDebug() << "Test completato. Controlla il file di output:" << outputFilePath;
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    testStorageManager();

    return 0;
}