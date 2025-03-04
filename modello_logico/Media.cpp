#include"Media.h"

Media::Media(){}

Media::Media(const QString& titolo, const QString& percorsoImg, int anno, int id)
    : titolo(titolo), percorsoImg(percorsoImg), anno(anno), id(id) {}

Media::~Media(){}

int Media::getID() const {
    return id;
}

void Media::setID(const int newID) {
    id = newID;
}

QString Media::getTitolo() const {
    return titolo;
}

void Media::setTitolo(const QString& newTitolo) {
    titolo = newTitolo;
}

QString Media::getPercorsoImg() const {
    return percorsoImg;
}

void Media::setPercorsoImg(const QString& newPercorsoImg) {
    percorsoImg = newPercorsoImg;
}

int Media::getAnno() const {
    return anno;
}

void Media::setAnno(const int newAnno) {
    anno = newAnno;
}
