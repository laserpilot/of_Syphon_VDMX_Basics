#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("ofxSyphon Example");
    ofSetFrameRate(60);
    
    mainOutputSyphonServer.setName("Syphon_Output");
    
    mClient.setup();
    
    //using Syphon app Simple Server, found at http://syphon.v002.info/
    mClient.set("SyphonToOF","VDMX5"); //App name, Server Name
    
    grabber.initGrabber(1280, 720);
    showVid = false;
    
    sender.setup("localhost", 1234); //can control VDMX with OSC or VDMX can control OF
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    ofxOscMessage m;
    m.setAddress("/mouseX");
    m.addFloatArg(ofMap(ofGetMouseX(),0, ofGetWidth(), 0,1));
    sender.sendMessage(m);
    
    ofxOscMessage t;
    t.setAddress("/mouseY");
    t.addFloatArg(ofMap(ofGetMouseY(),0, ofGetHeight(), 0,1));
    sender.sendMessage(t);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if (showVid) {
        ofSetColor(255);
        grabber.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    ofSetColor(200+55*sin(5*ofGetElapsedTimef()),150+100*sin(3*ofGetElapsedTimef()) );
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, 200+100*sin(3*ofGetElapsedTimef()));
    
    if (showClient) { //potential for feedback FX if drawn here...
        ofSetColor(255);
        mClient.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    
    mainOutputSyphonServer.publishScreen(); //will only capture things above this line
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='s') {
        showVid = !showVid;
    }else if(key=='k'){
        showClient = !showClient;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
