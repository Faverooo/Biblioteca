#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include"../modello_logico/Media.h"

class StorageManager{
private:
    StorageManager() {} // Costruttore privato
    StorageManager(const StorageManager&) = delete; // Disabilita il costruttore di copia
    StorageManager& operator=(const StorageManager&) = delete; // Disabilita l'operatore di assegnazione
    QList<Media*> storage;
public:
    static StorageManager& instance();
    void fromJOToStorage(const QJsonObject& json);
    void fromFiletoStorage(const QString& path);
    void printToFile(const QString& path);
    void addToStorage(Media* media);
    void removeToStorage(int id);
    int generateID() const;
    QList<Media*> getStorage() const;
};



#endif // STORAGEMANAGER_H