#ifndef ALBUM_H
#define ALBUM_H

#include"MediaDigital.h"


class Album: public MediaDigital{
private:
   QString regista;
   QString lingua;
public:
    Album();
    Album(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QString regista, QString lingua, unsigned int id = 0);
    
   
    void acceptVisitor(Visitor* visitor);
    void toJson(QJsonObject& json) const;
    void fromJson(const QJsonObject& json);
    
};


#endif // ALBUM_H