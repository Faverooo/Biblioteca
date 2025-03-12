#include "SearchView.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QScrollArea>
#include <QWidget>

SearchView::SearchView(QWidget *parent) : QWidget(parent)
{
    setupUI();

    connect(addButton, &QPushButton::clicked, this, &SearchView::addButtonClicked);

}

void SearchView::setupUI()
{
    // Layout principale
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // Layout della barra laterale di ricerca
    QVBoxLayout *sideBarLayout = new QVBoxLayout();
    searchBar = new QLineEdit(this);
    searchBar->setPlaceholderText("CERCA:");
    searchButton = new QPushButton(this);
    searchButton->setText("O"); // Icona lente d'ingrandimento
    sideBarLayout->addWidget(searchBar);
    sideBarLayout->addWidget(searchButton);
    sideBarLayout->addWidget(new QLabel("PER:"));
    //filtri
    titleCheckBox = new QCheckBox("Titolo", this);
    yearCheckBox = new QCheckBox("Anno", this);
    authorCheckBox = new QCheckBox("Autore/Regista/Artista", this);
    sideBarLayout->addWidget(titleCheckBox);
    sideBarLayout->addWidget(yearCheckBox);
    sideBarLayout->addWidget(authorCheckBox);
    addButton = new QPushButton("+ AGGIUNGI", this);
    sideBarLayout->addStretch();
    sideBarLayout->addWidget(addButton);

    // Definizione delle proporzioni della barra laterale
    sideBarWidget = new QWidget(this);
    sideBarWidget->setObjectName("sideBarWidget");
    sideBarWidget->setLayout(sideBarLayout);
    sideBarWidget->setFixedWidth(this->width() * 0.28);

    // Layout della barra superiore
    QHBoxLayout *topBarLayout = new QHBoxLayout();
    selector = new QComboBox(this);
    selector->addItem("TUTTO");
    selector->addItem("Libri");
    selector->addItem("Riviste");
    selector->addItem("Film");
    selector->addItem("Canzoni");
    selector->addItem("Album");
    resetButton = new QPushButton("AZZERA FILTRI", this);
    topBarLayout->addWidget(new QLabel("VISUALIZZA:"));
    topBarLayout->addWidget(selector);
    topBarLayout->addStretch();
    topBarLayout->addWidget(resetButton);

    // Definizione delle proporzioni della barra superiore
    topBarWidget = new QWidget(this);
    topBarWidget->setObjectName("topBarWidget");
    topBarWidget->setLayout(topBarLayout);
    topBarWidget->setFixedHeight(this->height() * 0.1);

    // Layout contenitore principale
    contentLayout = new QVBoxLayout();
    contentLayout->addWidget(topBarWidget);

    cardScrollArea = new CardScrollArea(this);
    contentLayout->addWidget(cardScrollArea);

    // Aggiunta dei layout al layout principale
    mainLayout->addWidget(sideBarWidget);
    mainLayout->addLayout(contentLayout);

    // Impostazione del layout principale
    this->setLayout(mainLayout);

    // Stili CSS per personalizzare l'aspetto
    this->setStyleSheet(
        "QWidget {"
        "   background-color: #f0f0f0;"
        "}"
        "QLineEdit {"
        "   border: 2px solid #8f8f8f;"
        "   border-radius: 10px;"
        "   padding: 5px;"
        "}"
        "QPushButton {"
        "   background-color: #4CAF50;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 10px;"
        "   padding: 10px 20px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;"
        "}"
        "QComboBox {"
        "   border: 2px solid #8f8f8f;"
        "   border-radius: 10px;"
        "   padding: 5px;"
        "   background-color: white;"
        "   color: black;" 
        "}"
        "QComboBox:hover {"
        "   color: black;" 
        "}"
        "QComboBox::drop-down {" 
        "   subcontrol-origin: padding;"
        "   subcontrol-position: top right;"
        "   width: 20px;"
        "   border-left-width: 1px;"
        "   border-left-color: #8f8f8f;"
        "   border-left-style: solid;"
        "   border-top-right-radius: 10px;"
        "   border-bottom-right-radius: 10px;"
        "}"
        "QComboBox::down-arrow {"
        "   image: url(:/icons/down_arrow.png);"
        "}"
        "QComboBox QAbstractItemView {"
        "   border: 2px solid #8f8f8f;"
        "   selection-background-color: #4CAF50;"
        "   color: black;" 
        "}"
        "QCheckBox {"
        "   padding: 5px;"
        "}"
        "QLabel {"
        "   padding: 5px;"
        "}"
        "QWidget#sideBarWidget {"
        "   border: 2px solid #000000;" 
        "   border-radius: 10px;"
        "   padding: 10px;"
        "}"
        "QWidget#topBarWidget {"
        "   border: 2px solid #000000;" 
        "   border-radius: 10px;"
        "   padding: 10px;"
        "}"
    );
}


void SearchView::refresh() {
    // Assuming cardScrollArea is a member variable of SearchView
    cardScrollArea->refreshCards();
}