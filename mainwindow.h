#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFont>
#include <QMainWindow>
#include <Qsci/qsciscintilla.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

public slots:
  void btnAction();
  void margin_left_click(int margin_nr, int line_nr, int state);
  void margin_right_clicked(int margin_nr, int line_nr, int state);

protected:
  QImage sym_red = QImage(":/images/Red.png").scaled(QSize(16, 16));
  QImage sym_green = QImage(":/images/green.png").scaled(QSize(16, 16));
  QImage sym_green_arrow =
      QImage(":/images/greenArrow.png").scaled(QSize(16, 16));
  QImage sym_red_arrow = QImage(":/images/redArrow.png").scaled(QSize(16, 16));

private:
  void editorSettings();
  void marginSettings();
  void mouseClick();
  QFont myFont;
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
