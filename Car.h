#pragma once

#include "Engine.h"

class Car {
private:
    Engine* engine;
    int speed;

public:
    Car(Engine* engine) {
        this->engine = engine;
        speed = 0;
    }

    ~Car() {
        delete engine;
    }

    void replaceEngine(Engine* newEngine) {
        delete engine;
        engine = newEngine;
        speed = 0;
        engine->setSpeed(0);
    }

    void start() {
        speed = 0;
        engine->setSpeed(speed);
    }

    void stop() {
        speed = 0;
        engine->setSpeed(speed);
    }

    void accelerate() {
        if (speed < 200) {
            speed += 20;
            if (speed > 200) {
                speed = 200;
            }
        }

        engine->setSpeed(speed);
    }

    void brake() {
        if (speed > 0) {
            speed -= 20;
            if (speed < 0) {
                speed = 0;
            }
        }

        engine->setSpeed(speed);
    }

    int getSpeed() {
        return speed;
    }

    Engine* getEngine() {
        return engine;
    }
};