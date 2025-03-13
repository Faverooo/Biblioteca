#ifndef DERIVIEDEDITVISITOR_H
#define DERIVIEDEDITVISITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "../modello_logico/Media.h"
#include "../modello_logico/Libro.h"
#include "../modello_logico/Rivista.h"
#include "../modello_logico/Film.h"
#include "../modello_logico/Canzone.h"
#include "../modello_logico/Album.h"


class AbsEditWidget : public QWidget {
    Q_OBJECT

public:
    explicit AbsEditWidget(QWidget *parent = nullptr);
    virtual ~AbsEditWidget() = default;
    void setTitolo(const QString &titolo);
    void setAnno(const QString &anno);
    void setPercorso(const QString &percorso);
    void setID(const int newID);
    void saveImg();
    virtual Media *getMedia() = 0;

protected:
    QVBoxLayout *layout;
    QLineEdit *LEtitolo;
    QLineEdit *LEanno;
    QLabel *LApercorso;
    QPushButton *selectImageButton;
    QString filePath;
    int id;

private slots:
    void openFileDialog();
};

class LibroEditWidget : public AbsEditWidget {
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

class RivistaEditWidget : public AbsEditWidget {
    Q_OBJECT

public:
    explicit RivistaEditWidget(QWidget *parent = nullptr);

    void setEditore(const QString &newEditore);
    void setPagine(const QString &pagine);
    Media *getMedia();
private:
    QLineEdit *LEeditore;
    QLineEdit *LEpagine;
};


class FilmEditWidget : public AbsEditWidget {
    Q_OBJECT

public:
    explicit FilmEditWidget(QWidget *parent = nullptr);

    void setSize(const QString &size);
    void setDurata(const QString &durata);
    void setRegista(const QString &regista);
    void setLingua(const QString &lingua);
    Media *getMedia();
private:
    QLineEdit *LEsize;
    QLineEdit *LEdurata;
    QLineEdit *LEregista;
    QLineEdit *LElingua;
};


class CanzoneEditWidget : public AbsEditWidget {
    Q_OBJECT

public:
    explicit CanzoneEditWidget(QWidget *parent = nullptr);

    void setSize(const QString &size);
    void setDurata(const QString &durata);
    void setArtista(const QString &artista);
    Media *getMedia();
private:
    QLineEdit *LEsize;
    QLineEdit *LEdurata;
    QLineEdit *LEartista;
};

#endif // DERIVIEDEDITVISITOR_H