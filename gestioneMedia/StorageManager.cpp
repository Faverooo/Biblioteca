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
#include <QCoreApplication>
#include <QRandomGenerator>

QList<Media *> *StorageManager::getStorage()
{
    return &storage;
}

StorageManager &StorageManager::instance()
{
    static StorageManager instance;
    return instance;
}

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
                        if (json.contains("editore") && json["editore"].isString())
                        {
                            QString editore = json["editore"].toString();
                            ptr = new Rivista(titolo, percorsoImg, anno, pagine, editore, id);
                        }
                    }
                }
            }
            else if (json["tipo"].toString() == "Film" || json["tipo"].toString() == "Canzone")
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
                }
            }
            else if (json["tipo"].toString() == "Album")
            {
                if (json.contains("archivio") && json["archivio"].isArray())
                {
                    QJsonArray jsonArray = json["archivio"].toArray();
                    QList<int> archivio;
                    for (const QJsonValue &value : jsonArray)
                    {
                        archivio.append(value.toInt());
                    }
                    ptr = new Album(titolo, percorsoImg, anno, archivio, id);
                }
            }
        }
        if (ptr != nullptr)
            storage.push_back(ptr);
    }
}

void StorageManager::fromFiletoStorage()
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

    //dopo aver ottenuto un array lo "spezza e salva tutto in memoria"
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

void StorageManager::printToFile()
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qWarning("Couldn't open file.");
        return;
    }

    //genera un array in json da scrivere nel file
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

void StorageManager::addToStorage(Media *media)
{
    storage.push_back(media);
    printToFile();
}

void StorageManager::removeToStorage(int id)
{
    // Trova attraverso l'id e rimuove dalla memoria l'oggetto associato
    for (auto it = storage.begin(); it != storage.end(); ++it)
    {
        if ((*it)->getID() == id)
        {
            // Se l'oggetto è una canzone, rimuovi le sue occorrenze dagli album
            Canzone *canzone = dynamic_cast<Canzone *>(*it);
            if (canzone)
            {
                for (Media *media : storage)
                {
                    Album *album = dynamic_cast<Album *>(media);
                    if (album)
                    {
                        QList<int> archivio = album->getArchivio();
                        if (archivio.contains(id))
                        {
                            archivio.removeAll(id);
                            album->setArchivio(archivio); // Aggiorna l'archivio dell'album
                        }
                    }
                }
            }

            // Rimuovi il file associato
            QString fullPath = QCoreApplication::applicationDirPath() + "/" + (*it)->getPercorsoImg();
            QFile::remove(fullPath);

            // Elimina l'oggetto e rimuovilo dallo storage
            delete *it;
            storage.erase(it);

            // Salva le modifiche sul file
            printToFile();
            return;
        }
    }
}

int StorageManager::generateID() const
{
    int id;
    bool unique;
    do
    {
        id = QRandomGenerator::global()->bounded(1, std::numeric_limits<int>::max());
        unique = true;
        for (const Media *media : storage)
        {
            if (media->getID() == id)
            {
                unique = false;
                break;
            }
        }
    } while (!unique);
    return id;
}

void StorageManager::setPath(const QString &newPath)
{
    path = newPath;
}