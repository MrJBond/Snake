#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include "qgraphicsview.h"
#include <QThread>
#include "mywidget.h"
#include <QMutex>


class GameThread : public QThread
{
    Q_OBJECT; // for signals

private:
    MyWidget* view;

public:
    GameThread(MyWidget& view) : view(&view), stop(false) {}

    // Game
    void run() override {

        view->addTargets(1);

        while (!stop) {
            if (view && view->scene()) {

                auto headItems = view->scene()->selectedItems(); // to get the head
                if (!headItems.isEmpty()) {
                    auto head = headItems.first(); // The head
                    QList<QGraphicsItem*> items = view->scene()->collidingItems(head); // collision
                    for (auto item : items) {
                        if (dynamic_cast<Target*>(item)) {
                            emit targetReached(); // The target has been reached
                        }
                    }
                }

            }

            msleep(100); // Add a short sleep to avoid busy-waiting
        }
    }

    bool stop;

signals:
    void targetReached();
};

#endif // GAMETHREAD_H
