#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include "abstractitem.h"
#include "head.h"

class Snake : public QObject, public AbstractItem
{
    Q_OBJECT;

private:
    Head* head = nullptr;
    int* length = nullptr;
    QGraphicsRectItem* bodyItem;

    std::vector<QGraphicsRectItem*> tail;

    QGraphicsScene* scene;

    QPointF prevHeadPos;
    QPointF initHeadPos; // first pos

    void tailPart(){
        qreal x = initHeadPos.x(),y = initHeadPos.y();

        bodyItem = new QGraphicsRectItem();

        bodyItem->setFlag(QGraphicsItem::ItemIsMovable, true);
        bodyItem->setRect(x,y,50,50);

        bodyItem->setX(x);
        bodyItem->setY(y);
        bodyItem->setPos(x, y);

        b.setStyle(Qt::SolidPattern);
        b.setColor(QColor(250,0,200,200));
        bodyItem->setBrush(b);

        tail.push_back(bodyItem);
        scene->addItem(bodyItem);

    }

    void moveParts(){
        // move all parts from back to front
        for (int i = 0; i < tail.size()-1; ++i){
            tail[i]->setPos(tail[i+1]->pos());
        }
        // move front part to previous position of the head
        tail.back()->setPos(prevHeadPos);
    }

public:
    Snake();
    Snake(QGraphicsScene &scene,Head &head, int& score){
        this->head = &head;
        this->length = &score;
        this->scene = &scene;

        connect(&head, &Head::positionChangedRight, this, &Snake::onHeadPosChangedRight);
        connect(&head, &Head::positionChangedLeft, this, &Snake::onHeadPosChangedLeft);
        connect(&head, &Head::positionChangedUp, this, &Snake::onHeadPosChangedUp);
        connect(&head, &Head::positionChangedDown, this, &Snake::onHeadPosChangedDown);

        prevHeadPos = head.scenePos();
        initHeadPos = head.scenePos();
    }
    void drawTail(){
         tailPart();
    }
    ~Snake(){
        for(auto& bodyItem : tail)
            delete bodyItem;
    }
public slots:
    void onHeadPosChangedRight(){

        prevHeadPos = head->scenePos();

        // move items
        if(tail.size() > 0)
             moveParts();
    }
    void onHeadPosChangedLeft(){

        prevHeadPos = head->scenePos();

        // move items
        if(tail.size() > 0)
            moveParts();
    }
    void onHeadPosChangedDown(){

        prevHeadPos = head->scenePos();

        // move items
        if(tail.size() > 0)
            moveParts();
    }
    void onHeadPosChangedUp(){

        prevHeadPos = head->scenePos();
        // move items
        if(tail.size() > 0)
            moveParts();

    }
};

#endif // SNAKE_H
