#pragma once

#include "frame.h"
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer {

using glm::vec2;

class DynamicFrame: Frame {
public:
    DynamicFrame(size_t x_size, size_t y_size, size_t window_size);

    void Update();

    void Draw();

    void SetActive(bool active);
private:
    size_t curr_x_;
    size_t window_size_;
    bool active_;
};

}

}
