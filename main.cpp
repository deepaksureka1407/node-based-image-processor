#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Node-Based Image Editor");
    window.resize(1000, 700);
    window.show();
    return app.exec();
}
