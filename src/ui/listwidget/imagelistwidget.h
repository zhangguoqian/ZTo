//
// Created by 11518 on 2023/4/23.
//

#ifndef QTO_PROJECT_IMAGELISTWIDGET_H
#define QTO_PROJECT_IMAGELISTWIDGET_H

#include <QListWidget>
#include <QDebug>
#include <QMessageBox>
#include <QImageWriter>

typedef QList<QImage> QImageList;


class ImageListWidget : public QListWidget{
    Q_OBJECT
public:
    explicit ImageListWidget(QWidget *parent = nullptr);
    ~ImageListWidget() override;
    //! 设置图片列表路径
    void setImagePathList(const QStringList &imagePathList);
    //! 设置图片列表
    void setImageList(const QImageList &imagePath);
    //! 获取图片列表
    QImageList getImageList() const;
    //! 清理图片列表
    void clearImageList();
    //! 是否位空
    bool isEmpty() const;

private:
    void setTransformation(int index,int rotate);

private:
    QStringList m_ImagePathList;
    QImageList m_ImageList;
};


#endif //QTO_PROJECT_IMAGELISTWIDGET_H
