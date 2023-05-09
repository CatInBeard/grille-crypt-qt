/*
 * Copyright 2023 Grigoriy Efimov
 *
 * Author: Grigoriy Efimov <efimov-gm@newpage.xyz>
 *
 * This file is part of grille-crypt-qt.
 *
 * Grille-crypt-qt is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * Grille-crypt-qt is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with grille-crypt-qt.
 * If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "actionwindow.h"
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <iostream>

ActionWindow::ActionWindow(QWidget *parent,ActionTypes at)
    : QWidget{parent}
{
    this->at = at;
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
    passcodeLabel = new QLabel();
    inputLabel->setText("Input File");
    outputLabel->setText("Output File");
    passcodeLabel->setText("Password");
    password = new QLineEdit();
    password->setEchoMode(QLineEdit::Password);

    box = new QHBoxLayout();

    box->addWidget(inputLabel);
    box->addWidget(buttonInputFile);
    box->addWidget(outputLabel);
    box->addWidget(buttonOutputFile);
    box->addWidget(passcodeLabel);
    box->addWidget(password);
    box->addWidget(passcodeLabel);
    box->addWidget(buttonAction);

    setLayout(box);

    connect(buttonInputFile, SIGNAL(clicked()), this, SLOT(getInputFileName()));
    connect(buttonOutputFile, SIGNAL(clicked()), this, SLOT(getOutputFileName()));
    connect(buttonAction, SIGNAL(clicked()), this, SLOT(doAction()));

}

void ActionWindow::doAction(){
    QString passCode = password->text();
    if( (inputPath == "") || (outputPath=="") || (passCode=="") ){
        QMessageBox::warning(this, "Warning", "Fill input filename, output filename and password",QMessageBox::Close);
        return;
    }
    grille::GrilleCrypt gc{};


    buttonAction->setEnabled(false);
    if(this->at == ActionTypes::encrypt){
        gc.Encrypt(inputPath.toStdString(), outputPath.toStdString(), passCode.toStdString());
    }
    else{
        gc.Decrypt(inputPath.toStdString(), outputPath.toStdString(), passCode.toStdString());
    }
    QMessageBox msgBox;
    msgBox.setText("Done");
    msgBox.exec();

    inputPath = "";
    outputPath = "";
    buttonInputFile->setText("...");
    buttonOutputFile->setText("...");
    buttonAction->setEnabled(true);
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
    outputPath = path;
}
