#ifndef LIBRO_H
#define LIBRO_H

#include"MediaTextual.h"


class Libro: public MediaTextual{
private:
   QString autore;
public:
    Libro();
    Libro(const QString& titolo, const QString& percorsoImg, int anno, int pagine, QString& autore, unsigned int id = 0);
    QString getAutore() const;
    void setAutore(const QString& newAutore);
   
    void acceptVisitor(Visitor* visitor);   
    QString getFields() const; 
};


#endif // LIBRO_H