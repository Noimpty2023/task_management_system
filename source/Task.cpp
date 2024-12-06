// Copyright 2024 lyp

#include <QJsonArray>

#include "../header/Task.h"

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

// 比较操作符
bool Task::operator==(const Task& other) const {
    return title == other.title &&
           description == other.description &&
           deadline == other.deadline &&
           priority == other.priority &&
           status == other.status;
}

QJsonObject Task::toJson() const {
    QJsonObject taskObj;
    taskObj["title"] = title;
    taskObj["description"] = description;
    taskObj["deadline"] = deadline.toString();
    taskObj["priority"] = priority;
    taskObj["status"] = status;
    taskObj["tag"] = tag.toJson();  // 假设 Tag 类有一个 toJson 方法
    QJsonArray remindersArray;
    for (const Reminder& reminder : reminders) {
        remindersArray.append(reminder.toJson());  // 假设 Reminder 类有一个 toJson 方法
    }
    taskObj["reminders"] = remindersArray;
    return taskObj;
}

Task Task::fromJson(const QJsonObject& json) {
    Task task;
    task.title = json["title"].toString();
    task.description = json["description"].toString();
    task.deadline = QDateTime::fromString(json["deadline"].toString());
    task.priority = json["priority"].toInt();
    task.status = json["status"].toBool();
    task.tag = Tag::fromJson(json["tag"].toObject());  // 假设 Tag 类有一个 fromJson 方法
    QJsonArray remindersArray = json["reminders"].toArray();
    for (const QJsonValue& value : remindersArray) {
        task.reminders.append(Reminder::fromJson(value.toObject()));  // 假设 Reminder 类有一个 fromJson 方法
    }
    return task;
}
