#include"Album.h"
#include<QJsonArray>

Album::Album(): MediaDigital(){}

Album::Album(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QList<int> archivio, unsigned int id)
    : MediaDigital(titolo, percorsoImg, anno, size, durata, id), archivio(archivio) {}

QList<int> Album::getArchivio() const {
    return archivio;
}

void Album::addToArchivio(int id) {
    if (!archivio.contains(id)) {
        archivio.append(id);
    }
}

void Album::removeFromArchivio(int id) {
    archivio.removeAll(id);
}


void Album::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}