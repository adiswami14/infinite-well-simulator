#include <visualizer/frame.h>

namespace finalproject{

namespace visualizer {

Frame::Frame(size_t frame_x_size, size_t frame_y_size,  const ci::Color &stroke_color, const ci::Color& fill_color):
frame_x_size_(frame_x_size), frame_y_size_(frame_y_size), stroke_color_(stroke_color), fill_color_(fill_color) {}

void Frame::SetFillColor(const ci::Color &fill_color) {
    fill_color_ = fill_color;
}

void Frame::SetStrokeColor(const ci::Color &stroke_color) {
    stroke_color_ = stroke_color;
}
}

}

