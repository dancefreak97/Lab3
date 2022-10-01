#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    //Hello World button
    QPushButton hello("Hello world!");
    hello.show();

    //Calling it Quits
    QPushButton quit("Quit", 0);
    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));
    quit.show();




    return app.exec();
}