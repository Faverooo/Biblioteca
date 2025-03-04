#include"Rivista.h"


Rivista::Rivista(): MediaTextual(){}

Rivista::Rivista(const QString& titolo, const QString& percorsoImg, int anno, int pagine, int numero, unsigned int id)
    : MediaTextual(titolo, percorsoImg, anno, pagine, id), numero(numero) {}

int Rivista::getNumero() const {
    return numero;
}

void Rivista::setNumero(const int newNumero) {
    numero = newNumero;
}


void Rivista::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}



