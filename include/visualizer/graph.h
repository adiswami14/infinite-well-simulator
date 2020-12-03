#pragma once
#include <iostream>
#include <core/particle.h>
#include <core/well.h>
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer {

/**
 * Overarching class that represents a graph in this simulation
 */
class Graph {
public:
    /**
     * The constructor for the graph class
     * @param bottom_right_corner The origin point of the graph
     * @param x_size The size of the graph horizontally
     * @param y_size The size of the graph vertically
     * @param graph_color The color of the graph
     * @param units The number of units on the graph
     * @param draw_labels Whether or not to draw the axes and titles of the graph
     */
    Graph(const glm::vec2& bottom_right_corner, size_t x_size, size_t y_size, const ci::Color &graph_color, size_t units, bool draw_labels);

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
protected:

    glm::vec2 bottom_right_corner_; //Origin point of graph
    size_t x_size_; //Horizontal size of graph
    size_t y_size_; //Vertical size of graph
    ci::Color graph_color_; //color of graph
    size_t units_; //number of units in graph
    bool draw_labels_; //whether or not to draw labels
};
}
}