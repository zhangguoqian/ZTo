//
// Created by 11518 on 2023/4/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ImageToPdfWidget.h" resolved

#include "imagetopdfwidget.h"
#include "ui_ImageToPdfWidget.h"
#include <QFileDialog>
#include <QMenu>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>


ImageToPdfWidget::ImageToPdfWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::ImageToPdfWidget) {
    ui->setupUi(this);

    connect(ui->pBn_SelectImage,SIGNAL(clicked()),SLOT(slotSelectImage()));
    connect(ui->pBn_Clear,SIGNAL(clicked()),this,SLOT(slotClearImageList()));
    connect(ui->pBn_Save,SIGNAL(clicked()),this,SLOT(slotSavePdfClicked()));
    connect(ui->pBn_Open,SIGNAL(clicked()),this,SLOT(slotOpenPdfDirClicked()));
}

ImageToPdfWidget::~ImageToPdfWidget() {
    delete ui;
}

void ImageToPdfWidget::slotSelectImage() {
    QStringList fileList = QFileDialog::getOpenFileNames(this,tr("选择图片"),"",tr("图片文件(*.bmp *png *jpg)"));
    if(fileList.empty()){
        return;
    }
    ui->listWidget->setImagePathList(fileList);
    qDebug()<<fileList;
}

void ImageToPdfWidget::slotClearImageList() {
    if(ui->listWidget->isEmpty()){
        return;
    }
    QMessageBox::StandardButton button = QMessageBox::information(this,
                                                                  tr("提示"),
                                                                  tr("确认清空当前图片列表？"),
                                                                  QMessageBox::Yes,
                                                                  QMessageBox::No);
    if(button==QMessageBox::Yes){
        ui->listWidget->clearImageList();
    }
}

void ImageToPdfWidget::slotSavePdfClicked() {
    QString pdfFileName;
    pdfFileName = QFileDialog::getSaveFileName(this, tr("保存PDF"), "pdf", tr("PDF文件(*.pdf)"));
    if(pdfFileName.isEmpty()){
        return;
    }
    auto pPdfWriter = new QPdfWriter(pdfFileName);
    QPageSize pageSize;
    QSizeF sizeF = QPageSize::definitionSize(QPageSize::A4);

    pPdfWriter->setPageSize(pageSize);
    pPdfWriter->setPageMargins(QMargins(0, 0, 0, 0));
    pPdfWriter->setResolution(300);//设置纸张的分辨率为300,因此其像素为3508X2479
    auto pPainter = new QPainter;
    pPainter->begin(pPdfWriter);
    const QImageList &list = ui->listWidget->getImageList();
    int size = list.size();
    QImage image;
    for(int i(0);i<size;i++){
        image = list[i].scaled(2479,3508);
        pPainter->drawImage(0,0,image);
        if(list[i] != list.last()){
            pPdfWriter->newPage();
        }
    }
    pPainter->end();
    delete pPainter;
    delete pPdfWriter;
}

void ImageToPdfWidget::slotOpenPdfDirClicked() {
    QDesktopServices::openUrl(QUrl::fromLocalFile(QDir::currentPath()+"./pdf"));
}

