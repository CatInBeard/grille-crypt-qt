#ifndef PRIMARYWINDOW_H
#define PRIMARYWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

class primarywindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit primarywindow(QWidget *parent = nullptr);

private slots:
    void aboutWindow();

signals:

private:
    MainWindow *widget;
};

#endif // PRIMARYWINDOW_H
