//
// Created by 11518 on 2023/4/23.
//

#include "imagelistwidget.h"
#include <QListWidgetItem>
#include <QMenu>

ImageListWidget::ImageListWidget(QWidget *parent) : QListWidget(parent) {
    connect(this->model(),&QAbstractItemModel::rowsMoved,
            this,[=](const QModelIndex &parent,int start,int end,const QModelIndex &destination,int row){
                int count = this->count() ;
                if(count == m_ImageList.size()){
                    m_ImageList.move(start,start>row?row:row-1);
                }
                if(count == m_ImagePathList.size()) {
                    m_ImagePathList.move(start, start > row ? row : row - 1);
                }
                qDebug()<<m_ImagePathList;
            });

    connect(this, &ImageListWidget::customContextMenuRequested,[=](const QPoint &point){
        qDebug()<<point;
        int row = this->currentIndex().row();
        if(row==-1){
            return ;
        }
        auto *pMenu = new QMenu();

        auto *pActionCR90 = new QAction(tr("顺时针旋转90°"),pMenu);
        connect(pActionCR90,&QAction::triggered,[=](){
            setTransformation(row,90);
            qDebug()<<"顺时针旋转90°";
        });
        pMenu->addAction(pActionCR90);

        auto *pActionCCR90 = new QAction(tr("逆时针旋转90°"),pMenu);
        connect(pActionCCR90,&QAction::triggered,[=](){
            setTransformation(row,270);
            qDebug()<<"逆时针旋转90°";
        });
        pMenu->addAction(pActionCCR90);

        auto *pAction180 = new QAction(tr("旋转180°"),pMenu);
        connect(pAction180,&QAction::triggered,[=](){
            setTransformation(row,180);
            qDebug()<<"旋转180°";
        });
        pMenu->addAction(pAction180);
        pMenu->exec(QCursor::pos());
    });
}

ImageListWidget::~ImageListWidget() {

}

void ImageListWidget::setImagePathList(const QStringList &imagePathList) {
    clearImageList();
    int size = imagePathList.size();
    QImage image;
    QListWidgetItem *pListItemWidget;
    for(int i(0);i<size;i++){
        if(image.load(imagePathList[i])){
            QIcon icon =QIcon(QPixmap(imagePathList[i]).scaled(200,200));
            pListItemWidget = new QListWidgetItem(icon ,imagePathList[i],this);
            this->addItem(pListItemWidget);
            m_ImageList.append(image);
            m_ImagePathList.append(imagePathList[i]);
        }else{
            QMessageBox::warning(this,tr("警告"),tr("第%0张图片加载错误，\n图片路径:%1!")
                    .arg(i+1)
                    .arg(imagePathList[i]));
        }
    }
}

void ImageListWidget::clearImageList() {
    this->clear();
    this->m_ImagePathList.clear();
    this->m_ImageList.clear();
}

void ImageListWidget::setTransformation(int index, int rotate) {
    QTransform transform;
    transform.rotate(rotate);
    m_ImageList[index] = m_ImageList[index].transformed(transform);
    this->item(index)->setIcon(QPixmap::fromImage(m_ImageList[index]).scaled(200, 200));
}

bool ImageListWidget::isEmpty()const {
    int count = this->count();
    return count == 0;
}

QImageList ImageListWidget:: getImageList() const {
    return m_ImageList;
}

void ImageListWidget::setImageList(const QImageList &imageList) {
    clearImageList();
    QString index;
    QListWidgetItem *pListItemWidget;
    int size = imageList.size();
    for(int i(0);i<size;i++){
        if(!imageList[i].isNull()){
            QIcon icon =QIcon(QPixmap::fromImage(imageList[i]).scaled(200,200));
            index = QString("%0").arg(i+1);
            pListItemWidget = new QListWidgetItem(icon,index, this);
            this->addItem(pListItemWidget);
            m_ImageList.append(imageList[i]);
            m_ImagePathList.append(index);
        }else{
            QMessageBox::warning(this,tr("警告"),tr("第%0张图片加载错误!")
                    .arg(i+1));
        }
    }
}




