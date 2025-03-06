#include "SearchView.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QListWidget>
#include <QLabel>

SearchView::SearchView(QWidget *parent) : QWidget(parent)
{
    setupUI();
}

void SearchView::setupUI()
{
    // Layout principale
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // Layout della barra laterale di ricerca
    QVBoxLayout *sideBarLayout = new QVBoxLayout();
    QLineEdit *searchBar = new QLineEdit(this);
    searchBar->setPlaceholderText("CERCA:");
    QPushButton *searchButton = new QPushButton(this);
    searchButton->setText("O"); // Icona lente d'ingrandimento
    sideBarLayout->addWidget(searchBar);
    sideBarLayout->addWidget(searchButton);
    sideBarLayout->addWidget(new QLabel("PER:"));
    sideBarLayout->addWidget(new QCheckBox("Titolo", this));
    sideBarLayout->addWidget(new QCheckBox("Anno", this));
    sideBarLayout->addWidget(new QCheckBox("Autore/Regista/Artista", this));
    QPushButton *addButton = new QPushButton("+ AGGIUNGI", this);
    sideBarLayout->addStretch();
    sideBarLayout->addWidget(addButton);

    // Definizione delle proporzioni della barra laterale
    QWidget *sideBarWidget = new QWidget(this);
    sideBarWidget->setLayout(sideBarLayout);
    sideBarWidget->setFixedWidth(this->width() * 0.28);

    // Layout della barra superiore
    QHBoxLayout *topBarLayout = new QHBoxLayout();
    QComboBox *selector = new QComboBox(this);
    selector->addItem("TUTTO");
    selector->addItem("Libri");
    selector->addItem("Film");
    selector->addItem("Musica");
    QPushButton *resetButton = new QPushButton("AZZERA FILTRI", this);
    topBarLayout->addWidget(new QLabel("VISUALIZZA:"));
    topBarLayout->addWidget(selector);
    topBarLayout->addStretch();
    topBarLayout->addWidget(resetButton);

    // Definizione delle proporzioni della barra superiore
    QWidget *topBarWidget = new QWidget(this);
    topBarWidget->setLayout(topBarLayout);
    topBarWidget->setFixedHeight(this->height() * 0.1);

    // Layout contenitore principale
    QVBoxLayout *contentLayout = new QVBoxLayout();
    contentLayout->addWidget(topBarWidget);

    // Placeholder per la visualizzazione dei contenuti
    QWidget *contentPlaceholder = new QWidget(this);
    contentPlaceholder->setStyleSheet("background-color: white;");
    contentLayout->addWidget(contentPlaceholder);

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
        "}"
        "QCheckBox {"
        "   padding: 5px;"
        "}"
        "QLabel {"
        "   padding: 5px;"
        "}"
        "QWidget#sideBarWidget {"
        "   background-color: #d3d3d3;"
        "   border: 2px solid #8f8f8f;"
        "   border-radius: 10px;"
        "   padding: 10px;"
        "}"
    );
}