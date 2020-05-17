#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QPixmap>
#include <QGridLayout>
#include <QLineEdit>



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

private slots:
    void on_fileComboBox_currentIndexChanged(const QString &arg1);
    void on_layerComboBox_currentIndexChanged(const QString &arg1);
    void on_scaleFactor_LineEdit_editingFinished();

private:
    Ui::Widget *ui;
    QLabel *imageLabel;
    QLabel *fileNameLabel,
            *scaleLabel,
            *layerLabel;
    QScrollArea *scrollArea;
    QComboBox *layerComboBox; //combobox с коэффициентами размера
    QComboBox *fileComboBox; //combobox со списком файлов
    QLineEdit *scaleFactor; //Поле для ввода коэффициента уменьшения
    QPixmap sourceImage;
    QPixmap scaledImage;
    QPushButton *quitBtn;
    QGridLayout *grid;
    void fillScale();
    void fillFileList();

};


#endif // WIDGET_H
