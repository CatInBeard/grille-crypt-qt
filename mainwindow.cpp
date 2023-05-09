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


#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{



    buttonEncrypt = new QPushButton("Ecnrypt");
    buttonDecrypt = new QPushButton("Decrypt");

    label = new QLabel();

    label->setText("Choose what you will do with the file");


    box = new QVBoxLayout();

    box->addWidget(label);
    box->addSpacing(50);
    box->addWidget(buttonEncrypt);
    box->addWidget(buttonDecrypt);

    setLayout(box);

    ew = new EncryptWindow();
    connect(buttonEncrypt, SIGNAL(clicked()), this, SLOT(encryptButtonClicked()));
}

void MainWindow::encryptButtonClicked(){
    ew->show();
}

MainWindow::~MainWindow()
{
}

