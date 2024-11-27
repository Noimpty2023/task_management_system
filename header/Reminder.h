// Copyright 2024 lyp

#ifndef HEADER_REMINDER_H_
#define HEADER_REMINDER_H_

#include <QString>
#include <QDateTime>

class Reminder {
 private:
    QDateTime reminderTime;      // 提醒时间
    QString notificationMethod;  // 通知方式
    QString message;             // 提醒消息

 public:
    void setReminder(const QDateTime& time, const QString& method, const QString& msg);
    bool checkAndTriggerReminder();  // 定时检查是否触发提醒
    bool operator==(const Reminder& other) const {
        return reminderTime == other.reminderTime &&
               notificationMethod == other.notificationMethod &&
               message == other.message;
    }
    QDateTime getReminderTime();
};

#endif  // HEADER_REMINDER_H_
