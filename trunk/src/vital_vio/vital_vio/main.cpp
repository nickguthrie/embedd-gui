////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------ :Libraries:
//                      _    _ _                 _        
//                     | |  (_) |__ _ _ __ _ _ _(_)___ ___
//                     | |__| | '_ \ '_/ _` | '_| / -_|_-<
//                     |____|_|_.__/_| \__,_|_| |_\___/__/
//                                                        
// -----------------------------------------------------------------------------
#include "mainwindow.h"
#include <QApplication>
#include <QWSServer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // Change the background Color
    QPalette pal = a.palette();
    pal.setColor(QPalette::Window, Qt::black);
    a.setPalette(pal);

#ifdef Q_WS_QWS
    QWSServer::setCursorVisible( false );
#endif

    // Start the GUI
    MainWindow w;
    w.showFullScreen();
    w.show();

    // Exit the program
    return a.exec();
}
