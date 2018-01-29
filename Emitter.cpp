#include "Emitter.h"
#include <random>
#include <time.h>
#include <chrono>
Emitter::Emitter(ofVec3f pos) :pos(pos) {};

void Emitter::start()
{

	

		for (int z = pos[2]-1000; z <= pos[2] + 1000; z=z+40)
		{
			for (int x = pos[0]-1000; x <= pos[0] + 1000; x=x+40)
			{
				if(pow(z,2)+pow(x,2)<pow(100,2))
					particles.push_back(new CubicParticle(ofVec3f(x,0,z),10, 6));
			}
		}

}


void Emitter::particlesUpdate()
{
	for (auto i = 0; i <particles.size(); i++)
	{
		particles[i]->update(0.1, 9.8);
	}


}

void Emitter::particleDraw(ofImage* fire)
{

	for (int i = 0; i < particles.size(); i++)
	{
		particles[i]->draw(fire);
	}



}

int Emitter::getSize()
{
	return particles.size();


}

void Emitter::particlesKiller()
{

	for (int i = 0; i < particles.size(); i++)
	{
		if(particles[i]->getLifetime()<=0)
			particles.erase(particles.begin() + i);
	}


}