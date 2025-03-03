#include"Rivista.h"


Rivista::Rivista(): MediaTextual(){}

Rivista::Rivista(const QString& titolo, const QString& percorsoImg, int anno, int pagine, int numero, unsigned int id = 0)
    : MediaTextual(titolo, percorsoImg, anno, pagine, id), numero(numero) {}

int Rivista::getNumero() const {
    return numero;
}

void Rivista::setNumero(const int& newNumero) {
    numero = newNumero;
}


void Rivista::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}

void Rivista::toJson(QJsonObject& json) const {
    json["tipo"] = "Rivista";
    MediaTextual::toJson(json);
    json["numero"] = numero;
}

void Rivista::fromJson(const QJsonObject& json) {
    MediaTextual::fromJson(json);
    numero = json["numero"].toInt();
}

