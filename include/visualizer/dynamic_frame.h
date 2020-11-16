#pragma once

#include "frame.h"
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer {

using glm::vec2;

/**
 * A frame that moves over the course of the simulation
 */
class DynamicFrame: Frame {
public:
    /**
     * Constructor for DynamicFrame class
     * @param x_size The width of the frame
     * @param y_size The height of the frame
     * @param window_size The size of the Cinder window the frame is being drawn in
     * @param stroke_color The border color of the frame
     * @param fill_color The fill color of the frame
     */
    DynamicFrame(size_t x_size, size_t y_size, size_t window_size, const ci::Color &stroke_color, const ci::Color& fill_color);

    /**
     * Updates the x position of the frame so the frame can come in and out of the windo
     */
    void Update();

    /**
     * Draws current version of the frame at a specific instance
     */
    void Draw();

    /**
     * Sets the value of the active parameter, checking if frame is in the process of opening up or closing down
     * @param active The value of the parameter we wish to set it to
     */
    void SetActive(bool active);

    /**
     * Checks if the active variable is true and if the current x-position is at the desired x-position
     * @return Whether or not the frame is open
     */
    bool IsOpen() const;
private:
    size_t curr_x_; //current x-position of the frame
    size_t window_size_; //size of the Cinder window that the frame is drawn in
    bool active_; //whether or not the frame is being opened or closed
};

}

}
