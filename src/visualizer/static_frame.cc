#include <visualizer/static_frame.h>

namespace finalproject{

namespace visualizer {

StaticFrame::StaticFrame(const vec2& top_left_corner, const vec2& bottom_right_corner, const ci::Color& color) :
        Frame(bottom_right_corner.x - top_left_corner.x, bottom_right_corner.y - top_left_corner.y),
        top_left_corner_(top_left_corner),
        bottom_right_corner_(bottom_right_corner),
        color_(color){}

void StaticFrame::Draw() const {
    ci::Rectf rect(top_left_corner_, bottom_right_corner_);
    ci::gl::color(ci::Color("black"));
    ci::gl::drawSolidRect(rect);
    ci::gl::color(color_);
    ci::gl::drawStrokedRect(rect);
}

}

}