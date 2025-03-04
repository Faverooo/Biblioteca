#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include"../modello_logico/Media.h"

class StorageManager{
private:
    QList<Media*> storage;
public:
    void fromJOToStorage(const QJsonObject& json);
    void fromFiletoStorage(const QString& path);
};



#endif // STORAGEMANAGER_H