#include "mylib.h"
#include <algorithm>

bool cmpByDiagonal(const ImageInfo &b1, const ImageInfo &b2)
{
  return b1.getDiagonal() < b2.getDiagonal();
}

double log(double a,double b)
{
    return std::log(b)/std::log(a);
}


ImageInfo::ImageInfo(QString fName, double dia)
{
    fileName = fName;
    diagonal = dia;
}

QString ImageInfo::getFilename() const{
    return fileName;
}

double ImageInfo::getDiagonal() const{
    return diagonal;
}




