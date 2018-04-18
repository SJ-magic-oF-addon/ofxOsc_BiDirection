/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp()
: Osc("127.0.0.1", 12346, 12345)
{
}

/******************************
******************************/
ofApp::~ofApp()
{
}

/******************************
******************************/
void ofApp::exit()
{
	printf("Good-bye\n");
}

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("OSC receive");
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	

}

//--------------------------------------------------------------
void ofApp::update(){
	/********************
	********************/
	while(Osc.OscReceive.hasWaitingMessages()){
		ofxOscMessage m_receive;
		Osc.OscReceive.getNextMessage(&m_receive);
		
		if(m_receive.getAddress() == "/MousePos"){
			OSC_mouseX = m_receive.getArgAsFloat(0);
			OSC_mouseY = m_receive.getArgAsFloat(1);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	ofBackground(30);
	
	/********************
	********************/
	ofSetColor(255);
	
	char buf[BUF_SIZE];
	sprintf(buf, "(%7.2f, %7.2f)", OSC_mouseX, OSC_mouseY);
	ofDrawBitmapString(buf, 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
