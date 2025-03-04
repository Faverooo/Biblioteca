#ifndef ALBUM_H
#define ALBUM_H

#include"MediaDigital.h"


class Album: public MediaDigital{
private:
   QList<int> archivio;
public:
    Album();
    Album(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QList<int> archivio, unsigned int id = 0);
    
    QList<int> getArchivio() const;
    void addToArchivio(int id);
    void removeFromArchivio(int id);

   
    void acceptVisitor(Visitor* visitor);
    void toJson(QJsonObject& json) const;
    void fromJson(const QJsonObject& json);
    
};


#endif // ALBUM_H