#pragma once
#ifndef MYLIB_H
#define MYLIB_H
#include <QString>
#include <cmath>


class ImageInfo{
public:
    ImageInfo(QString,double);
    QString getFilename() const;
    double getDiagonal() const;
private:
    QString fileName;
    double diagonal;
};

bool cmpByDiagonal(const ImageInfo &b1, const ImageInfo &b2);

double log(double a,double b);

#endif // MYLIB_H
