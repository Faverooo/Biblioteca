#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "../visitor/DeriviedEditVisitor.h"

class AddWindow : public QWidget { // classe per la schermata di aggiunta
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    void resetComboBox(); //resetta il widget di scelta
    
signals:
    void backButtonClicked(); //per tornare alla schermata precedente

private slots:
    void onComboBoxChanged(int index); //carica il nuovo widget per il riempimento dell'oggetto
    void onSaveButtonClicked(); //salvataggio

private:
    QVBoxLayout *layout;
    QLabel *banner;
    QComboBox *comboBox;
    QPushButton *backButton;
    QPushButton *saveButton;
    AbsEditWidget *currentEditWidget;
};

#endif // ADDWINDOW_H