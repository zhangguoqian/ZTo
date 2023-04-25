#include <QApplication>
#include <QTextCodec>
#include "ui/home.h"
#include "poppler-qt5.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Home home;
    home.show();

    return QApplication::exec();
}
