#ifndef LCDRANGE_H
#define LCDRANGE_H

#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class QSlider;

class LCDRange : public QWidget
{
    Q_OBJECT
        int value() const;

    public:
        LCDRange(QWidget* parent = 0);
    public slots:
        void setValue(int value);
    signals:
        void valueChanges(int newValue);

    private:
        QSlider* slider;
};

#endif