//
// Created by 11518 on 2023/4/25.
//

#ifndef QTO_PROJECT_FIRSTWIDGET_H
#define QTO_PROJECT_FIRSTWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class FirstWidget; }
QT_END_NAMESPACE

class FirstWidget : public QWidget {
Q_OBJECT

public:
    explicit FirstWidget(QWidget *parent = nullptr);

    ~FirstWidget() override;

private:
    Ui::FirstWidget *ui;
};


#endif //QTO_PROJECT_FIRSTWIDGET_H
