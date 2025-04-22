#include"Film.h"

Film::Film(): MediaDigital(){}

Film::Film(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QString regista, QString lingua, unsigned int id)
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

QString Film::getFields() const {
    QString allFields = getTitolo() + " " + QString::number(getAnno()) + " " + regista + " " + lingua + " " + QString::number(getDurata()) + " " + QString::number(getSize());
    return allFields;
}

void Film::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}
