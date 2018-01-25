#include <DialogBox.h>

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Event e;

	SDL_Window *window = SDL_CreateWindow("SDL Dialog Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	
	// initialise the dialog box with a SDL rectangle and a SDL colour
	DialogBox dialogBox(SDL_Rect{ 10, 10, 500, 400 }, SDL_Color{ 150, 150, 150, 255 });

	// used to get the exact position of the touch events, as the touch events' positions are normalised to be between 0 and 1
	dialogBox.setWindowSize(SDL_GetWindowSurface(window)->w, SDL_GetWindowSurface(window)->h);

	// set font takes the location and name of the desired font file, and the desired size of the font
	dialogBox.setFont("arial.ttf", 30);

	// takes a string that is to be displayed on the dialog box
	dialogBox.setMessage("This is a test. This string is very long to demonstrate that labels are multiline.");

	// set the distance of the text to draw away from the edges of the dialog box (this is optional)
	dialogBox.setMessageDistFromEdge(10, renderer);

	// takes a size for the thickness and the desired colour for an outline around the dialog box
	dialogBox.addBorder(2, SDL_Color{ 50, 50, 170, 255 });

	// takes a string for the id, a rectangle of its position and size, a colour to be drawn as, a string to be displayed on
	// the button, the file location and name of the font file, and the size of the font to be used
	dialogBox.addButton("button_1", SDL_Rect{ 10, 230, 100, 30 }, SDL_Color{ 120, 120, 120, 255 }, "Test Button 1", "arial.ttf", 12);

	// takes a string for the id, a rectangle of its position and size, a colour to be drawn as, a string to be displayed on
	// the button, the file location and name of the font file, and the size of the font to be used, a value for border thickness,
	// and a colour for the border
	dialogBox.addButtonWithBorder("button_2", SDL_Rect{ 170, 230, 100, 30 }, SDL_Color{ 120, 120, 120, 255 }, "Test Button 2", "arial.ttf", 12, 1, SDL_Color{ 0, 0, 0, 255 });

	// takes a string for the id, a file name to write to, a rectangle of its position and size, the file location and name of the 
	// font file, and the size of the font to be used
	dialogBox.addInputField("field_1", "field1_output.txt", SDL_Rect{ 10, 270, 270, 40 }, "arial.ttf", 10);

	// takes a string for the id, a file name to write to, a rectangle of its position and size, the thickness and colour of the
	// outline, the file location and name of the font file, and the size of the font to be used
	dialogBox.addInputFieldWithBorder("field_2", "field2_output.txt", SDL_Rect{ 10, 330, 270, 40 }, 1, SDL_Color{ 0, 0, 0, 255 }, "arial.ttf", 10);

	bool running = true;

	while (running) {
		// checks for events
		SDL_PollEvent(&e);

		// checks for user input events for the keyboard, mouse and touch
		dialogBox.getInputs(e, renderer);

		for (int i = 0; i < dialogBox.getButtons().size(); i++) {
			// check if a button has been pressed
			if (dialogBox.getButtons().at(i)->getPressed() == true) {
				// e.g. after button is pressed, changes the message on it to be
				// "Button Pressed"
				dialogBox.getButtons().at(i)->setMessage("Button Pressed", renderer);
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderClear(renderer);

		// renders the dialog box
		dialogBox.render(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}