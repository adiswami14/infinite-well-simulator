#pragma once

#include <core/well.h>
#include <core/particle.h>
#include <core/value_finder.h>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "static_frame.h"
#include "dynamic_frame.h"
#include "sin_graph.h"
#include "cardinal_sin_graph.h"

namespace finalproject {

namespace visualizer {

/**
* The class that extends Cinder and acts as a GUI
*/
class FinalProjectApp : public ci::app::App {
public:
    const double kWindowSize = 900; //size of the Cinder window
    const double kHeight = 350; //y-value at which the infinite well is drawn

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

    /**
     * Draws the expected values of the energy, x-position, x-spread and momentum-spread on the screen
     */
    void DrawExpectedValues() const;

    /**
     * Draws the possible x-spread around the average value of x-position
     */
    void DrawXSpreadRectangle() const;

    /**
     * Draws the instructions menu for the simulation
     */
    void DrawInstructionsMenu() const;

    /**
     * Draws the actual entire simulation
     */
    void DrawSimulation();

    /**
     * Changes the coloring of all frames and graphs to reflect a lighter tone
     */
    void SetLightMode();

    /**
     * Changes the coloring of all frames and graphs to reflect a darker tone
     */
    void SetDarkMode();

    /**
     * Used to set the text color in the information dynamicFrame panels
     * @return What color the text should be based on lighting mode of the simulation
     */
    ci::Color GetTextColor() const;

    Well well_; //instance of Well in the simulation
    Particle particle_; //the Particle in the Well
    StaticFrame top_frame_; //The static frame at the top of the screen, used for the graph of spatial wavefunction
    StaticFrame bottom_frame_; //Static frame at bottom of screen, for graph of momentum wavefunction
    DynamicFrame simulation_info_frame_; //The dynamic side panel for displaying simulation information
    DynamicFrame expected_values_frame_; //The dynamic side panel for displaying expected values
    ValueFinder value_finder_; //value finder instance to get expected values
    SinGraph wavefunction_prob_dist_graph_; //The sin graph representing the probability distribution of the spatial wavefunction
    SinGraph wavefunction_graph_; //The sin graph representing the spatial wavefunction itself
    CardinalSinGraph momentum_wavefunction_graph_; //The sin graph representing the momentum-space wavefunction
    CardinalSinGraph momentum_prob_dist_graph_; //The sin graph representing the probability distribution of the momentum wavefunction
    bool instruction_menu_; //just checks if instruction menu should be drawn at current moment
    bool dark_mode_; //checks if the simulation is in dark mode or not
};

} //namespace visualizer

} //namespace finalproject
