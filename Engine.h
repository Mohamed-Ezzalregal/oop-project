#pragma once

#include <string>

class Engine {
protected:
    int speed;

public:
    Engine() {
        speed = 0;
    }

    virtual ~Engine() {
    }

    virtual std::string getName() = 0;

    void increase() {
        speed++;
    }

    void decrease() {
        if (speed > 0) {
            speed--;
        }
    }

    virtual void setSpeed(int carSpeed) {
        while (speed < carSpeed) {
            increase();
        }

        while (speed > carSpeed) {
            decrease();
        }
    }

    int getSpeed() {
        return speed;
    }
};