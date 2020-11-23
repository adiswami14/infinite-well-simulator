#include <visualizer/graph.h>

namespace finalproject {

namespace visualizer {

Graph::Graph(const glm::vec2& bottom_right_corner, size_t x_size, size_t y_size, const ci::Color &graph_color, size_t units, bool draw_labels, size_t sin_power) :
bottom_right_corner_(bottom_right_corner),x_size_(x_size), y_size_(y_size), graph_color_(graph_color), units_(units), draw_labels_(draw_labels), sin_power_(sin_power){}

void Graph::Draw(const Well &well, const Particle& particle) const {
    ci::gl::color(ci::Color(graph_color_));
    if(draw_labels_) {
        ci::gl::drawStringCentered("Probability Distribution for Wavefunction Graph",
                                   glm::vec2(bottom_right_corner_.x + (x_size_ / 2),
                                             bottom_right_corner_.y - y_size_ - 10));
        ci::gl::drawLine(bottom_right_corner_, glm::vec2(bottom_right_corner_.x, bottom_right_corner_.y - y_size_));
        ci::gl::drawLine(bottom_right_corner_, glm::vec2(bottom_right_corner_.x + x_size_, bottom_right_corner_.y));
        ci::gl::drawStringCentered("L/2",
                                   glm::vec2(bottom_right_corner_.x + (units_ / 2), bottom_right_corner_.y + 10));
        ci::gl::drawStringCentered("L", glm::vec2(bottom_right_corner_.x + units_, bottom_right_corner_.y + 10));
        ci::gl::drawStringCentered("2/L", glm::vec2(bottom_right_corner_.x - 10, bottom_right_corner_.y - 100));
    }
    float x1, x2, y1, y2;
    float unit = well.GetLength()/units_;
    ci::gl::begin(GL_LINE_STRIP);
    for (double i=0;i<well.GetLength();i+=unit) {
        x1 = (float)i;
        x2 = ((float)i + unit);
        y1 = -100*pow(sin((particle.energy_state_*x1/(well.GetLength())) * M_PI),sin_power_);
        y2 = -100*pow(sin((particle.energy_state_*x2/(well.GetLength())) * M_PI),sin_power_);
        x1/=unit;
        x2/=unit;
        ci::gl::vertex(x1+bottom_right_corner_.x, y1 +bottom_right_corner_.y);
        ci::gl::vertex(x2+bottom_right_corner_.x, y2+bottom_right_corner_.y);
    }
    ci::gl::end();
}

void Graph::SetUnits(size_t units) {
    units_ = units;
}

void Graph::SetBottomRightCorner(const glm::vec2 &bottom_right_corner) {
    bottom_right_corner_ = bottom_right_corner;
}

}

}

