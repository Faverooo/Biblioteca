#include"Film.h"

Film::Film(): MediaDigital(){}

Film::Film(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QString regista, QString lingua, unsigned int id = 0)
    : MediaDigital(titolo, percorsoImg, anno, size, durata, id), regista(regista), lingua(lingua) {}

QString Film::getRegista() const {
    return regista;
}

void Film::setRegista(const QString& newRegista) {
    regista = newRegista;
}

QString Film::getLingua() const {
    return lingua;
}

void Film::setLingua(const QString& newLingua) {
    lingua = newLingua;
}

void Film::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}

void Film::toJson(QJsonObject& json) const {
    json = QJsonObject(); //CANCELLO
    json["tipo"] = "Film";
    MediaDigital::toJson(json);
    json["regista"] = regista;
    json["lingua"] = lingua;
}

void Film::fromJson(const QJsonObject& json) {
    MediaDigital::fromJson(json);
    if (json.contains("regista") && json["regista"].isString() &&
        json.contains("lingua") && json["lingua"].isString()) {
        regista = json["regista"].toString();
        lingua = json["lingua"].toString();
    }
}

