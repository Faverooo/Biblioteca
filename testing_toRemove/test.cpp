#include "../json_manager/StorageManager.h"
#include <QCoreApplication>
#include <QDebug>
#include"../modello_logico/Canzone.h"
void testStorageManager() {
    StorageManager manager;

    // Percorso del file JSON di input
    QString inputFilePath = "/home/marco/Biblioteca/testing_toRemove/input.json";
    // Percorso del file JSON di output
    QString outputFilePath = "/home/marco/Biblioteca/testing_toRemove/output.json";

    // Popola lo storage dal file JSON
    manager.fromFiletoStorage(inputFilePath);

    manager.removeToStorage(2);

    Canzone* cz = new Canzone("Titolo", "PercorsoImg", 2023, 1024, 300, "Artista");
    manager.addToStorage(cz);
    // Stampa il contenuto dello storage su un altro file JSON
    manager.printToFile(outputFilePath);

    qDebug() << "Test completato. Controlla il file di output:" << outputFilePath;
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    testStorageManager();

    return 0;
}