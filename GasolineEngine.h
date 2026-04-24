#pragma once

#include "Engine.h"

class GasolineEngine : public Engine {
public:
    std::string getName() override {
        return "GasolineEngine";
    }
};