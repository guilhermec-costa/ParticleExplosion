#ifndef SWARM_H_
#define SWARM_H_

#include <iostream>
#include "Particle.h"
using namespace std;

namespace particle {
class Swarm {
public:
	const static int NPARTICLES = 10000;
private:
	// ponteiro constante
	Particle* mParticles;
	int lastTimeUpdated;
public:
	Swarm();
	~Swarm();
	Particle* const getParticle() { return mParticles; };
	void update(int timePassed);
};
}

#endif
