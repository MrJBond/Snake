#ifndef TARGET_H
#define TARGET_H

#include "abstractitem.h"
#include <QGraphicsEllipseItem>

class Target : public QGraphicsEllipseItem, AbstractItem
{

public:
    Target(){

        qreal x = randomGenerator();
        qreal y = randomGenerator();

        this->setRect(x,y,50,50);
        this->setX(x);
        this->setY(y);

        b.setStyle(Qt::SolidPattern);
        b.setColor(QColor(255,10,10,207));
        this->setBrush(b);

        this->setPos(x, y);
    }
};

#endif // TARGET_H
