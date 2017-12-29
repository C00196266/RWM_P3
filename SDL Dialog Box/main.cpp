#include "DialogBox.h"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Event e;

	SDL_Window *window = SDL_CreateWindow("SDL Dialog Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	DialogBox dialogBox;
	dialogBox.setFont("arial.ttf");

	bool running = true;

	while (running) {
		SDL_PollEvent(&e);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		dialogBox.render(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}