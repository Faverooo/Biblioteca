#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class Card : public QWidget {
    Q_OBJECT

public:
    explicit Card(const QString &title, const QString &description, QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *titleLabel = new QLabel(title, this);
        titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");
        QLabel *descriptionLabel = new QLabel(description, this);

        layout->addWidget(titleLabel);
        layout->addWidget(descriptionLabel);

        setLayout(layout);
        setStyleSheet("border: 1px solid #8f8f8f; border-radius: 10px; padding: 10px; background-color: #ffffff;");
    }
};

#endif // CARD_H