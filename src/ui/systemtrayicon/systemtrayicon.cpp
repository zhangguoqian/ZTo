//
// Created by 11518 on 2023/4/24.
//

#include "systemtrayicon.h"
#include <QDebug>
#include <QApplication>

SystemTrayIcon::SystemTrayIcon(QObject *parent) : QSystemTrayIcon(parent) {
    setIcon(QIcon(":/image/png/to_logo.png"));
}

SystemTrayIcon::~SystemTrayIcon() {

}
