/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "treemodel.h"
#include <iostream>

#include <QFile>
#include <QDir>
#include <QFileSystemModel>
#include <QMessageBox>

#define targ "/Users/LeiBohan/Qt/Examples/Qt-5.12.0/widgets/itemviews/editabletreemodel/"
#define folder "/Users/LeiBohan/Qt/Examples/Qt-5.12.0/widgets/itemviews/editabletreemodel/"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    init();

    QStringList headers_local;
    headers_local << tr("Title") << tr("Description");
    QStringList headers_server;
    headers_server << tr("Title") << tr("Description");

    //updateActions();
}

void MainWindow::init()
{
    sprintf(console_info, "Welcome to FTP server");
    *new_content = '\0';
    updateConsole();

    dir_input->setText("/Users/Leibohan/FTPlocal");

    updateLocal();

    server_addr = "/";
    server_list = ".\n..\n";
    updateServer();
}

void MainWindow::error()
{
    QMessageBox::critical(0, "error", "An error has occured.");
}

void MainWindow::updateServer()
{
    QStringList header;
    header << tr("filename");
    free(view2->model());
    TreeModel *model_server = new TreeModel(header, server_list);
    view2->setModel(model_server);
}

void MainWindow::updateLocal(){
    dir_input->contentsMargins();

    QFileSystemModel *model = new QFileSystemModel();
    model->setRootPath(dir_input->text());

    QStringList nameFilter;
    nameFilter << "*";
    model->setNameFilterDisables(false);
    model->setNameFilters(nameFilter);
    view->setModel(model);
    view->setRootIndex(model->index(dir_input->text()));

    //QDir workspace;
    //workspace.setPath(dir_input->text());
    //workspace.Dirs;
    //workspace.setNameFilters();
}

void MainWindow::check()
{
    updateLocal();
    if (view->currentIndex().isValid()) view->clearSelection();
    QModelIndex present = view2->currentIndex();
    if (!present.isValid()) return;
    QModelIndex selected = present.sibling(present.row(),0);
    QString foldername(view2->model()->itemData(selected).values()[0].toString());
    QModelIndex selected2 = present.sibling(present.row(),2);
    QString type(view2->model()->itemData(selected2).values()[0].toString());
    if (type != "Folder") { // change to File Folder in windows system or refract the method to isDir with changing the class of QModelIndex
        view2->clearSelection();
        return;
    }
    /* 请完成 */
    //please implement a function that access to the folder named {foldername}
    view2->clearSelection();
    std::cout<<"updated";
    std::cout.flush();
}

void MainWindow::upload() {
    if (!view->currentIndex().isValid()) {
        //local upload source file not chosen.
        QMessageBox::critical(0, "fatal", "local upload source file not chosen.");
        return;
    }
    QString filename = ((QFileSystemModel)view->model()).filePath(view->currentIndex());
    /* 请完成 */
    //filename is the absolute address for the selected file.
    //we do not know the present ftp server address while it is our target.
    std::cout << filename.toStdString();
    std::cout.flush();
}

void MainWindow::download() {
    QModelIndex present = view2->currentIndex();
    if (!present.isValid()) {
        //server download source not chosen.
        QMessageBox::critical(0, "fatal", "server download source not chosen.");
        return;
    }
    QModelIndex selected = present.sibling(present.row(),0);
    QString filename(view2->model()->itemData(selected).values()[0].toString());
    QModelIndex present_ = view2->currentIndex();
    //QModelIndex selected__ = present_.sibling(present_.row(),2);
    //QString filename__(view2->model()->itemData(selected__).values()[0].toString());
    QString tar = dir_input->text();


    //use selected folder as the target saving address when it is a folder being selected only.
    tar = ((QFileSystemModel)view->model()).filePath(view->currentIndex());
    /* 请完成 */
    //filename is the name of the file going to be downloaded; tar is the target address; we do not know current ftp server address.
    std::cout << filename.toStdString();
    std::cout.flush();
}

void MainWindow::log()
{
    QString username = name_input->text();
    QString pw = pw_input->text();
    QString ip = ip_input->text();
    //以下请后端加入登录代码
    /* 请完成 */
    /*
    if (login) 执行登入;
    else 执行登出;
    login = ~login;
    */
    if (login)
        std::cout<<"log in";
    else
        std::cout<<"log out";
    std::cout.flush();
}

void MainWindow::updateConsole()
{

    //execute: {sprintf(new_content, "%s", __input_content__);} before this function

    sprintf(console_info, "%s%s\n", console_info, new_content);

    /*
    int lines = 0, count = 0, word = 0;
    for (char * ptr_a = new_content;*ptr_a != '\0';ptr_a ++) {
        if (*ptr_a == '\n') lines ++, count = word = 0;
        else if (*console_info == ' ') count += ++word, word = 0;
        else if (count>=50) lines ++, count = 0;
        else count++;
    }
    while (console_info ++ && !lines) {
        if (*console_info == '\n') lines --, count = word = 0;
        else if (*console_info == ' ') count += ++word, word = 0;
        else if (count + word>=50) lines --, count = 0;
        else count++;
    }
    sprintf(console_init, "%s", console_info);
    console_info = console_init;
    */
    textConsole->setText(console_info);

}

void MainWindow::on_btnUp_released()
{
    if (view->selectionBehavior())
    upload();
}


void MainWindow::on_btnDown_released()
{
    download();
}

void MainWindow::on_btnCheck_released()
{
    check();
}

void MainWindow::on_btnLog_released()
{
    log();
}
