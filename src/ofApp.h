#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "ofxGui.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"
#include "ofxISF.h"

enum ShaderParams{
    SHDR_NOISE,
    SHDR_DIST1,
    SHDR_DIST2,
    SHDR_SPEED,
    SHDR_SCROLL,
    SHDR_LINETHICK,
    SHDR_LINEINTENSE,
    SHDR_LINEOFFSET
    
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
private:
    ofxSyphonClient syClient;
    ofxSyphonServer syServer;
    
    ofxPanel guiPanel;
    ofParameter<float> noise;
    ofParameter<float> distortion1;
    ofParameter<float> distortion2;
    ofParameter<float> speed;
    ofParameter<float> scroll;
    ofParameter<float> scanLineThickness;
    ofParameter<float> scanLineIntensity;
    ofParameter<float> scanLineOffset;
    ofParameterGroup shaderParams;


    
    ofxISF::Shader vcrShader;
    ofFbo syphonInputFbo;
    void setShaderParam(ShaderParams param, float amt);
    
    ofxOscReceiver oscRec;
    
    void setupGui();
    
    
    // Callbax //
    void setNoise(float & amt){
        setShaderParam(SHDR_NOISE, amt);
    };
    void setDist1(float & amt){
        setShaderParam(SHDR_DIST1, amt);
    }
    void setDist2(float & amt){
        setShaderParam(SHDR_DIST2, amt);
    }
    void setSpeed(float & amt){
        setShaderParam(SHDR_SPEED, amt);
    }
    void setScroll(float & amt){
        setShaderParam(SHDR_SCROLL, amt);
    }
    void setLineThick(float & amt){
        setShaderParam(SHDR_LINETHICK, amt);
    }
    void setLineIntense(float & amt){
        setShaderParam(SHDR_LINEINTENSE, amt);
    }
    void setLineOffset(float & amt){
        setShaderParam(SHDR_LINEOFFSET, amt);
    }
};
