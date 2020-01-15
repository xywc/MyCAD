#ifndef SLICE_H
#define SLICE_H

#include <QDialog>
#include "DocumentCommon.h"
#include <QVector3D>
namespace Ui {
class Slice;
}

class Slice : public QDialog
{
    Q_OBJECT

public:
    enum SliceDirection{Slice_X=0,Slice_Y=1,Slice_Z=2};
    explicit Slice(QWidget *parent = nullptr);
    ~Slice();
    void setData(Handle(TopTools_HSequenceOfShape) aSequence,DocumentCommon *doc,SliceDirection sd=Slice_Z);
private slots:
    void on_pushButton_clicked(bool checked);

    void on_checkBox_stateChanged(int arg1);

    void on_verticalSlider_valueChanged(int value);

    void on_comboBox_currentIndexChanged(int index);

private:
    void getPlaneSet(const Bnd_Box &box);
private:
    Ui::Slice *ui;
    Handle(TopTools_HSequenceOfShape) aSequence;
    DocumentCommon *doc;
    double thickness = 0;
    gp_Dir normal;//slice direction
    QVector<QVector3D> planeset;
    SliceDirection sd;
    QVector<int> sliceindex;

    Handle(AIS_InteractiveContext) myContext;
    View *openGLWidget;
    Handle(V3d_Viewer) aViewer;
};

#endif // SLICE_H
