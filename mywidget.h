#ifndef MYWIDGET_H
#define MYWIDGET_H

#include "head.h"
#include "qevent.h"
#include "qgraphicsitem.h"
#include "qmutex.h"
#include "snake.h"
#include "target.h"
#include <QGraphicsView>
#include <Mutex>
#include <QDebug>

class MyWidget : public QGraphicsView
{
    Q_OBJECT

public:

    MyWidget(QWidget* parent) : QGraphicsView(parent) {

    }

    MyWidget(){

    }

    std::vector<Target*> getTargets(){
        return targets;
   }

    void addTargets(int n){

        for(int i = 0; i<n; i++){
            Target* tar = new Target();
            targets.push_back(tar);
        }

        for(auto tar : targets){
           this->scene()->addItem(tar);
        }

    }

    void setHead(){
        this->head = new Head();
        this->scene()->addItem(head);
    }
    Head* getHead(){

        return head;
    }

    ~MyWidget() = default;

    void deleteTarget(){

        this->scene()->removeItem(targets[0]);
        delete targets.back();
        targets.clear();
    }
    void incrScore(){
        score++;
    }
    int getScore(){
        return score;
    }
    void setSnake(){
        snake = new Snake(*this->scene(),*head, score);
    }
    void incTail(){
        snake->drawTail();
    }


private:
    std::vector<Target*> targets;

    Head* head = nullptr;

    int score = 0;

    Snake* snake = nullptr;

protected:

    void keyPressEvent(QKeyEvent *e) override {

        QGraphicsItem* item = nullptr;

        if(!this->scene()->selectedItems().empty())
            item = this->scene()->selectedItems().at(0);

        switch(e->key()){
        case Qt::Key_Left:{
            if(item != nullptr){

                QPointF newPos = item->scenePos() + QPointF(-20, 0);
                item->setPos(newPos);

                emit static_cast<Head*>(item)->positionChangedLeft();
            }
            break;
        }
        case Qt::Key_Right:{
            if(item != nullptr){

                QPointF newPos = item->scenePos() + QPointF(20, 0);
                item->setPos(newPos);

                emit static_cast<Head*>(item)->positionChangedRight();
            }
            break;
        }
        case Qt::Key_Down:{
            if(item != nullptr){

                QPointF newPos = item->scenePos() + QPointF(0, 20);
                item->setPos(newPos);

                emit static_cast<Head*>(item)->positionChangedDown();
            }
            break;
        }
        case Qt::Key_Up:{
            if(item != nullptr){

                QPointF newPos = item->scenePos() + QPointF(0, -20);
                item->setPos(newPos);

                emit static_cast<Head*>(item)->positionChangedUp();
            }
            break;
        }
        default:
            break;
        }
    }
};

#endif // MYWIDGET_H
