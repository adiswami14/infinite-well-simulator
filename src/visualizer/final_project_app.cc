#include <visualizer/final_project_app.h>

namespace finalproject{

namespace visualizer {

using glm::vec2;

FinalProjectApp::FinalProjectApp() : well_(Well(100.0, 250.0)),
top_frame_(vec2(0,0), vec2(kWindowSize, 200), ci::Color("green")),
side_panel_frame_(300, 700, kWindowSize){
    ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void FinalProjectApp::update() {
    side_panel_frame_.Update();
}

void FinalProjectApp::draw() {
    ci::Color8u background_color(15, 15, 15);
    ci::gl::clear(background_color);
    ci::gl::color(ci::Color("green"));
    ci::gl::drawLine(vec2(0, kHeight), vec2(well_.GetStartPos(), kHeight));
    ci::gl::drawLine(vec2(well_.GetStartPos(), kHeight), vec2(well_.GetStartPos(), kWindowSize));
    ci::gl::drawLine(vec2(well_.GetEndPos(), kWindowSize), vec2(well_.GetEndPos(), kHeight));
    ci::gl::drawLine(vec2(well_.GetEndPos(), kHeight), vec2(kWindowSize, kHeight));

    top_frame_.Draw();
    side_panel_frame_.Draw();
}

void FinalProjectApp::keyDown(ci::app::KeyEvent event) {
    if(event.getCode() == ci::app::KeyEvent::KEY_DOWN) {
        side_panel_frame_.SetActive(true);
    }
    if(event.getCode() == ci::app::KeyEvent::KEY_UP) {
        side_panel_frame_.SetActive(false);
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
}

}