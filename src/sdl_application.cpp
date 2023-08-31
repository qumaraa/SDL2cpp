#include <SDL.h>
#include <iostream>

using namespace std;


class SDLApplication {
public:
	SDLApplication(int w, int h, std::string title) : 
		SCREEN_WIDTH(w), SCREEN_HEIGHT(h),
		sdlWindow{nullptr}, sdlScreenSurface{nullptr},
		t(title)
	{

	}
	bool init() {
		bool success = true;
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		}

		sdlWindow = SDL_CreateWindow(
			t.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
		);

		if (sdlWindow == nullptr) {
			cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		sdlScreenSurface = SDL_GetWindowSurface(sdlWindow);
		return success;
	}
	~SDLApplication() {
		SDL_DestroyWindow(sdlWindow);
		sdlWindow = nullptr;
		SDL_Quit();
	}
	auto getSdlWindow() {
		if (sdlWindow != nullptr) {
			return sdlWindow;
		}
	}
private:
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;
	SDL_Window* sdlWindow;
	SDL_Surface* sdlScreenSurface;
	std::string t;
};

int main(int argc, char* argv[]) {
	SDLApplication s(800,600,"SDL Application");
	if (!s.init()) {
		cerr << "SDL initialize error." << endl;
	}
	auto gWindow = s.getSdlWindow();
	SDL_UpdateWindowSurface(gWindow);
	SDL_Delay(5000);
	
	return 0;
}
