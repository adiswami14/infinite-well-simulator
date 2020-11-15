#include <visualizer/dynamic_frame.h>

namespace finalproject{

namespace visualizer {

DynamicFrame::DynamicFrame(size_t x_size, size_t y_size, size_t window_size) : Frame(x_size, y_size), window_size_(window_size){
    active_ = false;
    curr_x_ = window_size_;
}

void DynamicFrame::Update() {
    if(active_){
        if (curr_x_ >= window_size_ - 300) {
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
        ci::gl::color(ci::Color("green"));
        ci::gl::drawStrokedRect(rect);
        ci::gl::color(ci::Color("black"));
        ci::gl::drawSolidRect(rect);
    } else {
        if(curr_x_ < window_size_) {
            ci::Rectf rect(vec2(curr_x_, window_size_-frame_y_size_), vec2(window_size_, window_size_));
            ci::gl::color(ci::Color("green"));
            ci::gl::drawStrokedRect(rect);
            ci::gl::color(ci::Color("black"));
            ci::gl::drawSolidRect(rect);
        }
    }
}

void DynamicFrame::SetActive(bool active) {
    active_ = active;
}
}

}

