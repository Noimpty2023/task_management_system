// Copyright 2024 lyp

#ifndef  HEADER_TAG_H_
#define  HEADER_TAG_H_

#include <QString>

class Tag {
 private:
    QString name;  // 标签名称

 public:
    void setName(const QString& newName);
    QString getTagInfo() const;
    bool operator==(const Tag& other) const {
        return this->name == other.name;  // 比较 name 字段
    }
};

#endif  // HEADER_TAG_H_
