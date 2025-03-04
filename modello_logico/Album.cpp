#include"Album.h"
#include<QJsonArray>

Album::Album(): MediaDigital(){}

Album::Album(const QString& titolo, const QString& percorsoImg, int anno, unsigned int size, unsigned int durata, QList<int> archivio, unsigned int id = 0)
    : MediaDigital(titolo, percorsoImg, anno, size, durata, id), archivio(archivio) {}

QList<int> Album::getArchivio() const {
    return archivio;
}

void Album::addToArchivio(int id) {
    if (!archivio.contains(id)) {
        archivio.append(id);
    }
}

void Album::removeFromArchivio(int id) {
    archivio.removeAll(id);
}


void Album::acceptVisitor(Visitor* visitor) {
    visitor->visit(this);
}

void Album::toJson(QJsonObject& json) const {
    json = QJsonObject(); //CANCELLO
    json["tipo"] = "Album";
    MediaDigital::toJson(json);

    QJsonArray jsonArray;
    for (int id : archivio) {
        jsonArray.append(id);
    }
    json["archivio"] = jsonArray;
}

void Album::fromJson(const QJsonObject& json) {
    MediaDigital::fromJson(json);

    if (json.contains("archivio") && json["archivio"].isArray()) {
        QJsonArray jsonArray = json["archivio"].toArray();
        archivio.clear();
        for (const QJsonValue& value : jsonArray) {
            archivio.append(value.toInt());
        }
    }
}
