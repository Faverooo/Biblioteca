#ifndef CARDSCROLLAREA_H
#define CARDSCROLLAREA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>

class CardScrollArea : public QWidget {
    Q_OBJECT

public:
    explicit CardScrollArea(QWidget *parent = nullptr);
};

#endif // CARDSCROLLAREA_H