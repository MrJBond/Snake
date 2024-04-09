#ifndef HEAD_H
#define HEAD_H

#include "abstractitem.h"
#include "qgraphicsscene.h"
#include "qnamespace.h"
#include <QGraphicsEllipseItem>
#include <QKeyEvent>

class Head : public QObject, public QGraphicsRectItem, public AbstractItem
{

    Q_OBJECT;

public:
    Head(){

        qreal x = randomGenerator();
        qreal y = randomGenerator();

        this->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
        this->setFlag(QGraphicsItem::ItemIsSelectable, true);
        this->setSelected(true);
        this->setFlag(QGraphicsItem::ItemIsMovable, true);
        this->setRect(x,y,50,50);

        this->setX(x);
        this->setY(y);
        this->setPos(x, y);

        b.setStyle(Qt::SolidPattern);
        b.setColor(QColor(250,0,200,200));
        this->setBrush(b);
    }



signals:
    void positionChangedRight();
    void positionChangedLeft();
    void positionChangedUp();
    void positionChangedDown();

};

#endif // HEAD_H
