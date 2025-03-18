#ifndef CARDSCROLLAREA_H
#define CARDSCROLLAREA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "../visitor/CardVisitor.h"

class CardScrollArea : public QWidget {
    Q_OBJECT

public:
    explicit CardScrollArea(QWidget *parent = nullptr);
    void refreshCards();

private:
    QVBoxLayout *cardLayout;
    QWidget *contentWidget;
    CardVisitor* cardVisitor;

signals:
    void editButtonClicked(int id);
    
private slots:
    void ActionOnRemoveButtonClicked(int id);
    void ActionOnEditButtonClicked(int id); //propagazione alla mainwindow dalla card
};

#endif // CARDSCROLLAREA_H