// Copyright 2024 lyp

#ifndef HEADER_USER_H_
#define HEADER_USER_H_

#include <QString>
#include <QList>
#include <QDateTime>
#include <QTimer>

#include "header/Task.h"
#include "header/ScheduleManager.h"
#include "header/TimelineView.h"
#include "header/FocusSessionManager.h"
#include "header/Setting.h"
#include "header/NotificationManager.h"

class User : public QObject {
    Q_OBJECT

 private:
    QList<Task> tasks;                        // 用户的任务列表
    ScheduleManager scheduleManager;          // 用户的任务管理/显示主界面
    TimelineView timelineView;                // 用户的时间线视图
    FocusSessionManager focusSessionManager;  // 管理用户专注模式
    Setting setting;                          // 存储和管理用户信息
    NotificationManager notificationManager;  // 通知管理器
    QTimer* reminderTimer;                    // 定时器

 public:
    User();   // 构造函数
    ~User();  // 析构函数

    bool createTask(const QString& title, const QString& tagName,
                    const QString& description, const QDateTime& deadline, int priority,
                    bool reminder_flag, const QDateTime& reminderTime);
    bool editTask(const Task& task, const QString& title, const QString& tagName,
                  const QString& description, const QDateTime& deadline, int priority,
                  bool reminder_flag, const QDateTime& reminderTime);
    bool deleteTask(const Task& task);

    QList<Task> getTasks(const QString& order = "创建时间") const;
    QList<Tag> getTags() const;
    bool createTag(const QString& name);

 private slots:
    void checkTasksAndReminders();  // 定时检查任务和提醒
};

#endif  // HEADER_USER_H_
