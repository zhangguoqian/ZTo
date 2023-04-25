//
// Created by 11518 on 2023/4/24.
//

#ifndef QTO_PROJECT_PDFTOIMAGEWIDGET_H
#define QTO_PROJECT_PDFTOIMAGEWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>


QT_BEGIN_NAMESPACE
namespace Ui { class PdfToImageWidget; }
QT_END_NAMESPACE

class PdfToImageWidget : public QWidget {
Q_OBJECT
protected:
    void showEvent(QShowEvent *event) override;

public:
    explicit PdfToImageWidget(QWidget *parent = nullptr);

    ~PdfToImageWidget() override;
private slots:
    void slotOpenPdfClicked();
    void slotSaveImageClicked();
    void slotClearImageList();
private:
    Ui::PdfToImageWidget *ui;
    QString m_PdfFileName;
};


#endif //QTO_PROJECT_PDFTOIMAGEWIDGET_H
