#pragma once

#include <core/well.h>
#include <core/particle.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace finalproject {

namespace visualizer {

/**
* The class that extends Cinder and acts as a GUI
*/
class FinalProjectApp : public ci::app::App {
public:
    const double kWindowSize = 900;//size of the Cinder window
    const double kHeight = 500;

    /**
     * Default constructor for this class
     */
    FinalProjectApp();

    void draw() override;
    void update() override;
    void keyDown(ci::app::KeyEvent event) override;
    void mouseDown(ci::app::MouseEvent event) override;
    void mouseDrag(ci::app::MouseEvent event) override;
private:
    Well well_;
    Particle particle_;
    bool edit_particle_frame_;
    size_t particle_frame_x_;
};

} //namespace visualizer

} //namespace finalproject
