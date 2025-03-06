#ifndef CARDSCROLLAREA_H
#define CARDSCROLLAREA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "Card.h"

class CardScrollArea : public QWidget {
    Q_OBJECT

public:
    explicit CardScrollArea(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *cardLayout = new QVBoxLayout();

        // Aggiungi alcune card di esempio
        for (int i = 0; i < 10; ++i) {
            Card *card = new Card(QString("Title %1").arg(i + 1), QString("Description for card %1").arg(i + 1), this);
            cardLayout->addWidget(card);
        }

        QWidget *contentWidget = new QWidget(this);
        contentWidget->setLayout(cardLayout);

        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setWidget(contentWidget);
        scrollArea->setWidgetResizable(true);
        scrollArea->setStyleSheet("background-color: white;");

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(scrollArea);
        setLayout(mainLayout);
    }
};

#endif // CARDSCROLLAREA_H