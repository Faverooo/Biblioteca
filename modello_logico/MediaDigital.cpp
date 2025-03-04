#include"MediaDigital.h"

MediaDigital::MediaDigital(){}

MediaDigital::MediaDigital(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, unsigned int id = 0)
    : Media(titolo, percorsoImg, anno, id), size(size), durata(durata) {}

    unsigned int MediaDigital::getSize() const {
        return size;
    }

    void MediaDigital::setSize(unsigned int newSize) {
        size = newSize;
    }

    unsigned int MediaDigital::getDurata() const {
        return durata;
    }

    void MediaDigital::setDurata(unsigned int newDurata) {
        durata = newDurata;
    }


void MediaDigital::toJson(QJsonObject& json) const {
    Media::toJson(json);
    json["size"] = static_cast<int>(size);
    json["durata"] = static_cast<int>(durata);
}

void MediaDigital::fromJson(const QJsonObject& json) {
    Media::fromJson(json);
    if (json.contains("size") && json["size"].isDouble() && json.contains("durata") && json["durata"].isDouble()) {
        size = json["size"].toInt();
        durata = json["durata"].toInt();
    }
}