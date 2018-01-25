#include <DialogBox.h>

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Event e;

	SDL_Window *window = SDL_CreateWindow("SDL Dialog Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	DialogBox dialogBox(SDL_Rect{ 10, 10, 500, 400 }, SDL_Color{ 150, 150, 150, 255 });
	dialogBox.setFont("arial.ttf", 30);
	dialogBox.setMessage("This is a test. This string is very long to demonstrate that labels are multiline.");
	dialogBox.addBorder(2, SDL_Color{ 50, 50, 170, 255 });
	dialogBox.setMessageDistFromEdge(10, renderer);
	dialogBox.setWindowSize(SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h);

	dialogBox.addButtonWithBorder("button_1", SDL_Rect{ 10, 230, 100, 30 }, SDL_Color{ 120, 120, 120, 255 }, "Test Button 1", "arial.ttf", 12, 1, SDL_Color{ 0, 0, 0, 255 });
	dialogBox.addButtonWithBorder("button_2", SDL_Rect{ 170, 230, 100, 30 }, SDL_Color{ 120, 120, 120, 255 }, "Test Button 2", "arial.ttf", 12, 1, SDL_Color{ 0, 0, 0, 255 });

	dialogBox.addInputFieldWithBorder(SDL_Rect{ 10, 300, 260, 70 }, 1, SDL_Color{ 0, 0, 0, 255 }, "arial.ttf", 10);

	bool running = true;

	while (running) {
		SDL_PollEvent(&e);

		dialogBox.getInputs(e, renderer);

		for (int i = 0; i < dialogBox.getButtons().size(); i++) {
			if (dialogBox.getButtons().at(i)->getPressed() == true) {
				dialogBox.getButtons().at(i)->setMessage("Button Pressed", renderer);
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		dialogBox.render(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
