#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundColor(10, 10, 10);
	//////////TEXTURES//////////////////////////////
	ofDisableArbTex();
	ofEnableDepthTest();

	fire.getTexture().allocate(1024, 768, GL_RGB);
	fire.loadImage("fire3.jpg");
	fire.getTexture().generateMipmap();
	fire.getTexture().setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_NEAREST);


	torch.getTexture().allocate(1024, 1024, GL_RGB);
	torch.loadImage("torch4Texture.png");
	torch.getTexture().generateMipmap();
	torch.getTexture().setTextureMinMagFilter(GL_LINEAR_MIPMAP_LINEAR, GL_NEAREST);

	////////////////MODEL//////////////////////
	model.loadModel("torch4.obj");
	//model.setScale(1, -1, 1);
	model.setPosition(0, -10, 0);

	////////////////SOUND/////////////////////////////
	FireSound.loadSound("fire3.mp3");
	FireSound.setVolume(0.5);
	FireSound.play();
	FireSound.setLoop(true);


	////////////////CAMERA//////////////////////
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	//cam.setGlobalPosition(ofVec3f(600, 500));
	cam.setDistance(1200);
	emitter = new Emitter(ofVec3f(0, 0, 0));
	

}

//--------------------------------------------------------------
void ofApp::update(){

	emitter->particlesUpdate();
	emitter->particlesKiller();
	emitter->start();

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	emitter->particleDraw(&fire);

	torch.bind();
	model.drawFaces();
	torch.unbind();

	cam.end();
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






