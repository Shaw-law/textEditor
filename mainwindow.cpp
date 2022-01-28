#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Set Font
  myFont.setPointSize(14);

  // Button Settings
  connect(ui->btn, SIGNAL(clicked()), this, SLOT(btnAction()));
  ui->btn->setFont(myFont);

  ui->editor->setText("Hello\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->append("World\n");
  ui->editor->setUtf8(true);
  ui->editor->setFont(myFont);

  editorSettings(); // load editor configs
  marginSettings();
}

void MainWindow::btnAction() { std::cout << "Hello World"; }

// This function is for editor Settings
void MainWindow::editorSettings() {

  // Wrap Word Settings
  ui->editor->setWrapMode(QsciScintilla::WrapWord); // Wrap word
  ui->editor->setWrapVisualFlags(QsciScintilla::WrapFlagByText);
  ui->editor->setWrapIndentMode(QsciScintilla::WrapIndentIndented);

  // End of Line settings
  ui->editor->setEolMode(QsciScintilla::EolUnix); // Eol is set to unix
  ui->editor->setEolVisibility(false);

  // Indention settings
  ui->editor->setIndentationsUseTabs(false);
  ui->editor->setTabWidth(4);
  ui->editor->setIndentationGuides(true);
  ui->editor->setTabIndents(true);
  ui->editor->setAutoIndent(true);

  ui->editor->setCallTipsForegroundColor(QColor("#ff0000ff"));
  ui->editor->setCaretLineVisible(true);
  ui->editor->setCaretLineBackgroundColor(QColor("#1f0000ff"));
  ui->editor->setCaretWidth(2);
}

// This function is for margin settings
void MainWindow::marginSettings() {

  // Margin-0 Line Numbers
  ui->editor->setMarginType(0, QsciScintilla::NumberMargin);
  ui->editor->setMarginWidth(0, "0000");
  ui->editor->setMarginsForegroundColor(QColor("#ff888888"));

  // Symbol Margin
  ui->editor->setMarginType(1, QsciScintilla::SymbolMargin);
  ui->editor->setMarginWidth(1, "00000");

  ui->editor->markerDefine(sym_red, 0);
  ui->editor->markerDefine(sym_green, 1);
  ui->editor->markerDefine(sym_green_arrow, 2);
  ui->editor->markerDefine(sym_red_arrow, 3);

  ui->editor->setMarginMarkerMask(1, 0b1111);

  // Display a few symbols and keep their handle stored
  int handle1 = ui->editor->markerAdd(0, 0);
  int handle2 = ui->editor->markerAdd(4, 0);
  int handle3 = ui->editor->markerAdd(5, 0);
  int handle4 = ui->editor->markerAdd(8, 3);
  int handle5 = ui->editor->markerAdd(9, 2);
}

void MainWindow::mouseClick() {
  ui->editor->setMarginSensitivity(1, true);
  connect(ui->editor, &QsciScintilla::marginClicked, this,
          &MainWindow::margin_left_click);
  connect(ui->editor, &QsciScintilla::marginClicked, this,
          &MainWindow::margin_right_clicked);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::margin_left_click(int margin_nr, int line_nr, int state) {
  std::cout << "Hello Button Clicked \n";
  std::cout << "Margin No. " << margin_nr;
  std::cout << "\nline No. " << line_nr;
  std::cout << "\n";

  if (state == Qt::ControlModifier) {
    ui->editor->markerAdd(line_nr, 0);
  } else if (state == Qt::ShiftModifier) {
    ui->editor->markerAdd(line_nr, 1);
  } else if (state == Qt::AltModifier) {
    ui->editor->markerAdd(line_nr, 2);
  } else {
    ui->editor->markerAdd(line_nr, 3);
  }
}
void MainWindow::margin_right_clicked(int margin_nr, int line_nr, int state) {
  std::cout << "Right Button Clicked\n";
  std::cout << "Margin No. " << margin_nr;
  std::cout << "\nline no. " << line_nr;
  std::cout << "\n";
}
