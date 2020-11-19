#pragma once

#include "well.h"
#include "particle.h"

namespace finalproject {

class ValueFinder {
public:
    const double kPlanckConstant = 6.626070040;

    ValueFinder();
    double FindExpectedXValue(const Well &well) const;
    double FindExpectedEnergyValue(const Particle &particle, const Well &well) const;
    double FindProbabilitySpread(const Particle &particle, const Well &well) const;
    double FindXValueSpread(const Particle &particle, const Well &well) const;
};

}
