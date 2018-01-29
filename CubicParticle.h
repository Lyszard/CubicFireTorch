#pragma once
#include "ofMain.h"
#include <deque>
#include <iostream>

class CubicParticle
{
public:
	CubicParticle(ofVec3f pos, double edge, int mass);
	~CubicParticle();

	double  getX();
	double  getY();
	double  getZ();
	int  getEdge();
	int  getMass();
	void setLifetime(int a);
	void updateAge();
	int getLifetime();

	void draw(ofImage* fire);
	void update(double dt, double fn);
	ofVec3f WindForce();

private:
	deque<ofVec3f>  allPos;
	ofBoxPrimitive* cube;
	ofImage fire;
	int  edge;
	double impulse;
	int  mass;
	double angleX;
	double angleZ;
	int lifetime;
	int age;
	
};

