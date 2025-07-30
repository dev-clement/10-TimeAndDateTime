#ifndef CPPCLASS_HPP
#define CPPCLASS_HPP

#include <QObject>
#include <QDateTime>
#include <QTime>
#include <QtQml/qqmlregistration.h>

class CppClass : public QObject {
    Q_OBJECT
public:
    explicit CppClass(QObject *parent = nullptr);

public slots:
    void cppSlot();
    void timeSlot(const QTime &time);
    void dateTimeSlot(const QDateTime &dateTime);

signals:
    void sendDateTime(const QDateTime &dateTime);
    void sendTime(const QTime &time);
};

#endif // CPPCLASS_HPP
