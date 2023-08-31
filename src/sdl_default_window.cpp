#include <SDL.h>
#include <SDL_net.h>
#include <iostream>

constexpr int SCREEN_WIDTH { 800 };
constexpr int SCREEN_HEIGHT{ 600 };

using namespace std;

int main(int argc, char* argv[]) {
	SDL_Window* window{ nullptr };
	SDL_Surface* screen_surface{ nullptr };
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	}
	
	window = SDL_CreateWindow(
		"SDL Window",
		SDL_WINDOWPOS_CENTERED_MASK,
		SDL_WINDOWPOS_CENTERED_MASK,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);

	if (window == nullptr) {
		cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
	}

	screen_surface = SDL_GetWindowSurface(window);
	SDL_FillRect(screen_surface, nullptr, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));
	
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
