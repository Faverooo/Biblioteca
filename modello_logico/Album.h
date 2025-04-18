#ifndef ALBUM_H
#define ALBUM_H

#include"Media.h"

class Album: public Media{
private:
   QList<int> archivio;
public:
    Album();
    Album(const QString& titolo, const QString& percorsoImg, int anno, QList<int> archivio, unsigned int id = 0);
    
    //interi univoci (ID) che possono essere salvati in json, equivalente di puntatori
    QList<int> getArchivio() const;
    void setArchivio(const QList<int>& nuovoArchivio);
    // void addToArchivio(int id);
    // void removeFromArchivio(int id);

   
    void acceptVisitor(Visitor* visitor);    
};


#endif // ALBUM_H