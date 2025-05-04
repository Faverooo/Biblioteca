#include "JsonVisitor.h"
#include "../modello_logico/Libro.h"
#include "../modello_logico/Rivista.h"
#include "../modello_logico/Film.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"


// VISITOR

void JsonVisitor::visit(Libro *libro)
{
    json = QJsonObject();
    json["tipo"] = "Libro";
    toJsonMT(libro);
    json["autore"] = libro->getAutore();
}

void JsonVisitor::visit(Rivista *rivista)
{
    json = QJsonObject();
    json["tipo"] = "Rivista";
    toJsonMT(rivista);
    json["editore"] = rivista->getEditore();
}

void JsonVisitor::visit(Film *film)
{
    json = QJsonObject();
    json["tipo"] = "Film";
    toJsonMD(film);
    json["regista"] = film->getRegista();
    json["lingua"] = film->getLingua();
}

void JsonVisitor::visit(Canzone *canzone)
{
    json = QJsonObject();
    json["tipo"] = "Canzone";
    toJsonMD(canzone);
    json["artista"] = canzone->getArtista();
}

void JsonVisitor::visit(Album *album)
{
    json = QJsonObject();
    json["tipo"] = "Album";
    toJsonM(album);

    QJsonArray jsonArray;
    for (int id : album->getArchivio())
    {
        jsonArray.append(id);
    }
    json["archivio"] = jsonArray;
}

// ROUTINE DI SUPPORTO

void JsonVisitor::toJsonM(const Media *m)
{
    json["id"] = static_cast<int>(m->getID());
    json["titolo"] = m->getTitolo();
    json["percorsoImg"] = m->getPercorsoImg();
    json["anno"] = m->getAnno();
}

void JsonVisitor::toJsonMT(const MediaTextual *mt)
{
    toJsonM(mt);
    json["pagine"] = mt->getPagine();
}

void JsonVisitor::toJsonMD(const MediaDigital *md)
{
    toJsonM(md);
    json["size"] = static_cast<int>(md->getSize());
    json["durata"] = static_cast<int>(md->getDurata());
}

QJsonObject JsonVisitor::getJsonObj() const
{
    return json;
}