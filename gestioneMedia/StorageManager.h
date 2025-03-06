#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include"../modello_logico/Media.h"

class StorageManager{
private:
    QList<Media*> storage;
public:
    void fromJOToStorage(const QJsonObject& json);
    void fromFiletoStorage(const QString& path);
    void printToFile(const QString& path);
    void addToStorage(Media* media);
    void removeToStorage(int id);
    int generateID() const;
};



#endif // STORAGEMANAGER_H