#include "MyWidget.h"

#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

//Let There Be Widgets
MyWidget::MyWidget(QWidget* parent) : QWidget(parent)
{
    setFixedSize(200, 200);

    //Hello World
    QPushButton* hello = new QPushButton(tr("Hello World"), this);

    //Calling it Quits
    QPushButton* quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(62, 40, 75, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    //Building Blocks
    QLCDNumber* lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);

    connect(slider, SIGNAL(valueChanged(int)),
        lcd, SLOT(display(int)));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(hello);
    layout->addWidget(quit);
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}