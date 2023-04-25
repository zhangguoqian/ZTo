#include "zfile.h"
#include <fstream>
#include <iostream>
#include <QCryptographicHash>

#ifdef QT_CORE_LIB

bool ZFile::readFile(const QString &fileName, QByteArray &byteArray) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }
    byteArray = file.readAll();
    file.close();
    return 1;
}

QByteArray ZFile::readFile(const QString &fileName) {
    QByteArray byteArray;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return byteArray;
    }
    byteArray = file.readAll();
    file.close();
    return byteArray;
}

bool ZFile::writeFile(const QString &fileName, const QByteArray &byteArray) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    file.write(byteArray);
    file.close();
    return 1;
}

bool ZFile::appendFile(const QString &fileName, const QByteArray &byteArray) {
    QFile file(fileName);
    if (!file.open(QIODevice::Append)) {
        return false;
    }
    file.write(byteArray);
    file.close();
    return 1;
}

#endif

bool ZFile::readFile(const std::string &fileName, std::string &string) {
    char chars[100];
    std::fstream in(fileName, std::ios_base::in);
    if (!in.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return false;
    }
    string.clear();
    while (!in.eof())  //eof到文件末尾返回true
    {
        in.getline(chars, 100);
        string.append(chars, 100);
    }
    in.close();
    return true;
}

std::string ZFile::readFile(const std::string &fileName) {
    std::string str;
    bool info = readFile(fileName, str);
    if (!info) {
        return str;
    }
    return str;
}

bool ZFile::writeFile(const std::string &fileName, const std::string &string) {
    std::fstream out(fileName, std::ios_base::out);
    if (!out.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return false;
    }
    out.write(string.c_str(), string.length());
    out.close();
    return true;
}

bool ZFile::appendFile(const std::string &fileName, const std::string &string) {
    std::fstream out(fileName, std::ios_base::app);
    if (!out.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return false;
    }
    out.write(string.c_str(), string.length());
    out.close();
    return true;
}

QString ZFile::getFileMd5(const QString &fileName){
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly)){
        return "";
    }
    QByteArray array = file.readAll();
    file.close();
    QCryptographicHash md5(QCryptographicHash::Md5);
    md5.addData(array);
    return md5.result().toHex();
}