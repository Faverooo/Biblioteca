#include "DeriviedEditVisitor.h"

#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QCoreApplication>

AbsEditWidget::AbsEditWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("Titolo:", this));
    LEtitolo = new QLineEdit(this);
    layout->addWidget(LEtitolo);

    layout->addWidget(new QLabel("Anno:", this));
    LEanno = new QLineEdit(this);
    layout->addWidget(LEanno);

    layout->addWidget(new QLabel("Percorso:", this));
    LEpercorso = new QLabel(this);
    layout->addWidget(LEpercorso);

    selectImageButton = new QPushButton("Seleziona Immagine", this);
    layout->addWidget(selectImageButton);

    connect(selectImageButton, &QPushButton::clicked, this, &AbsEditWidget::openFileDialog);
}

void AbsEditWidget::setTitolo(const QString &titolo)
{
    LEtitolo->setText(titolo);
}

void AbsEditWidget::setAnno(const QString &anno)
{
    LEanno->setText(anno);
}

void AbsEditWidget::setPercorso(const QString &percorso)
{
    LEpercorso->setText(percorso);
}

void AbsEditWidget::setID(const int newID)
{
    id = newID;
}

void AbsEditWidget::saveImg()
{
    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.exists())
        {
            QDir dir(QCoreApplication::applicationDirPath() + "/salvataggi/immagini");
            if (!dir.exists())
            {
                dir.mkpath(".");
            }
            QString fileName = QFileInfo(filePath).fileName();
            QString newFilePath = dir.filePath(fileName);
            if (!QFile::copy(filePath, newFilePath))
            {
                QMessageBox::warning(this, "Errore", "Impossibile copiare il file.");
            }
            filePath = QString("/salvataggi/immagini/%1").arg(fileName);
        }
    }
}

void AbsEditWidget::openFileDialog()
{
    filePath = QFileDialog::getOpenFileName(this, "Seleziona Immagine", "", "Immagini (*.png *.jpg *.jpeg)");
    LEpercorso->setText(filePath);
}

LibroEditWidget::LibroEditWidget(QWidget *parent) : AbsEditWidget(parent)
{
    layout->addWidget(new QLabel("Autore:", this));
    LEautore = new QLineEdit(this);
    layout->addWidget(LEautore);

    layout->addWidget(new QLabel("Pagine:", this));
    LEpagine = new QLineEdit(this);
    layout->addWidget(LEpagine);
}

void LibroEditWidget::setAutore(const QString &autore)
{
    LEautore->setText(autore);
}

void LibroEditWidget::setPagine(const QString &pagine)
{
    LEpagine->setText(pagine);
}

Media *LibroEditWidget::getMedia()
{
    Libro *libro = new Libro();
    libro->setTitolo(LEtitolo->text());
    libro->setAnno(LEanno->text().toInt());
    libro->setPercorsoImg(LEpercorso->text());
    libro->setAutore(LEautore->text());
    libro->setPagine(LEpagine->text().toInt());
    libro->setID(id);
    return libro;
}

RivistaEditWidget::RivistaEditWidget(QWidget *parent) : AbsEditWidget(parent)
{
    layout->addWidget(new QLabel("Editore:", this));
    LEeditore = new QLineEdit(this);
    layout->addWidget(LEeditore);

    layout->addWidget(new QLabel("Pagine:", this));
    LEpagine = new QLineEdit(this);
    layout->addWidget(LEpagine);
}

void RivistaEditWidget::setEditore(const QString &newEditore)
{
    LEeditore->setText(newEditore);
}

void RivistaEditWidget::setPagine(const QString &pagine)
{
    LEpagine->setText(pagine);
}

Media *RivistaEditWidget::getMedia()
{
    Rivista *rivista = new Rivista();
    rivista->setTitolo(LEtitolo->text());
    rivista->setAnno(LEanno->text().toInt());
    rivista->setPercorsoImg(LEpercorso->text());
    rivista->setEditore(LEeditore->text());
    rivista->setPagine(LEpagine->text().toInt());
    rivista->setID(id);
    return rivista;
}
