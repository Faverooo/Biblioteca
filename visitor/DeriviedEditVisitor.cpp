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

    layout->addWidget(new QLabel("Percorso immagine:", this));
    LApercorso = new QLabel(this);
    layout->addWidget(LApercorso);

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
    LApercorso->setText(percorso);
    filePath=percorso;
}

QString AbsEditWidget::getPercorso() const
{
    return filePath;
}

void AbsEditWidget::setID(const int newID)
{
    id = newID;
}

void AbsEditWidget::saveImg()
{
    // Controlla se il percorso del file non è vuoto
    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        // Verifica se il file esiste
        if (file.exists())
        {
            // Crea la directory di destinazione se non esiste
            QDir dir(QCoreApplication::applicationDirPath() + "/salvataggi/immagini");
            if (!dir.exists())
            {
                dir.mkpath(".");
            }
            // Ottiene il nome del file e costruisce il nuovo percorso
            QString fileName = QFileInfo(filePath).fileName();
            QString newFilePath = dir.filePath(fileName);
            int counter = 1;
            // Gestisce i conflitti di nomi aggiungendo un suffisso numerico
            while (QFile::exists(newFilePath))
            {
                QString baseName = QFileInfo(fileName).completeBaseName();
                QString extension = QFileInfo(fileName).suffix();
                newFilePath = dir.filePath(QString("%1_%2.%3").arg(baseName).arg(counter).arg(extension));
                counter++;
            }
            // Copia il file nella nuova posizione e gestisce eventuali errori
            if (!QFile::copy(filePath, newFilePath))
            {
                QMessageBox::warning(this, "Errore", "Impossibile copiare il file.");
            }
            // Aggiorna il percorso del file con il nuovo percorso relativo
            filePath = QString("salvataggi/immagini/%1").arg(QFileInfo(newFilePath).fileName());
        }
    }
}

void AbsEditWidget::openFileDialog()
{
    filePath = QFileDialog::getOpenFileName(this, "Seleziona Immagine", "", "Immagini (*.png *.jpg *.jpeg)");
    LApercorso->setText(filePath);
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
    if (LEtitolo->text().isEmpty() || LEanno->text().isEmpty() || filePath.isEmpty() || LEautore->text().isEmpty() || LEpagine->text().isEmpty())
        return nullptr;
    Libro *libro = new Libro();
    libro->setTitolo(LEtitolo->text());
    libro->setAnno(LEanno->text().toInt());
    libro->setPercorsoImg(filePath);
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
    if (LEtitolo->text().isEmpty() || LEanno->text().isEmpty() || filePath.isEmpty() || LEeditore->text().isEmpty() || LEpagine->text().isEmpty())
        return nullptr;
    Rivista *rivista = new Rivista();
    rivista->setTitolo(LEtitolo->text());
    rivista->setAnno(LEanno->text().toInt());
    rivista->setPercorsoImg(filePath);
    rivista->setEditore(LEeditore->text());
    rivista->setPagine(LEpagine->text().toInt());
    rivista->setID(id);
    return rivista;
}


FilmEditWidget::FilmEditWidget(QWidget *parent) : AbsEditWidget(parent)
{
    layout->addWidget(new QLabel("Dimensione (MB):", this));
    LEsize = new QLineEdit(this);
    layout->addWidget(LEsize);

    layout->addWidget(new QLabel("Durata (min):", this));
    LEdurata = new QLineEdit(this);
    layout->addWidget(LEdurata);

    layout->addWidget(new QLabel("Regista:", this));
    LEregista = new QLineEdit(this);
    layout->addWidget(LEregista);

    layout->addWidget(new QLabel("Lingua:", this));
    LElingua = new QLineEdit(this);
    layout->addWidget(LElingua);
}

void FilmEditWidget::setSize(const QString &size)
{
    LEsize->setText(size);
}

void FilmEditWidget::setDurata(const QString &durata)
{
    LEdurata->setText(durata);
}

void FilmEditWidget::setRegista(const QString &regista)
{
    LEregista->setText(regista);
}

void FilmEditWidget::setLingua(const QString &lingua)
{
    LElingua->setText(lingua);
}

Media *FilmEditWidget::getMedia()
{
    if (LEtitolo->text().isEmpty() || LEanno->text().isEmpty() || filePath.isEmpty() || LEsize->text().isEmpty() || LEdurata->text().isEmpty() || LEregista->text().isEmpty() || LElingua->text().isEmpty())
        return nullptr;
    Film *film = new Film();
    film->setTitolo(LEtitolo->text());
    film->setAnno(LEanno->text().toInt());
    film->setPercorsoImg(filePath);
    film->setSize(LEsize->text().toInt());
    film->setDurata(LEdurata->text().toInt());
    film->setRegista(LEregista->text());
    film->setLingua(LElingua->text());
    film->setID(id);
    return film;
}

CanzoneEditWidget::CanzoneEditWidget(QWidget *parent) : AbsEditWidget(parent)
{
    layout->addWidget(new QLabel("Dimensione (MB):", this));
    LEsize = new QLineEdit(this);
    layout->addWidget(LEsize);

    layout->addWidget(new QLabel("Durata (sec):", this));
    LEdurata = new QLineEdit(this);
    layout->addWidget(LEdurata);

    layout->addWidget(new QLabel("Artista:", this));
    LEartista = new QLineEdit(this);
    layout->addWidget(LEartista);
}

void CanzoneEditWidget::setSize(const QString &size)
{
    LEsize->setText(size);
}

void CanzoneEditWidget::setDurata(const QString &durata)
{
    LEdurata->setText(durata);
}

void CanzoneEditWidget::setArtista(const QString &artista)
{
    LEartista->setText(artista);
}

Media *CanzoneEditWidget::getMedia()
{
    if (LEtitolo->text().isEmpty() || LEanno->text().isEmpty() || filePath.isEmpty() || LEsize->text().isEmpty() || LEdurata->text().isEmpty() || LEartista->text().isEmpty())
        return nullptr;
    Canzone *canzone = new Canzone();
    canzone->setTitolo(LEtitolo->text());
    canzone->setAnno(LEanno->text().toInt());
    canzone->setPercorsoImg(filePath);
    canzone->setSize(LEsize->text().toInt());
    canzone->setDurata(LEdurata->text().toInt());
    canzone->setArtista(LEartista->text());
    canzone->setID(id);
    return canzone;
}



AlbumEditWidget::AlbumEditWidget(QWidget *parent) : AbsEditWidget(parent) {
    manageSongsButton = new QPushButton("Gestisci Canzoni", this);
    layout->addWidget(manageSongsButton);

    connect(manageSongsButton, &QPushButton::clicked, this, &AlbumEditWidget::openSongSelectionDialog);
}

void AlbumEditWidget::openSongSelectionDialog() { //apre e modifica l'archivio del nuovo media tramite riferimento
    SongSelectionDialog dialog(archivio, this);
    dialog.exec();
}

void AlbumEditWidget::setArchivio(const QList<int> &newArchivio)
{
    archivio = newArchivio;
}

Media *AlbumEditWidget::getMedia() //media aggiornato
{
    if (LEtitolo->text().isEmpty() || LEanno->text().isEmpty() || filePath.isEmpty() )
        return nullptr;
    Album *album = new Album();
    album->setTitolo(LEtitolo->text());
    album->setAnno(LEanno->text().toInt());
    album->setPercorsoImg(filePath);
    album->setID(id);
    album->setArchivio(archivio);
    return album;
}