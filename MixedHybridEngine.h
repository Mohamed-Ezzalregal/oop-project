#pragma once

#include <string>

#include "ElectronicEngine.h"
#include "GasolineEngine.h"

class MixedHybridEngine : public Engine {
private:
    GasolineEngine gasEngine;
    ElectronicEngine electricEngine;
    std::string currentEngine;

public:
    MixedHybridEngine() {
        currentEngine = "ElectronicEngine";
    }

    std::string getName() override {
        return "MixedHybridEngine";
    }

    void setSpeed(int carSpeed) override {
        if (carSpeed < 50) {
            electricEngine.setSpeed(carSpeed);
            gasEngine.setSpeed(0);
            currentEngine = electricEngine.getName();
            speed = electricEngine.getSpeed();
        } else {
            gasEngine.setSpeed(carSpeed);
            electricEngine.setSpeed(0);
            currentEngine = gasEngine.getName();
            speed = gasEngine.getSpeed();
        }
    }

    std::string getCurrentEngine() {
        return currentEngine;
    }

    int getGasSpeed() {
        return gasEngine.getSpeed();
    }

    int getElectricSpeed() {
        return electricEngine.getSpeed();
    }
};