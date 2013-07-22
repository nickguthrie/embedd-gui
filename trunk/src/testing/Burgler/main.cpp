#include "mainwindow.h"
#include <QApplication>
#include <QWSServer>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // a.setOverrideCursor(QCursor( Qt::BlankCursor ));

    // Change the background Color
    QPalette pal = a.palette();
    pal.setColor(QPalette::Window, Qt::black);
    a.setPalette(pal);


#ifdef Q_WS_QWS
    QWSServer::setCursorVisible( false );
#endif
    MainWindow w;
    w.showFullScreen();
    return a.exec();
}

