#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <SDL.h>
using namespace std;

namespace particle {
class Screen {
private:
	SDL_Window* m_window; // inicialização da janela por um ponteiro
	SDL_Surface* m_surface; // superfície contida pela janela
	SDL_Renderer* m_gRenderer;
	SDL_Texture* m_gTexture;
	Uint32* m_pixelBuffer;
	Uint32* m_pixelBufferBlurred;
	bool applicationState;
public:
	const static int SCREEN_WIDTH = 1000;
	const static int SCREEN_HEIGHT = 800;
public:
	Screen();
	bool initialize(Uint32 flags);
	void close();
	bool manageEvents();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void unsetPixel();
	void applyBlur();
};
}
#endif
