#ifndef ALBUM_H
#define ALBUM_H

#include"Media.h"

class Album: public Media{
private:
   QList<int> archivio;
public:
    Album();
    Album(const QString& titolo, const QString& percorsoImg, int anno, QList<int> archivio, int id = 0);
    
    QList<int> getArchivio() const;//interi univoci (ID) che possono essere salvati in json, equivalente di puntatori
    void setArchivio(const QList<int>& nuovoArchivio);

    QString getFields() const; 
    void acceptVisitor(Visitor* visitor);    
};


#endif // ALBUM_H