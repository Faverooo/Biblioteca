#ifndef DERIVIEDEDITVISITOR_H
#define DERIVIEDEDITVISITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
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

    void setTitolo(const QString &titolo);
    void setAnno(const QString &anno);
    void setPercorso(const QString &percorso);
    void setID(const int newID);

protected:
    QVBoxLayout *layout;
    QLineEdit *LEtitolo;
    QLineEdit *LEanno;
    QLineEdit *LEpercorso;
    QPushButton *selectImageButton;
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

#endif // DERIVIEDEDITVISITOR_H