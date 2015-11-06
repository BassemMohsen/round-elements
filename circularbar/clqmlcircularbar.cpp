#include "clqmlcircularbar.h"

clQmlCircularBar::clQmlCircularBar(QQuickPaintedItem *parent) :
    QQuickPaintedItem(parent)
{
    __horizontalDepth = 10;
    __start_angle = 180;
    __span_angle = 0;
    __color = "white";
    __barImage = QImage("bar_active.png");

    //update painting of the shape upon changes of properties.
    connect(this, SIGNAL(colorChanged()), this, SLOT(update()));
    connect(this, SIGNAL(depthChanged()), this, SLOT(update()));
    connect(this, SIGNAL(startAngleChanged()), this, SLOT(update()));
    connect(this, SIGNAL(spanAngleChanged()), this, SLOT(update()));
    connect(this, SIGNAL(progressChanged()), this, SLOT(update()));
}

void clQmlCircularBar::paint(QPainter *painter)
{
    //AntiAliasing
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::HighQualityAntialiasing);
    painter->setRenderHint(QPainter::SmoothPixmapTransform);

    QRectF rect = this->boundingRect();
    painter->setPen(Qt::NoPen);

    QPainterPath slicePath(QPointF(rect.width()/2, rect.height()/2));
    slicePath.lineTo(0, rect.height()/2);
    slicePath.arcTo(rect, __start_angle, __span_angle);
    slicePath.lineTo(rect.width()/2, rect.height()/2);
    slicePath.closeSubpath();

    painter->setClipRegion(slicePath.toFillPolygon().toPolygon());
    painter->drawImage(rect,__barImage);
}
