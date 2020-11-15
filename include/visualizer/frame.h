#pragma once
#include <iostream>
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer {

class Frame{
public:
    Frame(size_t frame_x_size, size_t frame_y_size, const ci::Color &stroke_color, const ci::Color& fill_color);
protected:
    size_t frame_x_size_;
    size_t frame_y_size_;
    ci::Color stroke_color_;
    ci::Color fill_color_;
};

}

}
