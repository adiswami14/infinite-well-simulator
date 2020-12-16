#pragma once

#include "well.h"
#include "particle.h"

namespace finalproject {

/**
 * Class that finds the expected values of the simulation
 */
class ValueFinder {
public:
    const double kPlanckConstant = 6.626070040; //constant representing the Planck's Constant

    /**
     * Default constructor for the ValueFinder class
     */
    ValueFinder();

    /**
     * Finds the average x-position of the particle in the well
     * @param well The infinite well in question
     * @return The average x-position of a particle in the well
     */
    double FindExpectedXValue(const Well &well) const;

    /**
     * Finds expected energy value of particle in the well
     * @param particle The particle whose data is being used to compute the energy
     * @param well The infinite well in question
     * @return Expected energy value
     */
    double FindExpectedEnergyValue(const Particle &particle, const Well &well) const;

    /**
     * Finds the maximum spread of momentum (how much error there is possibly)
     * @param particle The particle in the well
     * @param well The infinite well where the simulation is taking place
     * @return The spread of momentum
     */
    double FindMomentumSpread(const Particle &particle, const Well &well) const;

    /**
     * Finds the maximum spread of x-position
     * @param particle The particle in the well
     * @param well The infinite well where the simulation is taking place
     * @return The spread of x-position
     */
    double FindXValueSpread(const Particle &particle, const Well &well) const;

    /**
     * Find the k-term of the particle
     * @param particle The particle in question
     * @param well The infinite well where the simulation is taking place
     * @return The expected k-value of the particle
     */
    double FindExpectedKValue(const Particle &particle, const Well &well) const;
};

}
