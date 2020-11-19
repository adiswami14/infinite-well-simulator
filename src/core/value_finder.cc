#include <core/value_finder.h>

namespace finalproject {

ValueFinder::ValueFinder() {}

double ValueFinder::FindExpectedXValue(const Well &well) {
    return ((well.GetLength()/2)+well.GetStartPos());
}

double ValueFinder::FindExpectedEnergyValue(const Particle &particle, const Well &well) {
    double numerator_factor = particle.energy_state_*M_PI*kPlanckConstant;
    double length_squared = pow(well.GetLength(),2);
    return (pow(numerator_factor, 2)/(2*particle.mass_*length_squared));
}

}

