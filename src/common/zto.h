//
// Created by 11518 on 2022/12/14.
//

#ifndef ZTO_H
#define ZTO_H

#include <QString>
#include <QFile>

namespace ZTo {
    QString secondToTimeString(int sec);
    QString vectorToString(QVector<int> vector,QChar chr = ',');

    void delayMs(int ms);
};


#endif //DCUNION_PCRAPP_ZTO_H
