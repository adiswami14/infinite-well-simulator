#pragma once
#include <iostream>
#include <core/particle.h>
#include <core/well.h>
#include "cinder/gl/gl.h"
#include "graph.h"

namespace finalproject {

namespace visualizer {

/**
 * Class that represents a cardinal sin curve (sinc)
 */
class CardinalSinGraph: Graph {
public:
    /**
     * The constructor for the CardinalSinGraph class
     * @param bottom_right_corner The origin point of the graph
     * @param x_size The size of the graph horizontally
     * @param y_size The size of the graph vertically
     * @param graph_color The color of the graph
     * @param units The number of units on the graph
     * @param draw_labels Whether or not to draw the axes and titles of the graph
     * @param cardinal_sin_power The power to raise the cardinal sine curve to
     */
    CardinalSinGraph(const glm::vec2& bottom_right_corner, size_t x_size, size_t y_size, const ci::Color &graph_color, size_t units, bool draw_labels, size_t cardinal_sin_power);

    /**
     * Draws cardinal sine curve on screen
     * @param well The well of the simulation
     * @param particle Particle in the well
     */
    void Draw(const Well &well, const Particle& particle) const;

    /**
     * Sets the k-term variable to a desired value
     * @param k_term The desired k-term of the particle
     */
    void SetKTerm(double k_term);

    /**
     * Set the number of units in graph to desired amount
     * @param units The desired amount of units
     */
    void SetUnits(size_t units);

    /**
     * Sets the origin point of the graph to a new value
     * @param bottom_right_corner Desired value of the origin point of the graph
     */
    void SetBottomRightCorner(const glm::vec2 &bottom_right_corner);
private:
    size_t cardinal_sin_power_; //The power to raise the cardinal sine curve to
    double k_term_; //The k-term of the particle
};

}

}
