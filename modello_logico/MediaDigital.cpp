#include"MediaDigital.h"

MediaDigital::MediaDigital(){}

MediaDigital::MediaDigital(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, unsigned int id)
    : Media(titolo, percorsoImg, anno, id), size(size), durata(durata) {}

    unsigned int MediaDigital::getSize() const {
        return size;
    }

    void MediaDigital::setSize(unsigned int newSize) {
        size = newSize;
    }

    unsigned int MediaDigital::getDurata() const {
        return durata;
    }

    void MediaDigital::setDurata(unsigned int newDurata) {
        durata = newDurata;
    }
