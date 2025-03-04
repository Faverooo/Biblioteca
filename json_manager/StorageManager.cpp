#include "StorageManager.h"
#include "../modello_logico/Libro.h"
#include "../modello_logico/Rivista.h"
#include "../modello_logico/Film.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"
#include "JsonVisitor.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

void StorageManager::fromJOToStorage(const QJsonObject &json)
{
    if (json.contains("tipo") && json["tipo"].isString())
    {
        Media *ptr = nullptr;

        if (json.contains("id") && json["id"].isDouble() &&
            json.contains("titolo") && json["titolo"].isString() &&
            json.contains("percorsoImg") && json["percorsoImg"].isString() &&
            json.contains("anno") && json["anno"].isDouble())
        {

            int id = json["id"].toInt();
            QString titolo = json["titolo"].toString();
            QString percorsoImg = json["percorsoImg"].toString();
            int anno = json["anno"].toInt();

            if (json["tipo"].toString() == "Libro" || json["tipo"].toString() == "Rivista")
            {
                if (json.contains("pagine") && json["pagine"].isDouble())
                {
                    int pagine = json["pagine"].toInt();

                    if (json["tipo"].toString() == "Libro")
                    {
                        if (json.contains("autore") && json["autore"].isString())
                        {
                            QString autore = json["autore"].toString();
                            ptr = new Libro(titolo, percorsoImg, anno, pagine, autore, id);
                        }
                    }
                    else
                    {
                        if (json.contains("numero") && json["numero"].isDouble())
                        {
                            int numero = json["numero"].toInt();
                            ptr = new Rivista(titolo, percorsoImg, anno, pagine, numero, id);
                        }
                    }
                }
            }
            else
            {
                if (json["tipo"].toString() == "Film" || json["tipo"].toString() == "Canzone" || json["tipo"].toString() == "Album")
                {
                    if (json.contains("size") && json["size"].isDouble() && json.contains("durata") && json["durata"].isDouble())
                    {
                        unsigned int size = json["size"].toInt();
                        unsigned int durata = json["durata"].toInt();

                        if (json["tipo"].toString() == "Film")
                        {
                            if (json.contains("regista") && json["regista"].isString() && json.contains("lingua") && json["lingua"].isString())
                            {
                                QString regista = json["regista"].toString();
                                QString lingua = json["lingua"].toString();
                                ptr = new Film(titolo, percorsoImg, anno, size, durata, regista, lingua, id);
                            }
                        }
                        else if (json["tipo"].toString() == "Canzone")
                        {
                            if (json.contains("artista") && json["artista"].isString())
                            {
                                QString artista = json["artista"].toString();
                                ptr = new Canzone(titolo, percorsoImg, anno, size, durata, artista, id);
                            }
                        }
                        else
                        {
                            if (json.contains("archivio") && json["archivio"].isArray())
                            {
                                QJsonArray jsonArray = json["archivio"].toArray();
                                QList<int> archivio;
                                for (const QJsonValue &value : jsonArray)
                                {
                                    archivio.append(value.toInt());
                                }
                                ptr = new Album(titolo, percorsoImg, anno, size, durata, archivio, id);
                            }
                        }
                    }
                }
            }
        }
        if (ptr != nullptr)
            storage.push_back(ptr);
    }
}

void StorageManager::fromFiletoStorage(const QString &path)
{
    storage.clear();

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning("Couldn't open file.");
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument doc(QJsonDocument::fromJson(fileData));
    if (!doc.isArray())
    {
        qWarning("Invalid JSON document. Expected an array of objects.");
        return;
    }

    QJsonArray jsonArray = doc.array();
    for (const QJsonValue &value : jsonArray)
    {
        if (value.isObject())
        {
            QJsonObject jsonObject = value.toObject();
            fromJOToStorage(jsonObject);
        }
        else
        {
            qWarning("Invalid JSON element. Expected an object.");
        }
    }
}

void StorageManager::printToFile(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qWarning("Couldn't open file.");
        return;
    }

    QJsonArray jsonArray;
    for (Media *media : storage)
    {
        QJsonObject jsonObject;
        JsonVisitor jsonvisitor;
        media->acceptVisitor(&jsonvisitor);
        jsonObject = jsonvisitor.getJsonObj();
        jsonArray.append(jsonObject);
    }

    QJsonDocument doc(jsonArray);
    file.write(doc.toJson());
    file.close();
}


void StorageManager::addToStorage(Media &media)
{
    storage.push_back(&media);
}

void StorageManager::removeToStorage(int id)
{
    for (auto it = storage.begin(); it != storage.end(); ++it)
    {
        if ((*it)->getID() == id)
        {
            delete *it;
            storage.erase(it);
            return;
        }
    }
}