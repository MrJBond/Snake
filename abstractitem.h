#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include "qbrush.h"
#include <QGraphicsItem>
#include <random>
#include <functional>
#include <QObject>


class AbstractItem
{

protected:
    QBrush b;

    int randomGenerator() {
        std::uniform_int_distribution<int> dice_distribution(30, 300);
        // Seed the random number engine with current time
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 random_number_engine(seed); // pseudorandom number generator
        auto dice_roller = std::bind(dice_distribution, random_number_engine);
        int random_roll = dice_roller();  // Generate one of the integers 30-300
        return random_roll;
    }
public:
    AbstractItem();
};

#endif // ABSTRACTITEM_H
