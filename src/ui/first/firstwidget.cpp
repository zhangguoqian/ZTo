//
// Created by 11518 on 2023/4/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FirstWidget.h" resolved

#include "firstwidget.h"
#include "ui_FirstWidget.h"


FirstWidget::FirstWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::FirstWidget) {
    ui->setupUi(this);
}

FirstWidget::~FirstWidget() {
    delete ui;
}
