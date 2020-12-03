#include <visualizer/final_project_app.h>

namespace finalproject{

namespace visualizer {

using glm::vec2;
using namespace cinder::app;


FinalProjectApp::FinalProjectApp() : well_(Well(300.0, 450.0)),
top_frame_(vec2(0,0), vec2(kWindowSize, 200), ci::Color("green"), ci::Color("black")),
bottom_frame_(vec2(0,700), vec2(kWindowSize, kWindowSize), ci::Color("green"), ci::Color("black")),
simulation_info_frame_(300, 700, kWindowSize, ci::Color("green"), ci::Color("black"), true),
expected_values_frame_(200, 700, kWindowSize, ci::Color("green"), ci::Color("black"), false),
wavefunction_prob_dist_graph_(vec2(150, 160), 500, 140, ci::Color("white"), 500, true, 2),
wavefunction_graph_(vec2(well_.GetStartPos(), kHeight), well_.GetLength(), 75, ci::Color("white"), well_.GetLength(), false, 1),
momentum_wavefunction_graph_(vec2(well_.GetStartPos(), kHeight), well_.GetLength(), 75, ci::Color("orange"), well_.GetLength(), false, 1),
momentum_prob_dist_graph_(vec2(150, 860), 500, 140, ci::Color("white"), 500, true, 2){
    ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
    instruction_menu_ = true;
}

void FinalProjectApp::update() {
    simulation_info_frame_.Update();
    expected_values_frame_.Update();
    wavefunction_graph_.SetUnits(well_.GetLength());
    wavefunction_graph_.SetBottomRightCorner(vec2(well_.GetStartPos(), kHeight));
    momentum_wavefunction_graph_.SetKTerm(value_finder_.FindExpectedKValue(particle_, well_));
    momentum_prob_dist_graph_.SetKTerm(value_finder_.FindExpectedKValue(particle_, well_));
    momentum_wavefunction_graph_.SetUnits(well_.GetLength());
    momentum_wavefunction_graph_.SetBottomRightCorner(vec2(well_.GetStartPos(), kHeight));
}

void FinalProjectApp::draw() {
    ci::Color8u background_color(15, 15, 15);
    ci::gl::clear(background_color);
    if(instruction_menu_) {
        DrawInstructionsMenu();
    } else {
        ci::Rectf left_rect(vec2(0, kHeight), vec2(well_.GetStartPos(), kWindowSize));
        ci::Rectf right_rect(vec2(well_.GetEndPos(), kHeight), vec2(kWindowSize, kWindowSize));
        ci::gl::color(ci::Color("green"));
        ci::gl::drawStrokedRect(left_rect);
        ci::gl::drawStrokedRect(right_rect);

        ci::gl::color(ci::Color("yellow"));
        ci::gl::drawLine(vec2(value_finder_.FindExpectedXValue(well_), 200),
                         vec2(value_finder_.FindExpectedXValue(well_), kWindowSize));

        DrawXSpreadRectangle();
        wavefunction_graph_.Draw(well_, particle_);
        momentum_wavefunction_graph_.Draw(well_, particle_);

        //code below draws the dashed line from one end of well to another
        ci::gl::color(ci::Color("white"));
        ci::gl::begin(GL_LINES);
        float step = 0.01f;
        for (float x = well_.GetStartPos(); x < well_.GetEndPos(); x += step) {
            ci::gl::vertex(x, kHeight);
        }
        ci::gl::end();

        top_frame_.Draw();
        simulation_info_frame_.Draw();
        expected_values_frame_.Draw();


        if (simulation_info_frame_.IsOpen()) {
            DrawSimulationInfo();
        }
        if (expected_values_frame_.IsOpen()) {
            DrawExpectedValues();
        }

        bottom_frame_.Draw();
        wavefunction_prob_dist_graph_.Draw(well_, particle_);
        momentum_prob_dist_graph_.Draw(well_, particle_);
    }
}

void FinalProjectApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_a:
            expected_values_frame_.SetActive(true);
            break;
        case ci::app::KeyEvent::KEY_s:
            expected_values_frame_.SetActive(false);
            break;
        case ci::app::KeyEvent::KEY_SPACE:
            if(instruction_menu_) {
                instruction_menu_ = false;
            } else instruction_menu_ = true;
            break;
        case ci::app::KeyEvent::KEY_DOWN:
            simulation_info_frame_.SetActive(true);
            break;
        case ci::app::KeyEvent::KEY_UP:
            simulation_info_frame_.SetActive(false);
            break;
        case ci::app::KeyEvent::KEY_RIGHT:
            if(simulation_info_frame_.IsOpen()) {
                particle_.energy_state_++;
            }
            break;
        case ci::app::KeyEvent::KEY_LEFT:
            if(particle_.energy_state_>1 && simulation_info_frame_.IsOpen()) {
                particle_.energy_state_--;
            }
            break;
        case ci::app::KeyEvent::KEY_PERIOD:
            if(simulation_info_frame_.IsOpen()) {
                particle_.mass_ += 0.5;
            }
            break;
        case ci::app::KeyEvent::KEY_COMMA:
            if(particle_.mass_>0.5 && simulation_info_frame_.IsOpen()) {
                particle_.mass_ -= 0.5;
            }
            break;
    }
}

