#pragma once

#include "Car.h"
#include "ElectronicEngine.h"
#include "EngineType.h"
#include "GasolineEngine.h"
#include "MixedHybridEngine.h"

class CarFactory {
public:
    static Engine* createEngine(EngineType type) {
        if (type == GASOLINE) {
            return new GasolineEngine();
        }

        if (type == ELECTRONIC) {
            return new ElectronicEngine();
        }

        return new MixedHybridEngine();
    }

    static Car* createCar(EngineType type) {
        return new Car(createEngine(type));
    }

    static void replaceCarEngine(Car* car, EngineType type) {
        car->replaceEngine(createEngine(type));
    }
};