#include"Canzone.h"

Canzone::Canzone(): MediaDigital(){}

Canzone::Canzone(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QString artista, unsigned int id = 0)
    : MediaDigital(titolo, percorsoImg, anno, size, durata, id), artista(artista) {}

QString Canzone::getArtista() const {
    return artista;
}

void Canzone::setArtista(const QString& newArtista) {
    artista = newArtista;
}


void Canzone::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}

void Canzone::toJson(QJsonObject& json) const {
    json = QJsonObject(); //CANCELLO
    json["tipo"] = "Canzone";
    MediaDigital::toJson(json);
    json["artista"] = artista;
}

void Canzone::fromJson(const QJsonObject& json) {
    MediaDigital::fromJson(json);
    if (json.contains("artista") && json["artista"].isString()) {
        artista = json["artista"].toString();
    }
}
