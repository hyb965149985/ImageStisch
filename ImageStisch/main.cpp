#include "ImageStisch.h"
#include <QtWidgets/QApplication>


#include "SetupWidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageStisch w;
	//SetupWidget w;
    w.show();
    return a.exec();
}
