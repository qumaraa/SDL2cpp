#include <SDL.h>
#include <SDL_net.h>
#include <iostream>

static SDL_Window* gWindow{nullptr};
static SDL_Surface* gScreenSurface{nullptr};
static SDL_Surface* gHelloWorld{nullptr};

constexpr int SCREEN_WIDTH{ 800 };
constexpr int SCREEN_HEIGHT{ 600 };

using namespace std;

bool init();
bool loadMedia();
void close();

int main(int argc, char* argv[]) {
	if (!init()) {
		cerr << "Failed to initalize SDL" << endl;
	}
	if (!loadMedia()) {
		cerr << "Failed to load media!" << endl;
	}
	SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);
	
	SDL_UpdateWindowSurface(gWindow);
	SDL_Delay(5000);

	close();

	return 0;
}

bool init() {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL could not initalize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	
	gWindow = SDL_CreateWindow(
		"SDL Tutorial",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);

	if (gWindow == nullptr) {
		cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	gScreenSurface = SDL_GetWindowSurface(gWindow);
	return success;
}

bool loadMedia() {
	bool success = true;
	gHelloWorld = SDL_LoadBMP("c:/users/qumar/downloads/xz.bmp");
	if (gHelloWorld == nullptr) {
		cerr << "Unable to load image! SDL_Error: " << SDL_GetError() << endl;	
		success = false;
	}
	
	return success;
}

void close() {
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	SDL_Quit();
}
