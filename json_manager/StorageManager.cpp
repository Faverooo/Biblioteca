#include "StorageManager.h"
#include "../modello_logico/Libro.h"
#include "../modello_logico/Rivista.h"
#include "../modello_logico/Film.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"
#include<QJsonArray>

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
                            if (json.contains("artista") && json["artista"].isString()) {
                                QString artista = json["artista"].toString();
                                ptr = new Canzone(titolo, percorsoImg, anno, size, durata, artista, id);
                            }
                        }
                        else
                        {
                            if (json.contains("archivio") && json["archivio"].isArray()) {
                                QJsonArray jsonArray = json["archivio"].toArray();
                                QList<int> archivio;
                                for (const QJsonValue& value : jsonArray) {
                                    archivio.append(value.toInt());
                                }
                                ptr = new Album(titolo, percorsoImg, anno, size, durata, archivio, id);
                            }
                        }
                    }
                }
            }
        }
        if(ptr!=nullptr)
            storage.push_back(ptr);
    }
}