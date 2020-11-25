#pragma once
#include <iostream>
#include <core/particle.h>
#include <core/well.h>
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer {

class Graph {
public:
    Graph(const glm::vec2& bottom_right_corner, size_t x_size, size_t y_size, const ci::Color &graph_color, size_t units, bool draw_labels);
protected:
    void Draw(const Well &well, const Particle& particle) const;

    void SetUnits(size_t units);

    void SetBottomRightCorner(const glm::vec2 &bottom_right_corner);

    glm::vec2 bottom_right_corner_;
    size_t x_size_;
    size_t y_size_;
    ci::Color graph_color_;
    size_t units_;
    bool draw_labels_;
};
}
}