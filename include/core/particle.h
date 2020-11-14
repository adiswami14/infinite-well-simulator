#pragma once
#include <iostream>

namespace finalproject {

struct Particle {
public:
    Particle();
    Particle(double mass, size_t energy_state);
    double mass_;
    size_t energy_state_;
};

}
