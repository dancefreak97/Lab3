#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QPushButton>
#include <QWidget>

#include "MyWidget.h"

int main(int argc, char* argv[])
{
    /*
    QApplication app(argc, argv);

    //Family Values: part1
    QWidget window;
    window.resize(200, 120);

    
    //Hello World -edited for Family Values
    QPushButton hello("Hello world!", &window);
    //hello.show();
    
    //Calling it Quits -edited for Family Values
    QPushButton quit("Quit", &window);
    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    quit.setGeometry(10, 40, 180, 40);
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));
   
    //Family Values 2: part 3
    window.show();

    return app.exec();
    */

    //Let There Be Widgets
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}