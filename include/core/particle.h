#pragma once
#include <iostream>

namespace finalproject {

/**
 * A struct that contains the mass and energy state of the particle
 */
struct Particle {
public:
    /**
     * Default constructor for Particle class
     */
    Particle();

    double mass_; //mass of the particle
    size_t energy_state_; //energy state of the particle
};

}
