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


#include "primarywindow.h"
#include <QToolBar>
#include <QString>
#include <QMenuBar>
#include <QMessageBox>

primarywindow::primarywindow(QWidget *parent)
    : QMainWindow{parent}
{
    widget = new MainWindow();
    setCentralWidget(widget);
    setWindowTitle("Grille crypt Qt");
    QAction* aboutAction = menuBar()->addAction("&About");

    connect(aboutAction, &QAction::triggered, this, &primarywindow::aboutWindow);

}

void primarywindow::aboutWindow(){
    QMessageBox::about(this,"About", "Copyright 2023 Grigoriy Efimov<efimov-gm@newpage.xyz>\n\n Grille-crypt-qt is a free software you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n \n This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. \n \n You should have received a copy of the GNU General Public License along with this program. If not, see https://www.gnu.org/licenses/.\n\n You can get sourcecode of this application from https://github.com/CatInBeard/grille-crypt-qt");
}
