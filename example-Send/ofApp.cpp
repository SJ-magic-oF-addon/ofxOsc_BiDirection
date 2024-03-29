/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp()
: Osc_Mouse("127.0.0.1", 12345, -1)
, Osc_key("127.0.0.1", 12346, -1)
, Osc_Various("127.0.0.1", 12347, -1)
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
	ofSetWindowTitle("OSC send");
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAntiAliasing();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA); // OF_BLENDMODE_DISABLED, OF_BLENDMODE_ALPHA, OF_BLENDMODE_ADD
}

//--------------------------------------------------------------
void ofApp::update(){
	if(b_SendMousePos){
		ofxOscMessage m;
		m.setAddress("/MousePos");
		m.addFloatArg(mouseX);
		m.addFloatArg(mouseY);
		
		Osc_Mouse.OscSend.sendMessage(m);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			ofxOscMessage m;
			m.setAddress("/key");
			m.addIntArg(key - '0');
			
			Osc_key.OscSend.sendMessage(m);
		}
			
			break;
			
		case 'v':
		{
			ofxOscMessage m;
			m.setAddress("/various");
			m.addStringArg("saijo");
			m.addFloatArg(1.23);
			m.addIntArg(999);
			m.addStringArg("nobuhiro");
			m.addFloatArg(2.45);
			m.addIntArg(777);
			m.addStringArg("michael");
			m.addFloatArg(3.79);
			m.addIntArg(555);
			
			Osc_Various.OscSend.sendMessage(m);
		}
			break;
			
		case  ' ':
			b_SendMousePos = !b_SendMousePos;
			printf("b_SendMousePos = %d\n", b_SendMousePos);
			fflush(stdout);
			break;
	}
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
