//
// Created by 11518 on 2023/4/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PdfToImageWidget.h" resolved

#include "pdftoimagewidget.h"
#include "ui_PdfToImageWidget.h"
#include <QPropertyAnimation>
#include <QFileDialog>
#include <QDesktopServices>
#include "common/zcommon.h"
#include "poppler-qt5.h"

PdfToImageWidget::PdfToImageWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::PdfToImageWidget) {
    ui->setupUi(this);
    connect(ui->pBn_Open,SIGNAL(clicked()),this,SLOT(slotOpenPdfClicked()));
    connect(ui->pBn_Save,SIGNAL(clicked()),this,SLOT(slotSaveImageClicked()));
    connect(ui->pBn_Clear,SIGNAL(clicked()),this,SLOT(slotClearImageList()));
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
}

PdfToImageWidget::~PdfToImageWidget() {
    delete ui;
}

void PdfToImageWidget::showEvent(QShowEvent *event) {
 //   mpPropertyAnimation->start();
    QWidget::showEvent(event);
}

void PdfToImageWidget::slotOpenPdfClicked() {
    QImageList imageList;
    m_PdfFileName=QFileDialog::getOpenFileName(this,tr("打开"),"","pdf file (*.pdf)");//获取pdf文件路径
    if(m_PdfFileName.isEmpty()){
        return;//如果文件路径为空则返回
    }

    Poppler::Document* document = Poppler::Document::load(m_PdfFileName);//加载pdf文件
    if (!document || document->isLocked()) {
        qDebug()<<"error";
        delete document;
        return;
    }
    //再次检查document是否可用
    if (!document) {
        qDebug()<<QString("文件内无内容:%1").arg(m_PdfFileName);//不可用则输出错误信息，并返回
        return;
    }

//将PDF文档的每一页输出为QImage
    for(int pageNumber=0;pageNumber<document->numPages();pageNumber++){
        //获取指定页码的页面，页码从0开始
        Poppler::Page* pdfPage = document->page(pageNumber);
        if (pdfPage == 0) {
            qDebug() << QString::fromUtf8("获取页面失败:%1").arg(m_PdfFileName);//如果获取页面失败，输出错误信息并返回
            return;
        }

        //将页面内容转换为QImage
        double xres=300.0, yres=300.0; int x=-1, y=-1, width=-1, height=-1;
        QImage image = pdfPage->renderToImage(xres, yres, x, y, width, height);

        if (image.isNull()) {
            qDebug() << QString::fromUtf8("pdf转图片失败:%1").arg(m_PdfFileName);//如果输出为QImage失败，输出错误信息并返回
            return;
        }
        imageList.append(image);
        //使用QImage，可以让QImage显示在QLabel中，或者进一步处理，作其他用途……

        //使用完后记得释放掉Poppler::Page* pdfPage
        delete pdfPage;
    }
    ui->listWidget->setImageList(imageList);
}

void PdfToImageWidget::slotSaveImageClicked() {
    QStringList list = m_PdfFileName.split('/');
    QString dirName = list.last();
    dirName = dirName.left(dirName.size()-4);
    ZDir::mkDir("./image/"+dirName);
    const QImageList &image = ui->listWidget->getImageList();
    for(int i(0);i<image.size();i++){
        bool info = image[i].save(QString("%0/%1.jpg").arg("./image/"+dirName).arg(i));
        if(!info){
            qDebug()<<QString("%0/%1.jpg").arg(dirName).arg(i) << i;
        }
    }
    QString s=QString(QDir::currentPath()+"/image/"+dirName);
    QDesktopServices::openUrl(QUrl::fromLocalFile(s));
}

void PdfToImageWidget::slotClearImageList() {
    ui->listWidget->clearImageList();
    m_PdfFileName.clear();
}
