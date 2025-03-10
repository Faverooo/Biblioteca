#ifndef DERIVIEDEDITVISITOR_H
#define DERIVIEDEDITVISITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include "../modello_logico/Media.h"
#include "../modello_logico/Libro.h"
#include "../modello_logico/Rivista.h"
#include "../modello_logico/Film.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"

class AbsEditWidget : public QWidget
{
    Q_OBJECT

protected:
    int id;
    QLineEdit *LEtitolo;
    QLineEdit *LEanno;
    QLineEdit *LEpercorso;

    QVBoxLayout *layout;

public:
    explicit AbsEditWidget(QWidget *parent = nullptr);
    virtual ~AbsEditWidget() = default;
    virtual Media *getMedia() = 0;
    void setTitolo(const QString &titolo);
    void setAnno(const QString &anno);
    void setPercorso(const QString &percorso);
    void setID(const int newID);
};

class LibroEditWidget : public AbsEditWidget
{
    Q_OBJECT

public:
    explicit LibroEditWidget(QWidget *parent = nullptr);
    void setAutore(const QString &autore);
    void setPagine(const QString &pagine);
    Media *getMedia();

private:
    QLineEdit *LEautore;
    QLineEdit *LEpagine;
};

#endif // DERIVIEDEDITVISITOR_H