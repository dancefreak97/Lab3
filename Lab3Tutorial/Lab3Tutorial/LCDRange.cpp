#include "LCDRange.h"

#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

LCDRange::LCDRange(QWidget* parent)
    : QWidget(parent)
{
    QLCDNumber* lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);
    connect(slider, SIGNAL(valueChanged(int)),
        lcd, SLOT(display(int)));

    //One Thing Leads To Another
    connect(slider, SIGNAL(valueChanged(int)),
        this, SIGNAL(valueChanged(int)));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

//One Thing Leads To Another
int LCDRange::value() const
{
    return slider->value();
}

 void LCDRange::setValue(int value)
 {
     slider->setValue(value);
 }