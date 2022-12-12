#include "ofMain.h"
#include "ofxFaceTracker2.h"
 
class ofApp : public ofBaseApp {
 
public:
    void setup();
    void update();
    void draw();
 
    void keyPressed(int key) {};
    void keyReleased(int key) {};
    void mouseMoved(int x, int y) {};
    void mouseDragged(int x, int y, int button) {};
    void mousePressed(int x, int y, int button) {};
    void mouseReleased(int x, int y, int button) {};
    void mouseEntered(int x, int y) {};
    void mouseExited(int x, int y) {};
    void windowResized(int w, int h) {};
    void dragEvent(ofDragInfo dragInfo) {};
    void gotMessage(ofMessage msg) {};
 
    ofMesh mesh;
    ofImage mask;
    ofImage eye;
    ofImage nose;
    ofImage mouth;
    ofImage eye_left;
    ofImage eye_right;
    
    ofImage mouth_side;
    ofImage eye_left_side;
    ofImage nose_side;
    
    ofImage ear;
    ofImage ear1;
    
    ofVideoGrabber grabber;
    ofxFaceTracker2 tracker;
};
