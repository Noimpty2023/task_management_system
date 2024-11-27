// Copyright 2024 lyp

#include "header/Task.h"

// 编辑任务
bool Task::editTask(const QString& newTitle, const Tag& newTag, const QString& newDescription,
                    const QDateTime& newDeadline, int newPriority, bool status) {
    if (!newTitle.isEmpty() && newDeadline.isValid()) {
        title = newTitle;
        tag = newTag;
        description = newDescription;
        deadline = newDeadline;
        priority = newPriority;
        this->status = status;
        return true;
    }
    return false;
}

// 标记任务为完成
void Task::markComplete() {
    status = true;
}

// 创建提醒
bool Task::createReminder(const QDateTime& reminderTime, const QString& notificationMethod) {
    Reminder reminder;
    reminder.setReminder(reminderTime, notificationMethod, title);
    reminders.append(reminder);
    // qDebug() << title << " " << this->getReminders().size();
    return true;
}

// 比较操作符
bool Task::operator==(const Task& other) const {
    return title == other.title &&
           description == other.description &&
           deadline == other.deadline &&
           priority == other.priority &&
           status == other.status;
}

// Getter functions
QString Task::getTitle() const {
    return title;
}

QString Task::getDescription() const {
    return description;
}

QDateTime Task::getDeadline() const {
    return deadline;
}

int Task::getPriority() const {
    return priority;
}

bool Task::getStatus() const {
    return status;
}

Tag Task::getTag() const {
    return tag;
}

QList<Reminder> Task::getReminders() const {
    // qDebug() << title << " " << reminders.size();
    return reminders;
}

bool Task::deleteReminder(Reminder* reminder) {
    for (int i = 0; i < reminders.size(); ++i) {
        if (reminders[i] == *reminder) {
            reminders.removeAt(i);
            return true;
        }
    }
    return false;
}
