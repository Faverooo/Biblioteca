#include"Rivista.h"


Rivista::Rivista() = default;

Rivista::Rivista(const QString& titolo, const QString& percorsoImg, int anno, int pagine, const QString& editore, unsigned int id)
    : MediaTextual(titolo, percorsoImg, anno, pagine, id), editore(editore) {}

QString Rivista::getEditore() const {
    return editore;
}

void Rivista::setEditore(const QString& newEditore) {
    editore = newEditore;
}

QString Rivista::getFields() const {
    QString allFields = getTitolo() + " " + QString::number(getAnno()) + " " + getEditore() + " " + QString::number(getPagine());
    return allFields;
}

void Rivista::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}



