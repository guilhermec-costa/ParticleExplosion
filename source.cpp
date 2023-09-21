#include <iostream>
#include <math.h>
#include <SDL.h>
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"
#include <time.h>
#include <stdlib.h>
using namespace std;
using namespace particle;

/*
argc: argument counter
argv: argument vector
Caso o programa processe instruções de linha de comando
*/

int main(int argc, char* argv[]) {
	srand(time(NULL));
	Screen screen;
	
	// rertorna uma seed. Aleatoriza o número gerado
	screen.initialize(SDL_INIT_VIDEO);

	Swarm swarm;
	const double recenterWidth = Screen::SCREEN_WIDTH / 2;
	const double recenterHeight = Screen::SCREEN_HEIGHT / 2;
	while (true) {

		int elapsedPreUpdate = SDL_GetTicks();
		swarm.update(elapsedPreUpdate);
		// 1 + sin(elapsed * 0.001) quase sempre será <=2
		unsigned char green = (1 + sin(elapsedPreUpdate * 0.001)) * 128;
		unsigned char red = (1 + sin(elapsedPreUpdate * 0.002)) * 128;
		unsigned char blue = (1 + sin(elapsedPreUpdate * 0.004)) * 128;
		// retorna um array de partículas do tipo Particle*
		const Particle* const pParticles = swarm.getParticle();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			// pegando partículas individuais do ponteiro para o array de partículas
			
			Particle particle = pParticles[i];
			double x = (particle.m_x + 1) * recenterWidth;
			double y = (particle.m_y * recenterWidth) + recenterHeight;
			screen.setPixel(x, y, red, green, blue);
		}

		screen.applyBlur();
		screen.update();
		
		// SDL_Event: é a união de todas as structures de eventos distintos no SDL
		if (!screen.manageEvents()) {
			break;
		}
	}

	screen.close();
	return 0;
}