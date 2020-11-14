#pragma once
#include <iostream>

namespace finalproject {

namespace visualizer {

class Frame{
public:
    Frame(size_t frame_x_size, size_t frame_y_size);
protected:
    size_t frame_x_size_;
    size_t frame_y_size_;
};

}

}
