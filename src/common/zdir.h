//
// Created by 11518 on 2022/11/23.
//

#ifndef ZDIR_H
#define ZDIR_H

class QString;

class QStringList;

class QFileInfo;

namespace ZDir {
    //! 获取文件目录的文件信息列表
    QList<QFileInfo> getFileInfoList(const QString &dirName, const QStringList &nameFilters);

    //! 获取文件目录的文件路径列表
    QStringList getFilePathList(const QString &dirName, const QStringList &nameFilters);

    //! 获取文件目录的文件名字列表
    QStringList getFileNameList(const QString &dirName, const QStringList &nameFilters);

    //! 新建文件，存在或创建成功返回true，创建失败返回false
    bool mkDir(const QString &dirName);
};


#endif //MUSICPLAYER_ZDIR_H