void FinalProjectApp::mouseDown(ci::app::MouseEvent event) {

}

void FinalProjectApp::mouseDrag(ci::app::MouseEvent event) {
    if(abs(event.getX()-well_.GetStartPos()) <= 10) {
        well_.SetStartPos(event.getX());
    }
    else if(abs(event.getX()-well_.GetEndPos()) <= 10) {
        well_.SetEndPos(event.getX());
    }
}

void FinalProjectApp::DrawSimulationInfo() const {
    ci::gl::drawStringCentered("Infinite Well", vec2(730, 250), ci::Color("white"), ci::Font("Arial", 30));
    ci::gl::drawStringCentered("Well Length", vec2(730, 300), ci::Color("white"), ci::Font("Arial", 20));

    ci::gl::drawStringCentered(std::to_string(well_.GetLength()), vec2(730, 320), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered("Particle in Well", vec2(730, 380), ci::Color("white"), ci::Font("Arial", 30));

    double particle_color;
    if(particle_.energy_state_ <= 25) {
        particle_color = 255-(particle_.energy_state_*10);
    } else particle_color = 3.0;
    ci::gl::color(ci::Color((float)particle_color/255+((float)(particle_.mass_*10)/255), (float)particle_color/255, (float)particle_color/255+((float)(particle_.mass_*10)/255)));
    ci::gl::drawSolidCircle(vec2(730, 450), 20);

    ci::gl::drawStringCentered("Particle Energy State", vec2(730, 500), ci::Color("white"), ci::Font("Arial", 20));
    ci::gl::drawStringCentered(std::to_string(particle_.energy_state_), vec2(730, 530), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("Particle Mass", vec2(730, 570), ci::Color("white"), ci::Font("Arial", 20));
    ci::gl::drawStringCentered(std::to_string(particle_.mass_), vec2(730, 600), ci::Color("white"), ci::Font("Arial", 15));
}

void FinalProjectApp::DrawExpectedValues() const {
    ci::gl::drawStringCentered("<x> (Average X-Position): ", vec2(100, 250), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindExpectedXValue(well_)), vec2(100, 300), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("<E> (Average Energy): ", vec2(100, 350), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindExpectedEnergyValue(particle_, well_))+"*10^-68 J", vec2(100, 400), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("Δp (Momentum Spread): ", vec2(100, 450), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindMomentumSpread(particle_, well_)) + "*10^-34 kg * m/s", vec2(100, 500), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("Δx (X-Position Spread): ", vec2(100, 550), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindXValueSpread(particle_, well_))+" m", vec2(100, 600), ci::Color("white"), ci::Font("Arial", 15));
}

void FinalProjectApp::DrawXSpreadRectangle() const {
    ci::gl::enableAlphaBlending();
    double x_spread = value_finder_.FindXValueSpread(particle_, well_);
    double average_x = value_finder_.FindExpectedXValue(well_);
    ci::Rectf rect(vec2(average_x-(x_spread/2),200), vec2(average_x+(x_spread/2),kWindowSize));
    ci::gl::color(ci::ColorA( 0.3f, 0.1f, 0.6f, 0.5f));
    ci::gl::drawSolidRect(rect);
}

void FinalProjectApp::DrawInstructionsMenu() const {
    ci::gl::drawStringCentered("Instructions", vec2(450, 70), ci::Color("white"), ci::Font("Arial", 45));
    ci::gl::drawStringCentered("SPACE BAR - Bring Up/Down Instructions Menu", vec2(450, 130), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("Particle:", vec2(450, 200), ci::Color("white"), ci::Font("Arial", 25));
    ci::gl::drawStringCentered("↑/↓ - Toggle the simulation info panel and edit particle", vec2(450, 240), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered("→/← - Increase/Decrease particle energy state", vec2(450, 300), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered("PERIOD/COMMA - Increase/Decrease particle mass", vec2(450, 360), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("Well:", vec2(450, 420), ci::Color("white"), ci::Font("Arial", 25));
    ci::gl::drawStringCentered("Being near any of the well edges and dragging it can edit the well for you", vec2(450, 480), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("Expected Values:", vec2(450, 600), ci::Color("white"), ci::Font("Arial", 25));
    ci::gl::drawStringCentered("a/s - Toggle expected value panel", vec2(450, 660), ci::Color("white"), ci::Font("Arial", 15));
}
}

}