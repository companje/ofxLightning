#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(60);
	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();
	
	mouseDown = false;
}

//--------------------------------------------------------------
void testApp::update(){
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(0, 0, 0, 25);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	
	if (mouseDown)
	{
		bolt.setup(boltX, 0, mouseX, mouseY, 6, ofRandom(80, 100), 0.04);
		bolt.parse();
		bolt.draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

	mouseDown = true;
	boltX = ofRandomWidth();
//	bolt.setup(boltX, 0, mouseX, mouseY, 6, ofRandom(90, 110), 0.3);
//	bolt.parse();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

	mouseDown = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

