#include <visualizer/dynamic_frame.h>

namespace finalproject{

namespace visualizer {

DynamicFrame::DynamicFrame(size_t x_size, size_t y_size, size_t window_size, const ci::Color &stroke_color, const ci::Color& fill_color)
: Frame(x_size, y_size, stroke_color, fill_color), window_size_(window_size){
    active_ = false;
    curr_x_ = window_size_;
}

void DynamicFrame::Update() {
    if(active_){
        if (curr_x_ >= window_size_ - frame_x_size_) {
            curr_x_ -= 10;
        }
    } else {
        if (curr_x_ <= window_size_) {
            curr_x_ += 10;
        }
    }
}

void DynamicFrame::Draw() {
    if(active_) {
        ci::Rectf rect(vec2(curr_x_, window_size_-frame_y_size_), vec2(window_size_, window_size_));
        ci::gl::color(stroke_color_);
        ci::gl::drawStrokedRect(rect);
        ci::gl::color(fill_color_);
        ci::gl::drawSolidRect(rect);
    } else {
        if(curr_x_ < window_size_) {
            ci::Rectf rect(vec2(curr_x_, window_size_-frame_y_size_), vec2(window_size_, window_size_));
            ci::gl::color(stroke_color_);
            ci::gl::drawStrokedRect(rect);
            ci::gl::color(fill_color_);
            ci::gl::drawSolidRect(rect);
        }
    }
}

void DynamicFrame::SetActive(bool active) {
    active_ = active;
}

bool DynamicFrame::IsOpen() const {
    return (active_ && curr_x_ < window_size_-frame_x_size_);
}
}

}

