#include <QtWidgets>
#include <FenPrincipale.h>

int main(int argc, char *argv[])

{
    QApplication app(argc,argv);
    FenPrincipale mainWindow;
    mainWindow.setWindowTitle("Paint by Djamby");
    mainWindow.show();

    return app.exec();


}
