#ifndef MEDIADIGITAL_H
#define MEDIADIGITAL_H

#include"Media.h"


class MediaDigital: public Media {
private:
    unsigned int size;
    unsigned int durata;
public:
    MediaDigital();
    MediaDigital(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, int id = 0);

    //in MB
    unsigned int getSize() const;
    void setSize(unsigned int newSize);
    
    unsigned int getDurata() const;
    void setDurata(unsigned int newDurata);

};


#endif // MEDIADIGITAL_H