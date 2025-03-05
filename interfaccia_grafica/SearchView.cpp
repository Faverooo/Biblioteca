#include "SearchView.h"

SearchView::SearchView(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void SearchView::setupUI() {
    // Layout principale
    mainLayout = new QVBoxLayout(this);

    // Layout della barra superiore
    topBarLayout = new QHBoxLayout();
    searchBar = new QLineEdit(this);
    searchBar->setPlaceholderText("Cerca...");
    selector = new QComboBox(this);
    selector->addItem("Tutti");
    selector->addItem("Titolo");
    selector->addItem("Autore");
    selector->addItem("Anno");
    QPushButton *resetButton = new QPushButton("Azzera Filtri", this);

    topBarLayout->addWidget(searchBar);
    topBarLayout->addWidget(selector);
    topBarLayout->addWidget(resetButton);

    // Layout della barra laterale
    sideBarLayout = new QVBoxLayout();
    searchButton = new QPushButton("Cerca", this);
    sideBarLayout->addWidget(searchButton);

    // Layout per la visualizzazione dei libri
    booksDisplay = new QListWidget(this);

    // Aggiungi i layout al layout principale
    mainLayout->addLayout(topBarLayout);
    mainLayout->addLayout(sideBarLayout);
    mainLayout->addWidget(booksDisplay);

    // Connessioni dei segnali
    //connect(searchButton, &QPushButton::clicked, this, &SearchView::onSearchButtonClicked);
    //connect(resetButton, &QPushButton::clicked, this, &SearchView::onResetButtonClicked);
}
