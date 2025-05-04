#ifndef JSONVISIOR_H
#define JSONVISIOR_H

#include"../visitor/Visitor.h"
#include<QJsonObject>
#include<QJsonArray>
class Media;
class MediaTextual;
class MediaDigital;

class JsonVisitor: public Visitor {
private:
    QJsonObject json;
public:
    void visit(Libro *libro);
    void visit(Rivista *rivista);
    void visit(Film *film);
    void visit(Canzone *canzone);
    void visit(Album *album);

    //metodi chiamati dai visitor
    void toJsonM(const Media* m);
    void toJsonMT(const MediaTextual* mt);
    void toJsonMD(const MediaDigital* md);

    //getter
    QJsonObject getJsonObj() const;
};

#endif // JSONVISIOR_H