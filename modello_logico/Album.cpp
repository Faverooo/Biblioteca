#include"Album.h"
#include<QJsonArray>

Album::Album() = default;

Album::Album(const QString& titolo, const QString& percorsoImg, int anno, QList<int> archivio, int id)
    : Media (titolo, percorsoImg, anno, id), archivio(archivio) {}

QList<int> Album::getArchivio() const {
    return archivio;
}

void Album::setArchivio(const QList<int>& nuovoArchivio) {
    archivio = nuovoArchivio;
}


QString Album::getFields() const {
    QString allFields = getTitolo() + " " + QString::number(getAnno());
    return allFields;
}

void Album::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}