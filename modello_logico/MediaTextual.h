#ifndef MEDIATEXTUAL_H
#define MEDIATEXTUAL_H

#include"Media.h"


class MediaTextual: public Media{
private:
   int pagine;
public:
    MediaTextual();
    MediaTextual(const QString& titolo, const QString& percorsoImg, int anno, int pagine, unsigned int id = 0);

    int getPagine() const;
    void setPagine(const int p);

};


#endif // MEDIATEXTUAL_H