#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include"../modello_logico/Media.h"

class StorageManager{
private:
    StorageManager() {} // Costruttore privato
    StorageManager(const StorageManager&) = delete; // Disabilita il costruttore di copia
    StorageManager& operator=(const StorageManager&) = delete; // Disabilita l'operatore di assegnazione
    QString path;
    QList<Media*> storage;
public:
    static StorageManager& instance(); //una sola istanza per tutto il programma
    void fromJOToStorage(const QJsonObject& json);
    void fromFiletoStorage();
    void printToFile();
    void addToStorage(Media* media);
    void removeToStorage(int id);
    int generateID() const;
    QList<Media*>* getStorage();
    void setPath(const QString& newPath);
};



#endif // STORAGEMANAGER_H