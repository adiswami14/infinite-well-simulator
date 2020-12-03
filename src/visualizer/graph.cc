#include <visualizer/graph.h>

namespace finalproject {

namespace visualizer {

Graph::Graph(const glm::vec2 &bottom_right_corner, size_t x_size, size_t y_size, const ci::Color &graph_color,
             size_t units, bool draw_labels) : bottom_right_corner_(bottom_right_corner), x_size_(x_size), y_size_(y_size),
             graph_color_(graph_color), units_(units), draw_labels_(draw_labels){}

void Graph::SetUnits(size_t units) {
    units_ = units;
}

void Graph::SetBottomRightCorner(const glm::vec2 &bottom_right_corner) {
    bottom_right_corner_ = bottom_right_corner;
}
}


}

