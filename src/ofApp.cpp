#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    syphonInputFbo.allocate(640, 480);
    
    // SYPHON //
    syServer.setName("VCR Output");
    syClient.setup();
    syClient.set("toVCR #1", "Millumin2");
    
    
    
    // SHADER //
    vcrShader.setup(640, 480, GL_RGB32F);
    vcrShader.load("Bad_TV.fs");
    vcrShader.setImage(syphonInputFbo.getTexture());
    
    // OSC //
    oscRec.setup(6667);

    
    // GUI //
    setupGui();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    vcrShader.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    syphonInputFbo.begin();
    ofBackground(0);
    syClient.draw(0,0);
    syphonInputFbo.end();
    
    vcrShader.draw(0, 0);
    
    syServer.publishScreen();
    
    guiPanel.draw();
}



void ofApp::setupGui(){
    
    guiPanel.setup();

    shaderParams.setName("Shader Params");
    shaderParams.add(noise.set("Noise", 0.5,0,1));
    shaderParams.add(distortion1.set("Distort 1", 1,0,5));
    shaderParams.add(distortion2.set("Distort 2", 1,0,5));
    shaderParams.add(speed.set("Speed", 0.3,0,1));
    shaderParams.add(scroll.set("Scroll", 0,0,1));
    shaderParams.add(scanLineThickness.set("Line Thickness", 25,1,50));
    shaderParams.add(scanLineIntensity.set("Line Intensity", 0.5,0,1));
    shaderParams.add(scanLineOffset.set("Line Offset", 0,0,1));
    guiPanel.add(shaderParams);

    noise.addListener(this, &ofApp::setNoise);
    distortion1.addListener(this, &ofApp::setDist1);
    distortion2.addListener(this, &ofApp::setDist2);
    speed.addListener(this, &ofApp::setSpeed);
    scroll.addListener(this, &ofApp::setScroll);
    scanLineThickness.addListener(this, &ofApp::setLineThick);
    scanLineIntensity.addListener(this, &ofApp::setLineIntense);
    scanLineOffset.addListener(this, &ofApp::setLineOffset);
}



void ofApp::setShaderParam(ShaderParams param, float amt){
    switch (param) {
        case SHDR_NOISE:
            vcrShader.setUniform<float>("noiseLevel",amt);
            break;
        case SHDR_DIST1:
            vcrShader.setUniform<float>("distortion1", amt);
            break;
        case SHDR_DIST2:
            vcrShader.setUniform<float>("distortion2", amt);
            break;
        case SHDR_SPEED:
            vcrShader.setUniform<float>("speed", amt);
            break;
        case SHDR_SCROLL:
            vcrShader.setUniform<float>("scroll", amt);
            break;
        case SHDR_LINETHICK:
            vcrShader.setUniform<float>("scanLineThickness", amt);
            break;
        case SHDR_LINEINTENSE:
            vcrShader.setUniform<float>("scanLineIntensity", amt);
            break;
        case SHDR_LINEOFFSET:
            vcrShader.setUniform<float>("scanLineOffset", amt);
            break;
            
        default:
            break;
    }
    
};



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
