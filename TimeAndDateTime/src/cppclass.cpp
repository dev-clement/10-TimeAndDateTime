#include <QDebug>
#include "cppclass.hpp"

CppClass::CppClass(QObject *parent): QObject{parent} {}

void CppClass::cppSlot() {
    qDebug() << "C++ here, cppSlot called !!";
    emit sendDateTime(QDateTime::currentDateTime());
    emit sendTime(QTime::currentTime());
}

void CppClass::timeSlot(const QTime &time) {
    qDebug() << "Time from QML is: " << time;
}

void CppClass::dateTimeSlot(const QDateTime &dateTime) {
    qDebug() << "DateTime from QML is: " << dateTime;
}
