#include"MediaTextual.h"

MediaTextual::MediaTextual(){}

MediaTextual::MediaTextual(const QString& titolo, const QString& percorsoImg, int anno, int pagine, unsigned int id = 0)
    : Media(titolo, percorsoImg, anno, id), pagine(pagine) {}

int MediaTextual::getPagine() const {
    return pagine;
}

void MediaTextual::setPagine(const int& p) {
    pagine = p;
}


void MediaTextual::toJson(QJsonObject& json) const {
    Media::toJson(json);
    json["pagine"] = pagine;
}

void MediaTextual::fromJson(const QJsonObject& json) {
    Media::fromJson(json);
    if (json.contains("pagine") && json["pagine"].isDouble()) {
        pagine = json["pagine"].toInt();
    }
}