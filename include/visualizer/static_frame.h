#pragma once

#include "frame.h"
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer{

using glm::vec2;

class StaticFrame : Frame {
public:
    StaticFrame(const vec2& top_left_corner, const vec2& bottom_right_corner, const ci::Color& color);

    void Draw() const;

private:
    vec2 top_left_corner_;
    vec2 bottom_right_corner_;
    ci::Color color_;
};

}

}