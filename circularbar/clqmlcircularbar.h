#ifndef CLQMLCIRCULARBAR_H
#define CLQMLCIRCULARBAR_H

#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>

class clQmlCircularBar : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle NOTIFY startAngleChanged)
    Q_PROPERTY(qreal spanAngle READ getSpanAngle WRITE setSpanAngle NOTIFY spanAngleChanged)
    Q_PROPERTY(int depth READ depth WRITE setDepth NOTIFY depthChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int progress READ progress WRITE setProgress NOTIFY progressChanged)


public:
    clQmlCircularBar(QQuickPaintedItem *parent=0);

    void paint(QPainter *painter);

    int getStartAngle() {return __start_angle;}
    qreal getSpanAngle() {return __span_angle;}
    QColor color() {return __color;}
    int depth() {return __horizontalDepth;}
    int progress() {return __progress;}

    void setStartAngle(int angle) {__start_angle = angle;this->update();}
    void setSpanAngle(qreal angle) {__span_angle = angle;this->update();}
    void setColor(QColor color) {__color = color;this->update();}
    void setDepth(int depth) {__horizontalDepth = depth;this->update();}

    void setProgress(int progress){__span_angle = - 3.6 * progress; this->update();}

signals:
    void colorChanged();
    void depthChanged();
    void startAngleChanged();
    void spanAngleChanged();
    void progressChanged();

public slots:

private:
    int __start_angle;
    qreal __span_angle;
    int __horizontalDepth;
    QColor __color;
    QImage __barImage;
    int __progress;
};

#endif // CLQMLCIRCULARBAR_H
