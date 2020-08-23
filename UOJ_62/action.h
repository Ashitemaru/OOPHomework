#pragma once

#include "animal.h"

void action(Animal* animal, std::vector<Dog>& dogzone, std::vector<Bird>& birdzone) {
    if (dynamic_cast<Dog*>(animal) == nullptr) {
        birdzone.push_back(std::move(*dynamic_cast<Bird*>(animal)));
    } else {
        dogzone.push_back(std::move(*dynamic_cast<Dog*>(animal)));
    }
}