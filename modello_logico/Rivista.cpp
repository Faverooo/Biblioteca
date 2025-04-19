#include"Rivista.h"


Rivista::Rivista(): MediaTextual(){}

Rivista::Rivista(const QString& titolo, const QString& percorsoImg, int anno, int pagine, QString& editore, unsigned int id)
    : MediaTextual(titolo, percorsoImg, anno, pagine, id), editore(editore) {}

QString Rivista::getEditore() const {
    return editore;
}

void Rivista::setEditore(const QString& newEditore) {
    editore = newEditore;
}

QStringList Rivista::getFields() const {
    return { getTitolo(), QString::number(getAnno()), getEditore(), QString::number(getPagine())};
}

void Rivista::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}



