#include <core/value_finder.h>

namespace finalproject {

ValueFinder::ValueFinder() {}

double ValueFinder::FindExpectedXValue(const Well &well) const {
    return ((well.GetLength()/2)+well.GetStartPos());
}

double ValueFinder::FindExpectedEnergyValue(const Particle &particle, const Well &well) const {
    double p_squared = FindProbabilitySpread(particle, well);
    return p_squared/(2*particle.mass_);
}

double ValueFinder::FindProbabilitySpread(const Particle &particle, const Well &well) const {
    double factor = particle.energy_state_*M_PI*kPlanckConstant;
    return (factor/well.GetLength());
}

double ValueFinder::FindXValueSpread(const Particle &particle, const Well& well) const {
    double square_root_denom_factor = 2*pow(particle.energy_state_*M_PI, 2);
    const double one_twelvth = 1.0/12.0;
    double sqrt_var = -1/square_root_denom_factor;
    sqrt_var+=one_twelvth;
    double square_root_factor = sqrt(sqrt_var);
    return well.GetLength()*square_root_factor;
}

}

