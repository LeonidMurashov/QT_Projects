#ifndef MYQLABEL_H
#define MYQLABEL_H

#include<QLabel>

class MyQLabel : public QLabel
{
public:
    MyQLabel(QWidget * parent);
    void paintEvent(QEvent*);
    void refresh(int x, int y, int x1, int y1);
    int _x, _y, _x1, _y1;


};

#endif // MYQLABEL_H
