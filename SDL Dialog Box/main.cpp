#include "DialogBox.h"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Event e;

	SDL_Window *window = SDL_CreateWindow("SDL Dialog Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	DialogBox dialogBox(SDL_Rect{ 10, 10, 500, 400 }, SDL_Color{ 150, 150, 150, 255 });
	dialogBox.setFont("arial.ttf", 30);
	dialogBox.setMessage("Ayyyyyyyyyyyyyyyyyy it a me gren maro, coming at you live from Killer Keemstar's HQ");
	dialogBox.addBorder(10, SDL_Color{ 50, 50, 170, 255 });
	dialogBox.setMessageDistFromEdge(10, renderer);

	dialogBox.addButtonWithBorder("first", SDL_Rect{ 10, 10, 50, 280 }, SDL_Color{ 0, 190, 90, 255 }, "it me weeg", "arial.ttf", 10, 1, SDL_Color{ 0, 0, 0, 255 });
	dialogBox.setWindowSize(SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h);

	dialogBox.addInputFieldWithBorder(SDL_Rect{ 300, 200, 260, 70 }, 1, SDL_Color{ 0, 0, 0, 255 }, "arial.ttf", 10);

	bool running = true;

	while (running) {
		SDL_PollEvent(&e);

		dialogBox.getInputs(e, renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		dialogBox.render(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}