#ifndef MEDIA_H
#define MEDIA_H

#include<QString>
#include<QJsonObject>
#include "../visitor/Visitor.h"

class Media {
private:
    QString titolo;
    QString percorsoImg;
    int anno;
    int id;
public:
    Media();
    Media(const QString& titolo, const QString& percorsoImg, int anno, int id = 0);

    int getID() const;
    void setID(const int newID);

    QString getTitolo() const;
    void setTitolo(const QString& newTitolo);

    QString getPercorsoImg() const;
    void setPercorsoImg(const QString& newPercorsoImg);

    int getAnno() const;
    void setAnno(const int newAnno);

    virtual void acceptVisitor(Visitor* visitor) = 0;
    virtual void toJson(QJsonObject& json) const;
    virtual void fromJson(const QJsonObject& json);
};


#endif // MEDIA_H