#ifndef CANZONE_H
#define CANZONE_H

#include"MediaDigital.h"


class Canzone: public MediaDigital{
private:
   QString artista;
public:
    Canzone();
    Canzone(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QString artista, unsigned int id = 0);
    QString getArtista() const;
    void setArtista(const QString& newArtista);
   
    void acceptVisitor(Visitor* visitor);
    void toJson(QJsonObject& json) const;
    void fromJson(const QJsonObject& json);
    
};


#endif // CANZONE_H