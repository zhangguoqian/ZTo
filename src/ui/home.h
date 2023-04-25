//
// Created by 11518 on 2023/4/23.
//

#ifndef QTO_PROJECT_HOME_H
#define QTO_PROJECT_HOME_H

#include <QWidget>
#include <QButtonGroup>
#include <QPropertyAnimation>
#include "systemtrayicon/systemtrayicon.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QWidget {
Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);

protected:
    void showEvent(QShowEvent *event) override;

public:

    ~Home() override;

private:
    Ui::Home *ui;
    QButtonGroup *mpButtonGroup;
    QPropertyAnimation *mpPropertyAnimation;
    SystemTrayIcon *mpSystemTrayIcon;
};


#endif //QTO_PROJECT_HOME_H
