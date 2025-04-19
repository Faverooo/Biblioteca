#ifndef FILM_H
#define FILM_H

#include"MediaDigital.h"


class Film: public MediaDigital{
private:
   QString regista;
   QString lingua;
public:
    Film();
    Film(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QString regista, QString lingua, unsigned int id = 0);
    QString getRegista() const;
    void setRegista(const QString& newRegista);
    QString getLingua() const;
    void setLingua(const QString& newLingua);
   
    QStringList getFields() const; 
    void acceptVisitor(Visitor* visitor);    
};


#endif // FILM_H