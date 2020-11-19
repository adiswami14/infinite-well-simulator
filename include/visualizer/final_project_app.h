#pragma once

#include <core/well.h>
#include <core/particle.h>
#include <core/value_finder.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "static_frame.h"
#include "dynamic_frame.h"

namespace finalproject {

namespace visualizer {

/**
* The class that extends Cinder and acts as a GUI
*/
class FinalProjectApp : public ci::app::App {
public:
    const double kWindowSize = 900; //size of the Cinder window
    const double kHeight = 500; //y-value at which the infinite well is drawn

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
    /**
     * Draws info on the well length, and info of the particle in the well (energy state, mass)
     */
    void DrawSimulationInfo() const;

    void DrawExpectedValues() const;

    Well well_; //instance of Well in the simulation
    Particle particle_; //the Particle in the Well
    StaticFrame top_frame_; //The static frame at the top of the screen, used for the graph of wavefunction
    DynamicFrame simulation_info_frame_; //The dynamic side panel for displaying simulation information
    DynamicFrame expected_values_frame_; //The dynamic side panel for displaying expected values
    ValueFinder value_finder_;
};

} //namespace visualizer

} //namespace finalproject
