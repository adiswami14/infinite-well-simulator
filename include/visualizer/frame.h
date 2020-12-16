#pragma once
#include <iostream>
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer {

/**
 * Basic frame class, which is extended into Static and Dynamic Frames
 */
class Frame{
public:
    /**
     * Constructor for Frame class
     * @param frame_x_size The horizontal width of the frame
     * @param frame_y_size The vertical height of the frame
     * @param stroke_color The color used to draw borders of frame
     * @param fill_color The color to fill in the rest of the frame with
     */
    Frame(size_t frame_x_size, size_t frame_y_size, const ci::Color &stroke_color, const ci::Color& fill_color);

    /**
     * Sets color of frame border
     * @param stroke_color The color of frame border
     */
    void SetStrokeColor(const ci::Color &stroke_color);

    /**
     * Sets color of frame itself
     * @param fill_color The color of frame itself
     */
    void SetFillColor(const ci::Color& fill_color);
protected:
    size_t frame_x_size_; //width of frame
    size_t frame_y_size_; //height of frame
    ci::Color stroke_color_; //frame border color
    ci::Color fill_color_; //frame fill color
};

}

}
