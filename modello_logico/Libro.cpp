#include"Libro.h"


Libro::Libro(): MediaTextual(){}

Libro::Libro(const QString& titolo, const QString& percorsoImg, int anno, int pagine, QString& autore, unsigned int id)
    : MediaTextual(titolo, percorsoImg, anno, pagine, id), autore(autore) {}

QString Libro::getAutore() const {
    return autore;
}

void Libro::setAutore(const QString& newAutore) {
    autore = newAutore;
}

QString Libro::getFields() const {
    QString allFields =  getTitolo() + " " + QString::number(getAnno()) + " " + getAutore() + " " + QString::number(getPagine());
    return allFields;
}

void Libro::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}

