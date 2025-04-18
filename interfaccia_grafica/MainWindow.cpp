#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(1200, 800); // Larghezza: 1200, Altezza: 800
    setMinimumSize(600, 400); // Imposta la dimensione minima

    stackedWidget = new QStackedWidget(this);
    QWidget *headerWidget = new QWidget(this);
    headerWidget->setStyleSheet("background-color:rgb(166, 250, 140); border: 2px solid rgb(3, 85, 34); border-radius: 10px;");

    QHBoxLayout *headerLayout = new QHBoxLayout(headerWidget);
    QLabel *titleLabel = new QLabel("MyArchive", headerWidget);
    QPushButton *exitButton = new QPushButton("Exit", headerWidget);
    titleLabel->setStyleSheet("border: 0px;");
    exitButton->setStyleSheet("padding: 10px;");

    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(exitButton);

    headerWidget->setFixedHeight(this->height() * 0.08);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(headerWidget);
    mainLayout->addWidget(stackedWidget);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);

    connect(exitButton, &QPushButton::clicked, this, &QMainWindow::close);
    
    searchView = new SearchView();
    stackedWidget->addWidget(searchView);

    addWindow = new AddWindow();
    stackedWidget->addWidget(addWindow);

    editWindow = new EditWindow();
    stackedWidget->addWidget(editWindow);

    albumView = new AlbumView();
    stackedWidget->addWidget(albumView);

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
    albumView->show(id);
}