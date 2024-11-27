// Copyright 2024 lyp

#ifndef HEADER_SCHEDULEMANAGER_H_
#define HEADER_SCHEDULEMANAGER_H_

#include <QList>

#include "header/Tag.h"
#include "header/Task.h"

class ScheduleManager {
 private:
    QList<Tag> tags;  // 标签列表

 public:
    ScheduleManager();  // 构造函数
    ~ScheduleManager();  // 析构函数

    bool createTag(const QString& name);
    QList<Tag> getTags() const;
    QList<Task> filterTasksByTag(const Tag& tag, const QList<Task>& tasks) const;
    QList<Task> displayTasks(const QString& order, const QList<Task>& tasks) const;
};

#endif  // HEADER_SCHEDULEMANAGER_H_
