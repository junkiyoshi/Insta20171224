#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofNoFill();
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int deg_span = 10;
	float radius = 0;
	float radius_default = 30;
	float radius_span = 5;
	int layer = 12;
	float x, y, z;
	float noise_value;

	for (int deg = 0; deg < 360 - deg_span; deg += deg_span) {
		radius = radius_default;
		for (int i = 0; i < layer; i++) {

			noise_value = ofNoise(i, deg * 0.005 + ofGetFrameNum() * 0.015);
			ofSetColor(255, 255 * noise_value);
			if (noise_value < 0.8) {
				noise_value = 0.8;
			}

			ofBeginShape();

			for (int tmp_deg = deg; tmp_deg <= deg + deg_span; tmp_deg += 1) {
				x = radius * cos(tmp_deg * DEG_TO_RAD);
				y = radius * sin(tmp_deg * DEG_TO_RAD);
				z = noise_value * 40;
				ofVertex(x, y, z);
			}

			for (int tmp_deg = deg + deg_span; tmp_deg >= deg; tmp_deg -= 1) {
				x = (radius + radius_span) * cos(tmp_deg * DEG_TO_RAD);
				y = (radius + radius_span) * sin(tmp_deg * DEG_TO_RAD);
				z = noise_value * 40;
				ofVertex(x, y, z);
			}

			ofEndShape(true);

			radius += radius_span;
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}