#include <visualizer/static_frame.h>

namespace finalproject{

namespace visualizer {

StaticFrame::StaticFrame(const vec2& top_left_corner, const vec2& bottom_right_corner, const ci::Color &stroke_color, const ci::Color& fill_color) :
        Frame(bottom_right_corner.x - top_left_corner.x, bottom_right_corner.y - top_left_corner.y, stroke_color, fill_color),
        top_left_corner_(top_left_corner),
        bottom_right_corner_(bottom_right_corner){}

void StaticFrame::Draw() const {
    ci::Rectf rect(top_left_corner_, bottom_right_corner_);
    ci::gl::color(fill_color_);
    ci::gl::drawSolidRect(rect);
    ci::gl::color(stroke_color_);
    ci::gl::drawStrokedRect(rect);
}

void StaticFrame::SetStrokeColor(const ci::Color &stroke_color) {
    Frame::SetStrokeColor(stroke_color);
}

void StaticFrame::SetFillColor(const ci::Color& fill_color){
    Frame::SetFillColor(fill_color);
}

}

}