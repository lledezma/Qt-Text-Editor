#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QAction>
#include <QFile>
#include <QLabel>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void updateStatusBar();
    void add_images();

    QString m_filename;
    bool m_filesaved;

private slots:
    // Programmed Slots
    void new_file();
    void open_file();
    void save_file();
    void save_as_file();

    void html_text();

    // UI Slots
    void on_copyText_triggered();
    void on_cutText_triggered();
    void on_pasteText_triggered();
    void on_selectAllText_triggered();
    void on_selectNoneText_triggered();

    void on_editFile_textChanged();
};
#endif // MAINWINDOW_H
