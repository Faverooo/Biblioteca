#ifndef MEDIATEXTUAL_H
#define MEDIATEXTUAL_H

#include"Media.h"


class MediaTextual: public Media{
private:
   unsigned int pagine;
public:
    MediaTextual();
    MediaTextual(const QString& titolo, const QString& percorsoImg, int anno, unsigned int pagine, int id = 0);

    unsigned int getPagine() const;
    void setPagine(const unsigned int p);

};


#endif // MEDIATEXTUAL_H