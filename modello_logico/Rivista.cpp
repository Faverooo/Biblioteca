#include"Rivista.h"


Rivista::Rivista(): MediaTextual(){}

Rivista::Rivista(const QString& titolo, const QString& percorsoImg, int anno, int pagine, QString& editore, unsigned int id)
    : MediaTextual(titolo, percorsoImg, anno, pagine, id), editore(editore) {}

QString Rivista::getEditore() const {
    return editore;
}

void Rivista::setEditore(QString& newEditore) {
    editore = newEditore;
}


void Rivista::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}



