#ifndef DRAWFIGURES_H
#define DRAWFIGURES_H

#include <QGraphicsItem>
#include "Figure.h"
#include <QPainter>
#include <QCursor>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QToolTip>
#include <QStyleOptionGraphicsItem>

class FigureDraw : public QGraphicsItem
{
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    QPointF point;
    QPointF position;
    QColor color = QRgb(688590);

protected:
    QPainterPath path;
    QRectF bounding;
    Figure* figure;
    FigureDraw(QPoint position);
    void updateInfo();
public:
    virtual ~FigureDraw();
};

class CircleDraw : public FigureDraw
{
private:
    void setPaint();
public:
    CircleDraw(Circle circle, QPoint position);
    ~CircleDraw();
};

class TriangleDraw : public FigureDraw
{
private:
    void setPaint();
public:
    TriangleDraw(Triangle triangle, QPoint position);
    ~TriangleDraw();
};

class RectangleDraw : public FigureDraw
{
private:
    void setPaint();
public:
    RectangleDraw(Rectangle rectangle, QPoint position);
    ~RectangleDraw();
};

#endif // DRAWFIGURES_H
