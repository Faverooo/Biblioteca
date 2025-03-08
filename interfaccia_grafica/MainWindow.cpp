#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QScrollArea>
#include <QGroupBox>
#include <QGridLayout>


#include"SearchView.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(1200, 800);

    //per la gestione di varie finestre all'interno della stessa schermata
    stackedWidget = new QStackedWidget(this);

    //barra di header
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

    //header fisso e schermate che cambiano sotto
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(headerWidget);
    mainLayout->addWidget(stackedWidget);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);

    //exit chiude l'app
    connect(exitButton, &QPushButton::clicked, this, &QMainWindow::close);
    
    //aggiunta schermate 
    SearchView *searchView = new SearchView();
    stackedWidget->addWidget(searchView);
    
}


