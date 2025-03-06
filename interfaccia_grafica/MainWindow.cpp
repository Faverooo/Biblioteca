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
    resize(1200, 800); // Larghezza: 1200, Altezza: 800
    setMinimumSize(600, 400);

    stackedWidget = new QStackedWidget(this);
    QWidget *headerWidget = new QWidget(this);
    headerWidget->setStyleSheet("background-color: #f5deb3;"); 

    QHBoxLayout *headerLayout = new QHBoxLayout(headerWidget);
    QLabel *titleLabel = new QLabel("MyArchive", headerWidget);
    QPushButton *exitButton = new QPushButton("Exit", headerWidget);

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
    
    SearchView *searchView = new SearchView();
    stackedWidget->addWidget(searchView);
    
}


