#include <core/particle.h>

namespace finalproject {

Particle::Particle() {
    mass_ = 1;
    energy_state_ = 1;
}

Particle::Particle(double mass, size_t energy_state) {
    if(mass <=0 || energy_state<=0) {
        throw std::invalid_argument("Mass and/or energy state can only be positive values!");
    }
    mass_ = mass;
    energy_state_ = energy_state;
}

}