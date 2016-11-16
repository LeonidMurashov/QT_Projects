#ifndef FINDER_H
#define FINDER_H

#include <QMainWindow>

namespace Ui {
class Finder;
}

class Finder : public QMainWindow
{
    Q_OBJECT

public:
    explicit Finder(QWidget *parent = 0);
    ~Finder();

private:
    Ui::Finder *ui;
public slots:
    void capturedslot(QString adr);
};

#endif // FINDER_H
