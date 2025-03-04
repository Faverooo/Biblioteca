#ifndef RIVISTA_H
#define RIVISTA_H

#include"MediaTextual.h"


class Rivista: public MediaTextual{
private:
   int numero;
public:
    Rivista();
    Rivista(const QString& titolo, const QString& percorsoImg, int anno, int pagine, int numero, unsigned int id = 0);
    int getNumero() const;
    void setNumero(const int newAutore);
   
    void acceptVisitor(Visitor* visitor);
};

#endif // RIVISTA_H