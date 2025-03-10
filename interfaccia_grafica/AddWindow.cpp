#include "AddWindow.h"

#include<QVBoxLayout>
#include<QLabel>

AddWindow::AddWindow(QWidget *parent){
    setWindowTitle("Aggiunta Widget");

    QLabel *banner = new QLabel("AGGIUNTA WIDGET", this);
    banner->setAlignment(Qt::AlignCenter);
    banner->setStyleSheet("font-size: 24px; font-weight: bold; color: blue;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(banner);
    setLayout(layout);
}