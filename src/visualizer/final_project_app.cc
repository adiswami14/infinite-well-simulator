#include <visualizer/final_project_app.h>

namespace finalproject{

namespace visualizer {

using glm::vec2;

FinalProjectApp::FinalProjectApp() : well_(Well(100.0, 250.0)){
    ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void FinalProjectApp::update() {

}

void FinalProjectApp::draw() {
    ci::Color8u background_color(15, 15, 15);
    ci::gl::clear(background_color);
    ci::gl::color(ci::Color("green"));
    ci::gl::drawLine(vec2(0, kHeight), vec2(well_.GetStartPos(), kHeight));
    ci::gl::drawLine(vec2(well_.GetStartPos(), kHeight), vec2(well_.GetStartPos(), kWindowSize));
    ci::gl::drawLine(vec2(well_.GetEndPos(), kWindowSize), vec2(well_.GetEndPos(), kHeight));
    ci::gl::drawLine(vec2(well_.GetEndPos(), kHeight), vec2(kWindowSize, kHeight));
}

void FinalProjectApp::keyDown(ci::app::KeyEvent event) {

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
}

}