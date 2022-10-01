#include "MyWidget.h"

#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

//Let There Be Widgets
MyWidget::MyWidget(QWidget* parent) : QWidget(parent)
{
    setFixedSize(200, 120);

    //Hello World
    QPushButton* hello = new QPushButton(tr("Hello World"), this);

    //Calling it Quits
    QPushButton* quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(62, 40, 75, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

}