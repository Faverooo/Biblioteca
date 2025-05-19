#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(800, 500); // Larghezza: 1200, Altezza: 800
    setMinimumSize(600, 400); // Imposta la dimensione minima

    stackedWidget = new QStackedWidget(this);
    QWidget *headerWidget = new QWidget(this);
    headerWidget->setStyleSheet("background-color:rgb(166, 250, 140); border: 2px solid rgb(3, 85, 34); border-radius: 10px;");

    // Imposta il layout orizzontale per l'intestazione
    QHBoxLayout *headerLayout = new QHBoxLayout(headerWidget);
    QLabel *titleLabel = new QLabel("MyArchive", headerWidget);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: rgb(3, 85, 34); border: 0px; padding: 5px;");
    titleLabel->setAlignment(Qt::AlignCenter);
    QPushButton *exitButton = new QPushButton("Exit", headerWidget);
    exitButton->setStyleSheet("padding: 10px;");
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(exitButton);
    headerWidget->setFixedHeight(this->height() * 0.12);

    // Imposta il layout principale per il contenuto
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(headerWidget);
    mainLayout->addWidget(stackedWidget);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(exitButton, &QPushButton::clicked, this, &QMainWindow::close);
    
    //aggiunta per le varie view
    searchView = new SearchView();
    stackedWidget->addWidget(searchView);

    addWindow = new AddWindow();
    stackedWidget->addWidget(addWindow);

    editWindow = new EditWindow();
    stackedWidget->addWidget(editWindow);

    albumView = new AlbumView();
    stackedWidget->addWidget(albumView);

    //connessione pulsanti
    connect(searchView, &SearchView::addButtonClicked, this, &MainWindow::showAddView);
    connect(addWindow, &AddWindow::backButtonClicked, this, &MainWindow::showSearchView);
    connect(editWindow, &EditWindow::backButtonClicked, this, &MainWindow::showSearchView);
    connect(albumView, &AlbumView::backButtonClicked, this, &MainWindow::showSearchView);
    connect(searchView, &SearchView::editButtonClicked, this, &MainWindow::showEditView);
    connect(searchView, &SearchView::viewAlbumButtonClicked, this, &MainWindow::showAlbum);

}

void MainWindow::showSearchView() {
    stackedWidget->setCurrentIndex(0); // Torna alla vista di ricerca
    searchView->refresh(); // Aggiorna la vista di ricerca
}

void MainWindow::showAddView() {
    stackedWidget->setCurrentIndex(1); // Cambia l'indice in base alla posizione della vista di aggiunta nello stack
    addWindow->resetComboBox();
}


void MainWindow::showEditView(int id) {
    stackedWidget->setCurrentIndex(2); // Schermata di Edit
    editWindow->showEdit(id);
}

void MainWindow::showAlbum(int id) {
    stackedWidget->setCurrentIndex(3); // Schermata di Edit
    albumView->showID(id);
}