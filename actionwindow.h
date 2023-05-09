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

#ifndef ACTIONWINDOW_H
#define ACTIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QList>
#include <QLineEdit>
#include "actiontypes.h"
#include "grille-crypt/src/GrilleCrypt.h"

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
    ActionTypes at;
    QHBoxLayout *box;
    QLabel *inputLabel;
    QLabel *outputLabel;
    QLabel *passcodeLabel;
    QLineEdit *password;
    QString inputPath;
    QString outputPath;
    QPushButton *buttonAction;
    QPushButton *buttonInputFile;
    QPushButton *buttonOutputFile;
};

#endif // ACTIONWINDOW_H
