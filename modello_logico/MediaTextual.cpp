#include"MediaTextual.h"

MediaTextual::MediaTextual() = default;

MediaTextual::MediaTextual(const QString& titolo, const QString& percorsoImg, int anno, unsigned int pagine, int id)
    : Media(titolo, percorsoImg, anno, id), pagine(pagine) {}

unsigned int MediaTextual::getPagine() const {
    return pagine;
}

void MediaTextual::setPagine(const unsigned int p) {
    pagine = p;
}


