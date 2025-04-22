#include"Canzone.h"

Canzone::Canzone(): MediaDigital(){}

Canzone::Canzone(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QString artista, unsigned int id)
    : MediaDigital(titolo, percorsoImg, anno, size, durata, id), artista(artista) {}

QString Canzone::getArtista() const {
    return artista;
}

void Canzone::setArtista(const QString& newArtista) {
    artista = newArtista;
}

QString Canzone::getFields() const {
    QString allFields = getTitolo() + " " + QString::number(getAnno()) + " " + artista + " " + QString::number(getDurata()) + " " + QString::number(getSize());
    return allFields;
}

void Canzone::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}