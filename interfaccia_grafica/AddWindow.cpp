#include "AddWindow.h"
#include "../visitor/EditVisitor.h"

#include<QVBoxLayout>
#include<QLabel>

AddWindow::AddWindow(QWidget *parent): QWidget(parent){
    banner = new QLabel("AGGIUNTA WIDGET", this);
    banner->setAlignment(Qt::AlignCenter);
    banner->setStyleSheet("font-size: 24px; font-weight: bold; color: blue;");

    layout = new QVBoxLayout(this);
    layout->addWidget(banner);
    LibroEditWidget* libroEditWidget = new LibroEditWidget();
    libroEditWidget->setTitolo("");
    libroEditWidget->setAnno("");
    libroEditWidget->setAutore("");
    libroEditWidget->setPagine("");
    libroEditWidget->setPercorso("");
    libroEditWidget->setID(-1);
    layout->addWidget(libroEditWidget);
    setLayout(layout);
}