#pragma once

#include <iostream>
#include <string>

#include "CarFactory.h"

class Main {
private:
    static void printCarInfo(Car* car, std::string title) {
        std::cout << title << std::endl;
        std::cout << "Car speed: " << car->getSpeed() << " km/h" << std::endl;
        std::cout << "Engine name: " << car->getEngine()->getName() << std::endl;
        std::cout << "Engine speed: " << car->getEngine()->getSpeed() << " km/h" << std::endl;

        MixedHybridEngine* hybrid = dynamic_cast<MixedHybridEngine*>(car->getEngine());
        if (hybrid != nullptr) {
            std::cout << "Current working engine: " << hybrid->getCurrentEngine() << std::endl;
            std::cout << "Gas engine speed: " << hybrid->getGasSpeed() << " km/h" << std::endl;
            std::cout << "Electric engine speed: " << hybrid->getElectricSpeed() << " km/h" << std::endl;
        }

        std::cout << "----------------------" << std::endl;
    }

    static void testCar(EngineType type, std::string carName) {
        Car* car = CarFactory::createCar(type);

        std::cout << std::endl << carName << std::endl;
        car->start();
        printCarInfo(car, "After start");

        car->accelerate();
        printCarInfo(car, "After first accelerate");

        car->accelerate();
        printCarInfo(car, "After second accelerate");

        car->accelerate();
        printCarInfo(car, "After third accelerate");

        car->brake();
        printCarInfo(car, "After brake");

        car->stop();
        printCarInfo(car, "After stop");

        delete car;
    }

public:
    static void run() {
        testCar(GASOLINE, "Testing Gasoline Car");
        testCar(ELECTRONIC, "Testing Electronic Car");
        testCar(HYBRID, "Testing Mixed Hybrid Car");

        Car* myCar = CarFactory::createCar(GASOLINE);
        myCar->start();
        myCar->accelerate();
        printCarInfo(myCar, "Before replacing engine");

        CarFactory::replaceCarEngine(myCar, HYBRID);
        printCarInfo(myCar, "After replacing engine");

        myCar->accelerate();
        myCar->accelerate();
        myCar->accelerate();
        printCarInfo(myCar, "After driving with new engine");

        delete myCar;
    }
};