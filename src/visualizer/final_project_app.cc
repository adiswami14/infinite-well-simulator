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

    DrawXSpreadRectangle();

    top_frame_.Draw();
    simulation_info_frame_.Draw();
    expected_values_frame_.Draw();

    if(simulation_info_frame_.IsOpen()){
        DrawSimulationInfo();
    }
    if(expected_values_frame_.IsOpen()) {
        DrawExpectedValues();
    }

    ci::gl::color(ci::Color("white"));
    float x1, x2, y1, y2;
    float unit = well_.GetLength()/150;
    for (double i=0;i<well_.GetLength();i+=unit) {
        x1 = (float)i;
        x2 = ((float)i + unit);
        y1 = -100*pow(sin((particle_.energy_state_*x1/(well_.GetLength())) * M_PI),2);
        y2 = -100*pow(sin((particle_.energy_state_*x2/(well_.GetLength())) * M_PI),2);
        x1/=unit;
        x2/=unit;
        ci::gl::drawLine(vec2(x1+300, y1 + 150), vec2(x2+300, y2 + 150));
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
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindExpectedXValue(well_)), vec2(100, 300), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("<E> (Average Energy): ", vec2(100, 400), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindExpectedEnergyValue(particle_, well_))+"*10^-68 J", vec2(100, 450), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("Δp (Probability Spread): ", vec2(100, 550), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindProbabilitySpread(particle_, well_))+"*10^-34 kg * m/s", vec2(100, 600), ci::Color("white"), ci::Font("Arial", 15));

    ci::gl::drawStringCentered("Δx (X-Position Spread): ", vec2(100, 700), ci::Color("white"), ci::Font("Arial", 15));
    ci::gl::drawStringCentered(std::to_string(value_finder_.FindXValueSpread(particle_, well_))+" m", vec2(100, 750), ci::Color("white"), ci::Font("Arial", 15));
}

void FinalProjectApp::DrawXSpreadRectangle() const {
    ci::gl::enableAlphaBlending();
    double x_spread = value_finder_.FindXValueSpread(particle_, well_);
    double average_x = value_finder_.FindExpectedXValue(well_);
    ci::Rectf rect(vec2(average_x-(x_spread/2),200), vec2(average_x+(x_spread/2),kWindowSize));
    ci::gl::color(ci::ColorA( 0.3f, 0.1f, 0.6f, 0.5f));
    ci::gl::drawSolidRect(rect);
}
}

}