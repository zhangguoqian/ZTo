//
// Created by 11518 on 2023/4/23.
//

#ifndef QTO_PROJECT_IMAGETOPDFWIDGET_H
#define QTO_PROJECT_IMAGETOPDFWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class ImageToPdfWidget; }
QT_END_NAMESPACE

class ImageToPdfWidget : public QWidget {
Q_OBJECT

public:
    explicit ImageToPdfWidget(QWidget *parent = nullptr);

    ~ImageToPdfWidget() override;

private:
    Ui::ImageToPdfWidget *ui;

private slots:
    //! 选择图片
    void slotSelectImage();
    //! 清理图片列表
    void slotClearImageList();
    //! 转换为PDF
    void slotSavePdfClicked();
    //! 打开PDF目录
    static void slotOpenPdfDirClicked();

};


#endif //QTO_PROJECT_IMAGETOPDFWIDGET_H
