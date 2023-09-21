#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <iostream>
#include "Screen.h"
using namespace std;

namespace particle {
struct Particle: public Screen
{
	double m_x;
	double m_y;

private:
	void init();
private:
	double m_speed;
	double m_direction;

public:
	Particle();
	~Particle();
	void update(int interval);

};


}

#endif
