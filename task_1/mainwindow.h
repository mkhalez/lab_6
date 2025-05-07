#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "state.h"

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

    QString createStateString(const Government& state);
    QString createPointerStateString(const Government* state);
    QString createRefStateString(Government& state);

    bool CheckInt(QString input);
    bool CheckDouble(QString input);

   private slots:
    void AddHelper();
};
#endif	// MAINWINDOW_H
