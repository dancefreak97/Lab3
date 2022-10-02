#include "MyWidget.h"
#include "LCDRange.h"

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
    //setFixedSize(200, 200);

    //Hello World
    QPushButton* hello = new QPushButton(tr("Hello World"), this);

    //Calling it Quits
    QPushButton* quit = new QPushButton(tr("Quit"), this);
    quit->setGeometry(62, 40, 75, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    /*
    //Building Blocks
    QLCDNumber* lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);

    connect(slider, SIGNAL(valueChanged(int)),
        lcd, SLOT(display(int)));
    */

    //One Thing Leads To Another
    QGridLayout* grid = new QGridLayout;
    LCDRange* previousRange = 0;

    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            LCDRange* lcdRange = new LCDRange;
            grid->addWidget(lcdRange, row, column);
            if (previousRange)
                connect(lcdRange, SIGNAL(valueChanged(int)),
                    previousRange, SLOT(setValue(int)));
            previousRange = lcdRange;
        }
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(hello);
    layout->addWidget(quit);
    layout->addLayout(grid);
    setLayout(layout);
}