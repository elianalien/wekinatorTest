#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    sender.setup(HOST, PORT);
    ofBackground(128, 128, 128);
    
    ofTrueTypeFont::setGlobalDpi(72);
    
    roboto.load("Roboto-Thin.ttf", 20);
    roboto.setLineHeight(22);
    roboto.setSpaceSize(1.3);
    
    receiver.setup(12000);
}

//--------------------------------------------------------------
void ofApp::update(){

    while (receiver.hasWaitingMessages()) {
        ofxOscMessage message;
        receiver.getNextMessage(message);
        
        if (message.getAddress() == "/wek/outputs") {
            oR = message.getArgAsFloat(0);
            oG = message.getArgAsFloat(1);
            oB = message.getArgAsFloat(2);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    roboto.drawString("Mouse X: ", 100, 100);
    roboto.drawString("Mouse Y: ", 100, 200);
    
    ofSetColor(255, 255, 255);
    roboto.drawString(sX, 200, 100);
    roboto.drawString(sY, 200, 200);
    
    std::string R = std::to_string(oR);
    std::string G = std::to_string(oG);
    std::string B = std::to_string(oB);
    
    ofSetColor(oR, oG, oB);
    roboto.drawString("WK output: ", 100, 300);
    roboto.drawString(R, 100, 400);
    roboto.drawString(G, 200, 400);
    roboto.drawString(B, 300, 400);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    sX = std::to_string(x);
    sY = std::to_string(y);
    
    ofxOscMessage message;
    message.setAddress("/wek/inputs");
    message.addFloatArg(x);
    message.addFloatArg(y);
    sender.sendMessage(message, false);
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
