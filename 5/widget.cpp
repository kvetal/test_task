#include "widget.h"
#include <QDir>
#include <QMessageBox>
#include <QList>
#include "mylib.h"
#include <algorithm>



Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
       quitBtn = new QPushButton("Выход"); //Создаем кнопку выхода
       fileComboBox = new QComboBox(this); //создаем комбобох со списком файлов картинок
       layerComboBox = new QComboBox(this); //создаем комбобох со списком слоев
       imageLabel = new QLabel(); //Поле для вывода изображения.
       fileNameLabel = new QLabel("Имя файла");
       scaleLabel = new QLabel("Коэффициент");
       layerLabel = new QLabel("Слой");
       scrollArea = new QScrollArea;
       scaleFactor = new QLineEdit();

       scaleFactor->setValidator(new QDoubleValidator);
       scaleFactor->setText("2");

       grid = new QGridLayout(this);
       grid->addWidget(fileNameLabel,0,0);
       grid->addWidget(scaleLabel,0,1);
       grid->addWidget(layerLabel,0,2);
       grid->addWidget(fileComboBox,1,0);
       grid->addWidget(layerComboBox,1,2);
       grid->addWidget(scaleFactor,1,1);
       grid->addWidget(scrollArea,2,0,1,3);
       grid->addWidget(quitBtn,3,2);
       setLayout(grid);

       connect(quitBtn,&QPushButton::clicked,qApp, &QApplication::quit);
       connect(fileComboBox,QOverload<const QString &>::of(&QComboBox::currentTextChanged),this,QOverload<const QString &>::of(&Widget::on_fileComboBox_currentIndexChanged));
       connect(layerComboBox,QOverload<const QString &>::of(&QComboBox::currentTextChanged),this,QOverload<const QString &>::of(&Widget::on_layerComboBox_currentIndexChanged));
       connect(scaleFactor,&QLineEdit::editingFinished,this,&Widget::on_scaleFactor_LineEdit_editingFinished);
       fillFileList();
}

void Widget::on_scaleFactor_LineEdit_editingFinished()
{
    this->fillScale();
}


void Widget::on_layerComboBox_currentIndexChanged(const QString &arg1)
{
    double k;
    if (arg1.toInt() == 1)
        k = 1;
    else
        k = std::pow(scaleFactor->text().toDouble(),arg1.toInt());
    scaledImage = sourceImage.scaled(sourceImage.width()/k,sourceImage.height()/k,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    scaledImage = scaledImage.scaled(sourceImage.width(),sourceImage.height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    imageLabel->setPixmap(scaledImage);
    scrollArea->setWidget(imageLabel);
}

void Widget::on_fileComboBox_currentIndexChanged(const QString &arg1)
{
    sourceImage = QPixmap("image/"+arg1);
    imageLabel->setPixmap(sourceImage);
    imageLabel->resize(sourceImage.width(),sourceImage.height());
    scrollArea->setWidget(imageLabel);
    fillScale();
}

void Widget::fillFileList(){ //Сканируем директорию и заполняем список файлов
  QDir dir("image");
    QMessageBox msgBox;
    if(!dir.exists()){
        QDir d;
        if (!d.mkdir("image")){
        msgBox.setText("Не удалось создать папку для изображений");
        msgBox.exec();
        }
    }
    dir.setFilter(QDir::Files);
    dir.setNameFilters(QStringList()<<"*.jpg" <<"*.jpeg"<<"*.png");
    QFileInfoList list = dir.entryInfoList();
    if (!list.size()){
        msgBox.setText("В папке image не обнаружены изображения.\n Добавьте файлы формата jpg/jpeg/png и перезапустите приложение.");
        msgBox.exec();
    }
    QList<ImageInfo> imageInfoList;
    for(auto val:list){
        QPixmap img("image/"+val.fileName());
        //Если размер не нулевой добавляем имя файла и диагональ в список. если формат неверный размер будет нулевым.
        if(img.width()){
            ImageInfo tmpinfo(val.fileName(),(std::sqrt(std::pow(img.width(),2)+std::pow(img.height(),2))));
            imageInfoList.push_back(tmpinfo);
        }
    }
    //Сортируем по размеру диагонали изображения.
    std::sort(imageInfoList.begin(),imageInfoList.end(),cmpByDiagonal);
    // Заполняем комбобокс именами файлов
    for(auto val:imageInfoList){
        fileComboBox->addItem(val.getFilename());
    }
}

void Widget::fillScale(){ //Вычисляем количество слоев и заполняем список.
    int64_t sizecount;
    double factor = scaleFactor->text().toDouble();
    if (sourceImage.height() <= sourceImage.width()){
        sizecount = log(factor,sourceImage.height());
    }
    else {
        sizecount = log(factor,sourceImage.width());
    }
    layerComboBox->clear();
    for (int i = 0; i<sizecount;++i){
      layerComboBox->addItem(QString::number(i+1));
    }
}





