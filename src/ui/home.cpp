//
// Created by 11518 on 2023/4/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Home.h" resolved

#include "home.h"
#include "ui_Home.h"
#include "common/zcommon.h"

Home::Home(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Home),
        mpButtonGroup(new QButtonGroup(this)),
        mpPropertyAnimation(new QPropertyAnimation (this, "windowOpacity")),
        mpSystemTrayIcon(new SystemTrayIcon(this)) {
    ui->setupUi(this);

    mpPropertyAnimation->setDuration(300);
    mpPropertyAnimation->setStartValue(0.0);
    mpPropertyAnimation->setEndValue(0.9);

    mpButtonGroup->addButton(ui->pBn_First,0);
    mpButtonGroup->addButton(ui->pBn_ImageToPdf,1);
    mpButtonGroup->addButton(ui->pBn_PdfToImage,2);
    connect(mpButtonGroup,SIGNAL(idClicked(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));

    ZDir::mkDir("pdf");
    ZDir::mkDir("image");

    mpSystemTrayIcon->setVisible(true);
}

Home::~Home() {
    mpSystemTrayIcon->deleteLater();
    mpPropertyAnimation->deleteLater();
    mpButtonGroup->deleteLater();
    delete ui;
}

void Home::showEvent(QShowEvent *event) {
    mpPropertyAnimation->start();
    QWidget::showEvent(event);
}
