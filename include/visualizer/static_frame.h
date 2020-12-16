#pragma once

#include "frame.h"
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer{

using glm::vec2;

/**
 * A frame that doesn't change at all during course of simulation
 */
class StaticFrame : Frame {
public:
    /**
     * Constructor of StaticFrame class
     * @param top_left_corner The top left corner of the frame
     * @param bottom_right_corner The bottom right corner of the frame
     * @param stroke_color Border color of the frame
     * @param fill_color Fill color of the frame
     */
    StaticFrame(const vec2& top_left_corner, const vec2& bottom_right_corner, const ci::Color &stroke_color, const ci::Color& fill_color);

    /**
     * Draws the rectangle representing the frame, and shades with the appropriate colors
     * This type of frame doesn't require Update, since nothing about it changes
     */
    void Draw() const;

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
private:
    vec2 top_left_corner_; //top left corner of the frame
    vec2 bottom_right_corner_; //bottom right corner of the frame
};

}

}
