#include "JsonVisitor.h"
#include "../modello_logico/Libro.h"
#include "../modello_logico/Rivista.h"
#include "../modello_logico/Film.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"

void JsonVisitor::visit(Libro *libro) {
    json = QJsonObject();
}

void JsonVisitor::visit(Rivista *rivista) {
    // Implementation goes here
}

void JsonVisitor::visit(Film *film) {
    // Implementation goes here
}

void JsonVisitor::visit(Canzone *canzone) {
    // Implementation goes here
}

void JsonVisitor::visit(Album *album) {
    // Implementation goes here
}

void JsonVisitor::toJsonM(Media* m) {
    json["id"] = static_cast<int>(m->getID());
    json["titolo"] = m->getTitolo();
    json["percorsoImg"] = m->getPercorsoImg();
    json["anno"] = m->getAnno();
}

void JsonVisitor::toJsonMT(MediaTextual* mt) {
    toJsonM(mt);
    json["pagine"] = mt->getPagine();
}

void JsonVisitor::toJsonMD(MediaDigital* md) {
    toJsonM(md);
    json["size"] = static_cast<int>(md->getSize());
    json["durata"] = static_cast<int>(md->getDurata());
}