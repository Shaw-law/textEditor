#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  qDebug() << QStyleFactory::keys();
  a.setStyle(QStyleFactory::create("gtk"));
  MainWindow w;

  w.setGeometry(300, 300, 800, 400);
  w.setWindowTitle("QSciScintilla Window");
  w.show();
  return a.exec();
}
