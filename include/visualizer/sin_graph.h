#pragma once
#include <iostream>
#include <core/particle.h>
#include <core/well.h>
#include "cinder/gl/gl.h"
#include "graph.h"

namespace finalproject {

namespace visualizer {

class SinGraph : Graph{
public:
    SinGraph(const glm::vec2& bottom_right_corner, size_t x_size, size_t y_size, const ci::Color &graph_color, size_t units, bool draw_labels, size_t sin_power);

    void Draw(const Well &well, const Particle& particle) const;

    void SetUnits(size_t units);

    void SetBottomRightCorner(const glm::vec2 &bottom_right_corner);
private:
    size_t sin_power_;

};

}

}