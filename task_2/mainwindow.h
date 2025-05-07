#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    Ui::MainWindow* ui;

    void WriteInFile(QString input, QString file_name);
    bool CheckDouble(QString input);
    bool CheckInt(QString input);

    double* array = nullptr;
    int number_of_element = 0;
    void ReadAndDisplayStructures();
    int size;

   private slots:
    void AddParagraph();
    void AddElementArray();
    void CalculateArray();
    void CreateArray();
    void AddHelper();
    void AddSentence();

   private:
    struct Government {
        int population;
        double GDP;
        char first_letter;
        bool in_war;
        char name[20];
        int type_taxes[3];
    };
};
#endif	// MAINWINDOW_H
