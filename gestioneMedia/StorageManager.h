#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include"../modello_logico/Media.h"

class StorageManager{
private:
    StorageManager() = default; // Costruttore privato
    StorageManager(const StorageManager&) = delete; // Disabilita il costruttore di copia
    StorageManager& operator=(const StorageManager&) = delete; // Disabilita l'operatore di assegnazione
    QString path;
    QList<Media*> storage;
public:
    static StorageManager& instance(); //una sola istanza per tutto il programma
    void fromJOToStorage(const QJsonObject& json);
    void fromFiletoStorage(); //da json a memoria, chiama fromJOToStorage per ogni oggetto
    void printToFile() const; //stampa sul file
    void addToStorage(Media* media);
    void removeToStorage(int id);
    int generateID() const; //genera id univoco
    QList<Media*>* getStorage(); //ritorna la qlist di memoria
    void setPath(const QString& newPath); //setta il path del file json
};



#endif // STORAGEMANAGER_H