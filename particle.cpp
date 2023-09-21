#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace particle {
	Particle::Particle(): m_x(0), m_y(0) {
		// número entre -1 e -1
		// direção de 0 até 2*PI = 6.28 em radians
		init();
	};

	Particle::~Particle() {
	};

	void Particle::init() {
		m_x = 0;
		m_y = 0;
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.04 * rand()) / RAND_MAX;
		m_speed *= m_speed;
	}
	void Particle::update(int interval) {

		m_direction += interval * 0.0003;

		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		// x and y speed equivalent to the amount of time passed
		m_x += xspeed * interval;
		m_y += yspeed * interval;

		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
			init();
		}

		if (rand() < RAND_MAX / 100) {
			init();
		}
	}
}