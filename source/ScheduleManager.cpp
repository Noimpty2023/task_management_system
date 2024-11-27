// Copyright 2024 lyp

#include "header/ScheduleManager.h"

ScheduleManager::ScheduleManager() {
    // 可以在这里进行初始化，如果需要的话
    createTag("全部");
}

ScheduleManager::~ScheduleManager() {
    // 可以在这里进行清理工作，如果需要的话
}

// 创建标签
bool ScheduleManager::createTag(const QString& name) {
    if (!name.isEmpty() && name.length() <= 4) {
        bool flag = true;
        // 防止用户重复建立相同标签
        for (Tag tag : getTags()) {
            if (tag.getTagInfo() == name) flag = false;
        }
        if (flag) {
            Tag newTag;
            newTag.setName(name);
            tags.append(newTag);
            return true;
        }
    }
    return false;
}

// 获取标签列表
QList<Tag> ScheduleManager::getTags() const {
    return tags;
}

// 按标签过滤任务
QList<Task> ScheduleManager::filterTasksByTag(const Tag& tag, const QList<Task>& tasks) const {
    QList<Task> filteredTasks;
    for (const Task& task : tasks) {
        //  假设 Task 类中有一个获取标签的方法
        //  if (task.hasTag(tag)) {
        //      filteredTasks.append(task);
        //  }
    }
    return filteredTasks;
}

// 显示任务
QList<Task> ScheduleManager::displayTasks(const QString& order, const QList<Task>& tasks) const {
    QList<Task> sortedTasks = tasks;
    // 根据 order 参数进行排序
    return sortedTasks;
}
