#ifndef LISTWSORT_H
#define LISTWSORT_H
#include<QFile>
#include<QListWidget>

class listWsort
{
public:
    QString files;
    QString files2;
    QString str;
    QListWidgetItem *item;
    int pupils;
    listWsort(QString _files , QString _files2, QListWidgetItem *_item, int _pupils, QString _str);
};

#endif // LISTWSORT_H
