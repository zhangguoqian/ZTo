#ifndef ZFILE_H
#define ZFILE_H

#include <string>

#ifdef QT_CORE_LIB

#include <QFile>

namespace ZFile {
#ifdef QT_CORE_LIB

    bool readFile(const QString &fileName, QByteArray &byteArray);

    QByteArray readFile(const QString &fileName);

    bool writeFile(const QString &fileName, const QByteArray &byteArray);

    bool appendFile(const QString &fileName, const QByteArray &byteArray);

    QString getFileMd5(const QString &fileName);
#endif

    bool readFile(const std::string &fileName, std::string &string);

    std::string readFile(const std::string &fileName);

    bool writeFile(const std::string &fileName, const std::string &string);

    bool appendFile(const std::string &fileName, const std::string &string);
};

#endif

#endif // ZFILE_H
