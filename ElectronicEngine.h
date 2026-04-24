#pragma once

#include "Engine.h"

class ElectronicEngine : public Engine {
public:
    std::string getName() override {
        return "ElectronicEngine";
    }
};