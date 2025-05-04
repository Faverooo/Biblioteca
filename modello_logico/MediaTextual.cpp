#include"MediaTextual.h"

MediaTextual::MediaTextual() = default;

MediaTextual::MediaTextual(const QString& titolo, const QString& percorsoImg, int anno, int pagine, unsigned int id)
    : Media(titolo, percorsoImg, anno, id), pagine(pagine) {}

int MediaTextual::getPagine() const {
    return pagine;
}

void MediaTextual::setPagine(const int p) {
    pagine = p;
}


