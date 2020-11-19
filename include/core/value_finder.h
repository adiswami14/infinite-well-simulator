#pragma once

#include "well.h"
#include "particle.h"

namespace finalproject {

class ValueFinder {
public:
    const double kPlanckConstant = 6.626070040e-34;

    ValueFinder();
    double FindExpectedXValue(const Well &well);
    double FindExpectedEnergyValue(const Particle &particle, const Well &well);
};

}
