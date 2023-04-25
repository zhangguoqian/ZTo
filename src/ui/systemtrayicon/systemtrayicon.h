//
// Created by 11518 on 2023/4/24.
//

#ifndef QTO_PROJECT_SYSTEMTRAYICON_H
#define QTO_PROJECT_SYSTEMTRAYICON_H

#include <QSystemTrayIcon>

class SystemTrayIcon : public QSystemTrayIcon{
Q_OBJECT
public:
    explicit SystemTrayIcon(QObject *parent = nullptr);
    ~ SystemTrayIcon() override;
};


#endif //QTO_PROJECT_SYSTEMTRAYICON_H
