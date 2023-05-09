#include "actionwindow.h"
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

ActionWindow::ActionWindow(QWidget *parent,ActionTypes at)
    : QWidget{parent}
{

    if(at == ActionTypes::encrypt){
        buttonAction = new QPushButton("Ecnrypt");
    }
    else{
        buttonAction = new QPushButton("Decrypt");
    }

    buttonInputFile = new QPushButton("...");
    buttonOutputFile = new QPushButton("...");

    inputLabel = new QLabel();
    outputLabel = new QLabel();
    inputLabel->setText("Input File");
    outputLabel->setText("Output File");

    box = new QHBoxLayout();

    box->addWidget(inputLabel);
    box->addWidget(buttonInputFile);
    box->addWidget(outputLabel);
    box->addWidget(buttonOutputFile);
    box->addWidget(buttonAction);

    setLayout(box);

    connect(buttonInputFile, SIGNAL(clicked()), this, SLOT(getInputFileName()));
    connect(buttonOutputFile, SIGNAL(clicked()), this, SLOT(getOutputFileName()));
    connect(buttonAction, SIGNAL(clicked()), this, SLOT(doAction()));

}

void ActionWindow::doAction(){
    if( (inputPath == "") & (outputPath=="") ){
        QMessageBox::warning(this, "Warning", "Fill input filename and output filename",QMessageBox::Close);
        return;
    }
    inputPath = "";
    outputPath = "";
    buttonInputFile->setText("...");
    buttonOutputFile->setText("...");
    QMessageBox msgBox;
    msgBox.setText("Done");
    msgBox.exec();
}

void ActionWindow::getInputFileName()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Find Files"), QDir::currentPath());
    QString inputFileText = "..." + path.mid(path.size()-5,5);
    buttonInputFile->setText(inputFileText);
    inputPath = path;
}

void ActionWindow::getOutputFileName()
{
    QString path = QFileDialog::getSaveFileName(this,tr("Find Files"), QDir::currentPath());
    QString outputFileText = "..." + path.mid(path.size()-5,5);
    buttonOutputFile->setText(outputFileText);
    inputPath = path;
}
