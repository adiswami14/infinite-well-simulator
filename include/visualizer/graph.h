#pragma once
#include <iostream>
#include <core/particle.h>
#include <core/well.h>
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer {

class Graph {
public:
    const size_t kUnits = 150;

    Graph(glm::vec2 bottom_right_corner, size_t x_size, size_t y_size, const ci::Color &graph_color);

    void Draw(const Well &well, const Particle& particle) const;
private:
    glm::vec2 bottom_right_corner_;
    size_t x_size_;
    size_t y_size_;
    ci::Color graph_color_;
};

}

}