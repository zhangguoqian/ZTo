//
// Created by 11518 on 2022/12/14.
//

#include <QTime>
#include <QEventLoop>
#include <QTimer>
#include "zto.h"

QString ZTo::secondToTimeString(int sec) {
    return QTime::fromMSecsSinceStartOfDay(sec * 1000).toString("hh:mm:ss");
}

QString ZTo::vectorToString(QVector<int> vector, QChar chr) {
    QStringList list;
    for (auto &var: vector) {
        list.append(QString::number(var));
    }
    return list.join(chr);
}



void ZTo::delayMs(int ms) {
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(ms, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}
