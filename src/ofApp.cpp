#include "ofApp.h"
#include "XboxGamePad.hpp"

float radian = 0.0f;

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
	xbox::update();

	if(xbox::isTrigger(0, XINPUT_GAMEPAD_LEFT_SHOULDER)) {
		printf("trigger !");
	}
	ofVec2f stick(xbox::stick_L_x(0), xbox::stick_L_y(0));
	ofVec2f stick_prev(xbox::stick_L_x_prev(0), xbox::stick_L_y_prev(0));

	if(xbox::trigger_L(0) > 0.5f) {
		float from = atan2(stick_prev.y, stick_prev.x);
		float to = atan2(stick.y, stick.x);
		radian += (to - from);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(0);
	
	ofPushMatrix();

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateZ(ofRadToDeg(radian));
	ofRect(-100, -100, 200, 200);

	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}