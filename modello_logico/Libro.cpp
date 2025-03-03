#include"Libro.h"


Libro::Libro(): MediaTextual(){}

Libro::Libro(const QString& titolo, const QString& percorsoImg, int anno, int pagine, QString autore, unsigned int id = 0)
    : MediaTextual(titolo, percorsoImg, anno, pagine, id), autore(autore) {}

QString Libro::getAutore() const {
    return autore;
}

void Libro::setAutore(const QString& newAutore) {
    autore = newAutore;
}


void Libro::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}

void Libro::toJson(QJsonObject& json) const {
    json["tipo"] = "Libro";
    MediaTextual::toJson(json);
    json["autore"] = autore;
}

void Libro::fromJson(const QJsonObject& json) {
    MediaTextual::fromJson(json);
    autore = json["autore"].toString();
}

