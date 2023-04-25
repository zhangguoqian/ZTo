//
// Created by 11518 on 2022/11/23.
//

#include <QString>
#include <QDir>
#include "zdir.h"

QList<QFileInfo> ZDir::getFileInfoList(const QString &dirName, const QStringList &nameFilters) {
    QFileInfoList list;
    QDir dir(dirName);
    if (!dir.exists()) {
        return list;
    }
    list = dir.entryInfoList(nameFilters, QDir::Files, QDir::SortFlag::Name);
    return list;
}

QStringList ZDir::getFilePathList(const QString &dirName, const QStringList &nameFilters) {
    QStringList list;
    QDir dir(dirName);
    if (!dir.exists()) {
        return list;
    }
    QFileInfoList infoList = dir.entryInfoList(nameFilters, QDir::Files, QDir::SortFlag::Name);
    for (auto var: infoList)
        list << var.absoluteFilePath();
    return list;
}

QStringList ZDir::getFileNameList(const QString &dirName, const QStringList &nameFilters) {
    QStringList list;
    QDir dir(dirName);
    if (!dir.exists()) {
        return list;
    }
    QFileInfoList infoList = dir.entryInfoList(nameFilters, QDir::Files, QDir::SortFlag::Name);
    for (auto var: infoList)
        list << var.fileName();
    return list;
}

bool ZDir::mkDir(const QString &dirName) {
    QDir dir(dirName);
    if (!dir.exists()) {
        return QDir::current().mkdir(dirName);
    }
    return 1;
}
