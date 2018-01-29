#pragma once
#include <iostream>
#include "ofMain.h"
#include <vector>
#include "CubicParticle.h"

class Emitter
{
	public:
		Emitter(ofVec3f pos);
		void start();
		void particlesUpdate();
		void particleDraw(ofImage* fire);
		void particlesKiller();
		int getSize();
		

	private:
		ofVec3f pos;
		vector<CubicParticle*> particles;








};

