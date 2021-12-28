#ifndef QTWINDOW_H
#define QTWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QToolBar>
#include <QInputDialog>
#include <QColorDialog>
#include "DrawFigures.h"
#include <list>
QT_BEGIN_NAMESPACE
namespace Ui { class QtWindow; }
QT_END_NAMESPACE

class QtWindow : public QMainWindow
{
    Q_OBJECT

public:
    QtWindow(QWidget *parent = nullptr);
    ~QtWindow();

private:
    Ui::QtWindow *ui;
    QToolBar *toolbar;
    QGraphicsScene* scene;
    QColor color;
    QString path;
public slots:
    void CreateCircle();
    void CreateTriangle();
    void CreateRectangle();
    void Delete();
};
#endif // QTWINDOW_H


