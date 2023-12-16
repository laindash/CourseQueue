#include "coursequeue.h"
#include <QtWidgets/QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, ".UTF8");
    QApplication a(argc, argv);
    CourseQueue w;
    w.show();
    return a.exec();
}
