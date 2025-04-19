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
    virtual ~Media();

    //id univoco
    int getID() const;
    void setID(const int newID);

    QString getTitolo() const;
    void setTitolo(const QString& newTitolo);

    //percorso che deve essere relativo
    QString getPercorsoImg() const;
    void setPercorsoImg(const QString& newPercorsoImg);

    int getAnno() const;
    void setAnno(const int newAnno);

    virtual QStringList getFields() const = 0;
    virtual void acceptVisitor(Visitor* visitor) = 0;
};


#endif // MEDIA_H