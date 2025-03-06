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
    
    SearchView *searchView = new SearchView();
    stackedWidget->addWidget(searchView);
    
}


