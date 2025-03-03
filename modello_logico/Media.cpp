#include"Media.h"

Media::Media(){}

Media::Media(const QString& titolo, const QString& percorsoImg, int anno, int id = 0)
    : titolo(titolo), percorsoImg(percorsoImg), anno(anno), id(id) {}

int Media::getID() const {
    return id;
}

void Media::setID(const int& newID) {
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

void Media::setAnno(const int& newAnno) {
    anno = newAnno;
}

void Media::toJson(QJsonObject& json) const {
    json = QJsonObject(); //CANCELLO
    json["id"] = static_cast<int>(id);
    json["titolo"] = titolo;
    json["percorsoImg"] = percorsoImg;
    json["anno"] = anno;
}

void Media::fromJson(const QJsonObject& json) {
    if (json.contains("id") && json["id"].isDouble() &&
        json.contains("titolo") && json["titolo"].isString() &&
        json.contains("percorsoImg") && json["percorsoImg"].isString() &&
        json.contains("anno") && json["anno"].isDouble()) {
        
        id = json["id"].toInt();
        titolo = json["titolo"].toString();
        percorsoImg = json["percorsoImg"].toString();
        anno = json["anno"].toInt();
    }
}
