#include "CubicParticle.h"
#include <random>
#include <time.h>
using namespace std;

CubicParticle::CubicParticle(ofVec3f pos, double Edge, int Mass) :
	edge(Edge),
	mass(Mass),
	lifetime(50),
	angleX(0),
	impulse(0),
	angleZ(0)
	

{
	
	cube = new ofBoxPrimitive(getEdge(), getEdge(), getEdge());
	cube->setGlobalPosition(0, 0, 0);


	///////////STARTING POSITION//////////////////////
	this->allPos.push_back(pos);
	ofVec3f temp = pos;
	temp[0] += 0.0;
	temp[1] += 0.0;
	temp[2] += 0.0;
	this->allPos.push_back(temp);

	//////////RANDOM ANGLE////////////////
	angleX = ofRandom(-1.0, 1.0);
	angleX /= PI;
	angleZ = ofRandom(-1.0, 1.0);
	angleZ /= PI;
	impulse = ofRandom(0.0, 20.0);


}

CubicParticle::~CubicParticle()
{
	delete cube;
}

void CubicParticle::draw(ofImage* fire)
{
	///////////COLOR INTERPOLATION////////////
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofColor orange = ofColor(255, 135, 14);
	ofColor yellow = ofColor(250, 204, 18);
	ofColor inBetween;
	if (lifetime > 0)
	{
		inBetween = orange.lerp(yellow,  100/lifetime);
		ofSetColor(inBetween,lifetime*20);

	}
		
	ofFill();

	/////////////ADDING TEXTURE////////////////
	fire->bind();
	//ofDrawBox(getX(), getY(), getZ(), getEdge(), getEdge(), getEdge());
	cube->draw();
	fire->unbind();
}

void CubicParticle::update(double dt, double fn)
{

	///////////////MOVEMENT&FORCES///////////////////
	double g = fn;
	double tempX = 0;
	double tempY = 0;
	double tempZ = 0;
	ofVec3f temp = allPos[1];


	tempX = 2 * this->allPos[1][0] - allPos[0][0] + dt*dt*(g*sin(angleX)*WindForce()[1] / mass);
	tempY = 2 * this->allPos[1][1] - allPos[0][1] + dt*dt*(g *impulse/ mass);
	tempZ = 2 * this->allPos[1][2] - allPos[0][2] + dt*dt*(g*sin(angleZ)*WindForce()[1] / mass);
	temp[1] = tempY;
	temp[0] = tempX;
	temp[2] = tempZ;

	this->allPos.pop_front();
	this->allPos.push_back(temp);
	
	lifetime--;
	cube->setGlobalPosition(getX(), getY(), getZ());
	
}

ofVec3f CubicParticle::WindForce()
{
	ofVec3f WindPos;
	if (ofGetElapsedTimef() > 30)
		ofResetElapsedTimeCounter();
	double t=ofRandom((-ofGetElapsedTimef()-10)*10, (ofGetElapsedTimef()+10)*10);
	//double t = (ofGetElapsedTimef() + 1) * 5;
	WindPos[0] = exp(-pow(getX(), 2))*t;
	WindPos[1] = exp(-pow(getY(), 2))*t;
	WindPos[2] = exp(-pow(getZ(), 2))*t;

	return WindPos;

}

void CubicParticle::setLifetime(int a) { this->lifetime = a; }
void CubicParticle::updateAge() { this->age++; }
int CubicParticle::getLifetime() { return this->lifetime; }
double CubicParticle::getX() { return this->allPos[1][0]; }
double CubicParticle::getY() { return this->allPos[1][1]; }
double CubicParticle::getZ() { return this->allPos[1][2]; }
int    CubicParticle::getEdge() { return edge; }
int    CubicParticle::getMass() { return mass; }



