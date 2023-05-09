#ifndef ACTIONWINDOW_H
#define ACTIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include "actiontypes.h"

class ActionWindow : public QWidget
{
    Q_OBJECT
public:
    ActionWindow(QWidget *parent = nullptr,ActionTypes at = ActionTypes::encrypt);

private slots:
    void getInputFileName();
    void getOutputFileName();
    void doAction();
signals:

private:
    QHBoxLayout *box;
    QLabel *inputLabel;
    QLabel *outputLabel;
    QString inputPath;
    QString outputPath;
    QPushButton *buttonAction;
    QPushButton *buttonInputFile;
    QPushButton *buttonOutputFile;
    ActionWindow *ew;
};

#endif // ACTIONWINDOW_H
