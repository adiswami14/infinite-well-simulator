#include <visualizer/final_project_app.h>

namespace finalproject{

namespace visualizer {

using glm::vec2;
using namespace cinder::app;


FinalProjectApp::FinalProjectApp() : well_(Well(100.0, 250.0)),
top_frame_(vec2(0,0), vec2(kWindowSize, 200), ci::Color("green"), ci::Color("black")),
simulation_info_frame_(300, 700, kWindowSize, ci::Color("green"), ci::Color("black"), true),
expected_values_frame_(200, 700, kWindowSize, ci::Color("green"), ci::Color("black"), false){
    ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void FinalProjectApp::update() {
    simulation_info_frame_.Update();
    expected_values_frame_.Update();
}

void FinalProjectApp::draw() {
    ci::Color8u background_color(15, 15, 15);
    ci::gl::clear(background_color);
    ci::gl::color(ci::Color("green"));
    ci::gl::drawLine(vec2(0, kHeight), vec2(well_.GetStartPos(), kHeight));
    ci::gl::drawLine(vec2(well_.GetStartPos(), kHeight), vec2(well_.GetStartPos(), kWindowSize));
    ci::gl::drawLine(vec2(well_.GetEndPos(), kWindowSize), vec2(well_.GetEndPos(), kHeight));
    ci::gl::drawLine(vec2(well_.GetEndPos(), kHeight), vec2(kWindowSize, kHeight));

    ci::gl::color(ci::Color("yellow"));
    ci::gl::drawLine(vec2(value_finder_.FindExpectedXValue(well_), 200), vec2(value_finder_.FindExpectedXValue(well_), kWindowSize));

    top_frame_.Draw();
    simulation_info_frame_.Draw();
    expected_values_frame_.Draw();

    if(simulation_info_frame_.IsOpen()){
        DrawSimulationInfo();
    }
    if(expected_values_frame_.IsOpen()) {
        DrawExpectedValues();
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
    if(abs(event.getX()-well_.GetStartPos()) <= 5) {
        well_.SetStartPos(event.getX());
    }
    else if(abs(event.getX()-well_.GetEndPos()) <= 5) {
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
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindExpectedXValue(well_))+" m", vec2(100, 300), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("<E> (Average Energy): ", vec2(100, 400), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindExpectedEnergyValue(particle_, well_))+"*10^-34 J", vec2(100, 450), ci::Color("white"), ci::Font("Arial", 15));
}
}

}