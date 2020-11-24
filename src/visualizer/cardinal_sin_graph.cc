#include <visualizer/cardinal_sin_graph.h>

namespace finalproject{

namespace visualizer {

CardinalSinGraph::CardinalSinGraph(const glm::vec2 &bottom_right_corner, size_t x_size, size_t y_size,
                                   const ci::Color &graph_color, size_t units, bool draw_labels, size_t cardinal_sin_power) :
                                   Graph(bottom_right_corner, x_size, y_size, graph_color, units, draw_labels),
                                   cardinal_sin_power_(cardinal_sin_power){}

void CardinalSinGraph::Draw(const Well &well, const Particle &particle) const {
    ci::gl::color(ci::Color(graph_color_));
    if(draw_labels_) {
        ci::gl::drawStringCentered("Momentum-Space Wavefunction Probability Distribution",
                                   glm::vec2(bottom_right_corner_.x + (x_size_ / 2),
                                             bottom_right_corner_.y - y_size_ - 10));
        ci::gl::drawLine(bottom_right_corner_, glm::vec2(bottom_right_corner_.x, bottom_right_corner_.y - y_size_));
        ci::gl::drawLine(bottom_right_corner_, glm::vec2(bottom_right_corner_.x + x_size_, bottom_right_corner_.y));
        ci::gl::drawStringCentered("L/2π", glm::vec2(bottom_right_corner_.x - 10, bottom_right_corner_.y - 100));
    }

    float x1, x2, y1, y2;
    float unit = well.GetLength()/units_;
    ci::gl::begin(GL_LINE_STRIP);
    for (double i=0;i<well.GetLength();i+=unit) {
        x1 = (float)i;
        x2 = ((float)i + unit);
        float term = k_term_*(i-well.GetLength()/2);
        y1 = -100*pow(sin(term)/term, cardinal_sin_power_);
        y2 = -100*pow(sin(term)/term, cardinal_sin_power_);
        x1/=unit;
        x2/=unit;
        ci::gl::vertex(x1+bottom_right_corner_.x, y1 +bottom_right_corner_.y);
        ci::gl::vertex(x2+bottom_right_corner_.x, y2+bottom_right_corner_.y);
    }
    ci::gl::end();

}

void CardinalSinGraph::SetKTerm(double k_term) {
    k_term_ = k_term;
}


void CardinalSinGraph::SetUnits(size_t units) {
    units_ = units;
}

void CardinalSinGraph::SetBottomRightCorner(const glm::vec2 &bottom_right_corner) {
    bottom_right_corner_ = bottom_right_corner;
}
}

}

