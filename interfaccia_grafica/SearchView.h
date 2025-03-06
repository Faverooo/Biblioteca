#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QListWidget>
#include <QCheckBox>
#include <QLabel>

class SearchView : public QWidget {
    Q_OBJECT

public:
    explicit SearchView(QWidget *parent = nullptr);

private:
    void setupUI();
};

#endif // SEARCHVIEW_H