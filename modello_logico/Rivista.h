#ifndef RIVISTA_H
#define RIVISTA_H

#include"MediaTextual.h"


class Rivista: public MediaTextual{
private:
    QString editore;
public:
    Rivista();
    Rivista(const QString& titolo, const QString& percorsoImg, int anno, int pagine, QString& editore, unsigned int id = 0);
    QString getEditore() const;
    void setEditore(const QString& newEditore);
   
    QStringList getFields() const; 
    void acceptVisitor(Visitor* visitor);
};

#endif // RIVISTA_H