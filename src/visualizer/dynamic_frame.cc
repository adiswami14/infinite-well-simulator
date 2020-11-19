#include <visualizer/dynamic_frame.h>

namespace finalproject{

namespace visualizer {

DynamicFrame::DynamicFrame(size_t x_size, size_t y_size, size_t window_size, const ci::Color &stroke_color, const ci::Color& fill_color, bool is_right_to_left)
: Frame(x_size, y_size, stroke_color, fill_color), window_size_(window_size), right_to_left_(is_right_to_left){
    active_ = false;
    if(right_to_left_) {
        curr_x_ = window_size_;
    } else curr_x_ = 0;
}

void DynamicFrame::Update() {
    if(active_){
        if(right_to_left_) {
            if (curr_x_ >= window_size_ - frame_x_size_) {
                curr_x_ -= 10;
            }
        } else {
            if (curr_x_ <= frame_x_size_) {
                curr_x_ += 10;
            }
        }
    } else {
        if(right_to_left_) {
            if (curr_x_ <= window_size_) {
                curr_x_ += 10;
            }
        } else {
            if (curr_x_ >= 10) {
                curr_x_ -= 10;
            }
        }
    }
}

void DynamicFrame::Draw() {
    if(active_) {
        if(right_to_left_) {
            ci::Rectf rect(vec2(curr_x_, window_size_ - frame_y_size_), vec2(window_size_, window_size_));
            ci::gl::color(stroke_color_);
            ci::gl::drawStrokedRect(rect);
            ci::gl::color(fill_color_);
            ci::gl::drawSolidRect(rect);
        } else {
            ci::Rectf rect(vec2(0, window_size_-frame_y_size_), vec2(curr_x_, window_size_));
            ci::gl::color(fill_color_);
            ci::gl::drawSolidRect(rect);
            ci::gl::color(stroke_color_);
            ci::gl::drawStrokedRect(rect);
        }
    } else {
        if(right_to_left_ && curr_x_ < window_size_) {
            ci::Rectf rect(vec2(curr_x_, window_size_-frame_y_size_), vec2(window_size_, window_size_));
            ci::gl::color(stroke_color_);
            ci::gl::drawStrokedRect(rect);
            ci::gl::color(fill_color_);
            ci::gl::drawSolidRect(rect);
        } else if (!right_to_left_ && curr_x_>0) {
            ci::Rectf rect(vec2(0, window_size_-frame_y_size_), vec2(curr_x_, window_size_));
            ci::gl::color(fill_color_);
            ci::gl::drawSolidRect(rect);
            ci::gl::color(stroke_color_);
            ci::gl::drawStrokedRect(rect);
        }
    }
}

void DynamicFrame::SetActive(bool active) {
    active_ = active;
}

bool DynamicFrame::IsOpen() const {
    if(right_to_left_) {
        return (active_ && curr_x_ < window_size_ - frame_x_size_);
    }
    return (active_ && curr_x_ > frame_x_size_);
}
}

}

