#include "office_tool.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Office_tool w;
    w.show();
    return a.exec();
}
