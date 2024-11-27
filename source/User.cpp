// Copyright 2024 lyp

#include <algorithm>

#include "header/User.h"

User::User() {
    // 在构造函数中初始化成员变量，必要时可进行设置
    reminderTimer = new QTimer(this);
    connect(reminderTimer, &QTimer::timeout, this, &User::checkTasksAndReminders);
    reminderTimer->start(1000);  // 每秒检查一次任务提醒
}

User::~User() {
    // 析构函数，清理资源
    // 这里通常不需要手动清理 QList 和其他 Qt 容器，
    // 但如果有动态分配的资源，应该在这里释放。
    delete reminderTimer;
}

void User::checkTasksAndReminders() {
    // 遍历任务列表，检查每个任务的提醒时间
    for (Task& task : tasks) {
        for (Reminder& reminder : task.getReminders()) {
            if (reminder.checkAndTriggerReminder()) {
                notificationManager.sendNotification(this, &task, &reminder);
            }
        }
    }
}

bool User::createTask(const QString& title, const QString& tagName,
                      const QString& description, const QDateTime& deadline, int priority,
                      bool reminder_flag, const QDateTime& reminderTime) {
    createTag(tagName);
    QList<QString> tagNames;
    for (Tag tag : getTags()) {
        tagNames.append(tag.getTagInfo());
    }

    // 先创建标签，如果标签没有创建成功（标签列表里面没有该标签），那就算创建任务失败
    Task newTask;
    if (tagNames.contains(tagName)) {
        if (newTask.editTask(title, getTags()[tagNames.indexOf(tagName)], description, deadline, priority, false)) {
            if (reminder_flag) newTask.createReminder(reminderTime, "");
            tasks.append(newTask);
            return true;
        }
    } else if (tagName.isEmpty()) {
        if (newTask.editTask(title, getTags()[0], description, deadline, priority, false)) {
            if (reminder_flag) newTask.createReminder(reminderTime, "");
            tasks.append(newTask);
            return true;
        }
    }
    return false;
}

bool User::editTask(const Task& task, const QString& title, const QString& tagName,
                    const QString& description, const QDateTime& deadline, int priority,
                    bool reminder_flag, const QDateTime& reminderTime) {
    createTag(tagName);
    QList<QString> tagNames;
    for (Tag tag : getTags()) {
        tagNames.append(tag.getTagInfo());
    }

    // 先创建标签，如果标签没有创建成功（标签列表里面没有该标签），那就算创建任务失败
    for (Task& tmp : tasks) {
        if (tmp == task) {
            if (tagNames.contains(tagName)) {
                if (tmp.editTask(title, getTags()[tagNames.indexOf(tagName)], description, deadline, priority, false)) {
                    if (reminder_flag) tmp.createReminder(reminderTime, "");
                    return true;
                }
            } else if (tagName.isEmpty()) {
                if (tmp.editTask(title, getTags()[0], description, deadline, priority, false)) {
                    if (reminder_flag) tmp.createReminder(reminderTime, "");
                    return true;
                }
            }
            break;
        }
    }
    return false;
}


bool User::deleteTask(const Task& task) {
    return tasks.removeOne(task);  // 使用重载的 '==' 运算符进行比较
}

bool compareByDueDate(const Task& task1, const Task& task2) {
    return task1.getDeadline() < task2.getDeadline();  // 按照 QDateTime 升序排序
}
QList<Task> User::getTasks(const QString& order) const {
    if (order == "截止时间") {
        QList<Task> sortedTasks = tasks;
        std::sort(sortedTasks.begin(), sortedTasks.end(), compareByDueDate);
        return sortedTasks;
    } else if (order == "创建时间") {
        return tasks;
    }
    else assert(0);
}

QList<Tag> User::getTags() const {
    return scheduleManager.getTags();
}

bool User::createTag(const QString& name) {
    return scheduleManager.createTag(name);
}
