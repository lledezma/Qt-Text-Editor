#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    this->setCentralWidget(ui->editFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    new_file();
    updateStatusBar();
    connect(ui->newFile, &QAction::triggered, this, &MainWindow::new_file);
    connect(ui->openFile, &QAction::triggered, this, &MainWindow::open_file);
    connect(ui->saveFile, &QAction::triggered, this, &MainWindow::save_file);
    connect(ui->saveAsFile, &QAction::triggered, this, &MainWindow::save_as_file);
}

void MainWindow::updateStatusBar()
{
    QLabel* barLabel = new QLabel(this);
    barLabel->setText(m_filename);
    ui->statusbar->addWidget(barLabel);
}

// Programmed Slots
void MainWindow::new_file()
{
    ui->editFile->clear();
    m_filename = "";
    m_filesaved = false;
}

void MainWindow::open_file()
{
    if(!ui->editFile->toPlainText().isEmpty()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Message", "Do you want to save current changes?", QMessageBox::Yes| QMessageBox::No);
        reply == QMessageBox::Yes ? save_file() : new_file();
    }

    QString filename = QFileDialog::getOpenFileName(this, "Open New File", QString(),"Text Files (*txt);;All Files (*,*)");
    m_filename = filename;

    if(filename.isEmpty())
        return;

    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this, "Message", file.errorString());
        return;
    }

    QTextStream filestream(&file);

    ui->editFile->setPlainText(filestream.readAll());

    file.close();

    updateStatusBar();
}

void MainWindow::save_file()
{
    if(m_filesaved)
        return;
    else if(m_filename.isEmpty())
        save_as_file();

    QFile file(m_filename);
    if(!file.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this, "Message", file.errorString());
        return;
    }

    QTextStream filestream(&file);
    filestream << ui->editFile->toPlainText();

    file.close();

    m_filesaved = true;
    updateStatusBar();

}

void MainWindow::save_as_file()
{
    m_filename = QFileDialog::getSaveFileName(this, "Save File", QString(),"Text Files (*txt);;All Files (*,*)");
    if(m_filename.isEmpty())
        return;
    save_file();
}

// UI Slots
void MainWindow::on_copyText_triggered()
{

}


void MainWindow::on_cutText_triggered()
{

}


void MainWindow::on_pasteText_triggered()
{

}


void MainWindow::on_selectAllText_triggered()
{

}


void MainWindow::on_selectNoneText_triggered()
{

}



void MainWindow::on_editFile_textChanged()
{
    m_filesaved = false;
}

