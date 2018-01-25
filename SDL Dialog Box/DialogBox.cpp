#include "DialogBox.h"

DialogBox::DialogBox() {
	m_boxRectangle = SDL_Rect{ 10, 20, 100, 100 };
	m_boxColour = SDL_Color{ 205, 205, 205, 255 };
	m_font = NULL;
	m_messageSurface = NULL;
	m_messageTexture = NULL;
	m_fontSize = 12;
	m_fontColour = SDL_Color{ 0, 0, 0, 255 };
	m_fontPos = SDL_Point{ m_boxRectangle.x + 10, m_boxRectangle.y + 10};
	m_distFromBoxEdge = 10;
	m_borderAdded = false;
	m_allowKeyPress = true;
}

DialogBox::DialogBox(SDL_Rect rectangle, SDL_Color boxColour) {
	m_boxRectangle = rectangle;
	m_boxColour = boxColour;
	m_font = NULL;
	m_messageSurface = NULL;
	m_messageTexture = NULL;
	m_fontSize = 12;
	m_fontColour = SDL_Color{ 0, 0, 0, 255 };
	m_fontPos = SDL_Point{ m_boxRectangle.x + 10, m_boxRectangle.y + 10 };
	m_distFromBoxEdge = 10;
	m_borderAdded = false;
	m_allowKeyPress = true;
}

DialogBox::DialogBox(SDL_Point position, float width, float height, SDL_Color boxColour) {
	m_boxRectangle.x = position.x;
	m_boxRectangle.y = position.y;
	m_boxRectangle.w = width;
	m_boxRectangle.h = height;
	m_boxColour = boxColour;
	m_font = NULL;
	m_messageSurface = NULL;
	m_messageTexture = NULL;
	m_fontSize = 12;
	m_fontColour = SDL_Color{ 0, 0, 0, 255 };
	m_fontPos = SDL_Point{ m_boxRectangle.x + 10, m_boxRectangle.y + 10 };
	m_distFromBoxEdge = 10;
	m_borderAdded = false;
	m_allowKeyPress = true;
}

DialogBox::DialogBox(float x, float y, float width, float height, SDL_Color boxColour) {
	m_boxRectangle.x = x;
	m_boxRectangle.y = y;
	m_boxRectangle.w = width;
	m_boxRectangle.h = height;
	m_boxColour = boxColour;
	m_font = NULL;
	m_messageSurface = NULL;
	m_messageTexture = NULL;
	m_fontSize = 12;
	m_fontColour = SDL_Color{ 0, 0, 0, 255 };
	m_fontPos = SDL_Point{ m_boxRectangle.x + 10, m_boxRectangle.y + 10 };
	m_distFromBoxEdge = 10;
	m_borderAdded = false;
	m_allowKeyPress = true;
}

void DialogBox::getInputs(SDL_Event &e, SDL_Renderer *renderer) {
	switch (e.type) {
	case SDL_FINGERDOWN:
		m_eventPosition.x = e.tfinger.x * m_windowWidth;
		m_eventPosition.y = e.tfinger.y * m_windowHeight;

		for (int i = 0; i < m_buttons.size(); i++) {
			if (m_buttons.at(i)->getPressed() == false) {
				m_buttons.at(i)->update(m_eventPosition);
			}
		}
		break;

	case SDL_MOUSEBUTTONDOWN:
		SDL_GetMouseState(&m_eventPosition.x, &m_eventPosition.y);

		if (m_buttons.empty() == false) {
			for (int i = 0; i < m_buttons.size(); i++) {
				if (m_buttons.at(i)->getPressed() == false) {
					m_buttons.at(i)->update(m_eventPosition);
				}
			}
		}

		break;

	case SDL_TEXTINPUT:
		if (m_inputField != NULL) {
			if (m_allowKeyPress == true) {
				m_inputField->appendToMessage(e.text.text);
				m_inputField->generateFontSurface(renderer);
				m_allowKeyPress = false;
			}
		}

		break;

	case SDL_KEYDOWN:
		switch (e.key.keysym.sym) {
		case SDLK_BACKSPACE:
			if (m_inputField != NULL) {
				if (m_allowKeyPress == true)
				{
					m_inputField->removeEndCharacter();
					m_inputField->generateFontSurface(renderer);
					m_allowKeyPress = false;
				}
			}
			break;

		case SDLK_RETURN:
			if (m_inputField != NULL) {
				if (m_allowKeyPress == true)
				{
					m_inputField->writeToFile();
					m_inputField->generateFontSurface(renderer);
					m_allowKeyPress = false;
				}
			}
		}
		break;

	case SDL_KEYUP:
		m_allowKeyPress = true;
		break;
	}
}

void DialogBox::render(SDL_Renderer *renderer) {
	if (m_borderAdded == true) {
		SDL_SetRenderDrawColor(renderer, m_borderColour.r, m_borderColour.g, m_borderColour.b, m_borderColour.a);
		SDL_RenderFillRect(renderer, &m_borderRectangle);
	}

	SDL_SetRenderDrawColor(renderer, m_boxColour.r, m_boxColour.g, m_boxColour.b, m_boxColour.a);
	SDL_RenderFillRect(renderer, &m_boxRectangle);

	if (m_messageTexture == NULL) {
		if (m_font != NULL && m_message != "") {
			generateFontSurface(renderer);
		}
	}
	else {
		SDL_RenderCopy(renderer, m_messageTexture, NULL, &m_fontRect);
	}

	if (m_buttons.empty() == false) {
		for (int i = 0; i < m_buttons.size(); i++) {
			m_buttons.at(i)->render(renderer);
		}
	}

	if (m_inputField != NULL) {
		m_inputField->render(renderer);
	}
}

void DialogBox::setPos(SDL_Point pos) {
	m_boxRectangle.x = pos.x;
	m_boxRectangle.y = pos.y;
}

void DialogBox::setPos(float x, float y) {
	m_boxRectangle.x = x;
	m_boxRectangle.y = y;
}

SDL_Point DialogBox::getPos() {
	return SDL_Point { m_boxRectangle.x, m_boxRectangle.y };
}

void DialogBox::setX(float x) {
	m_boxRectangle.x = x;
}

float DialogBox::getX() {
	return m_boxRectangle.x;
}

void DialogBox::setY(float y) {
	m_boxRectangle.y = y;
}

float DialogBox::getY() {
	return m_boxRectangle.y;
}

void DialogBox::setWidth(float w) {
	m_boxRectangle.w = w;
}

float DialogBox::getWidth() {
	return m_boxRectangle.w;
}

void DialogBox::setHeight(float h) {
	m_boxRectangle.h = h;
}

float DialogBox::getHeight() {
	return m_boxRectangle.h;
}

void DialogBox::setDialogBoxColour(SDL_Color colour) {
	m_boxColour = colour;
}

void DialogBox::setDialogBoxColour(float r, float g, float b) {
	m_boxColour.r = r;
	m_boxColour.b = b;
	m_boxColour.g = g;
}

void DialogBox::setDialogBoxColour(float r, float g, float b, float a) {
	m_boxColour.r = r;
	m_boxColour.b = b;
	m_boxColour.g = g;
	m_boxColour.a = a;
}

void DialogBox::setDialogBoxAlpha(float a) {
	m_boxColour.a = a;
}

SDL_Color DialogBox::getDialogBoxColour() {
	return m_boxColour;
}

void DialogBox::setFont(TTF_Font *font) {
	m_font = font;
}

void DialogBox::setFont(string fontFileLocation, float size) {
	m_fontSize = size;

	if (!TTF_OpenFont(fontFileLocation.c_str(), m_fontSize)) {
		cout << "Could not load font at " << fontFileLocation << endl;
	}
	else {
		m_font = TTF_OpenFont(fontFileLocation.c_str(), m_fontSize);
	}
}

void DialogBox::setFontSize(int size) {
	m_fontSize = size;
}

void DialogBox::setFontColour(SDL_Color colour) {
	m_fontColour = colour;
}

void DialogBox::setFontPos(SDL_Point pos) {
	m_fontPos = pos;
}

void DialogBox::setFontPos(float x, float y) {
	m_fontPos.x = x;
	m_fontPos.y = y;
}

void DialogBox::setFontColour(float r, float g, float b) {
	m_fontColour.r = r;
	m_fontColour.b = b;
	m_fontColour.g = g;
}

void DialogBox::setFontColour(float r, float g, float b, float a) {
	m_fontColour.r = r;
	m_fontColour.b = b;
	m_fontColour.g = g;
	m_fontColour.a = a;
}

void DialogBox::setFontAlpha(float a) {
	m_fontColour.a = a;
}

SDL_Color DialogBox::getFontColour() {
	return m_fontColour;
}

SDL_Point DialogBox::getFontLocalPos() {
	return SDL_Point{ m_fontPos.x - m_boxRectangle.x, m_fontPos.y - m_boxRectangle.y };
}

SDL_Point DialogBox::getFontGlobalPos() {
	return m_fontPos;
}

void DialogBox::setMessage(string message) {
	m_message = message;
}

string DialogBox::getMessage() {
	return m_message;
}

void DialogBox::setMessageDistFromEdge(int dist, SDL_Renderer *renderer) {
	m_distFromBoxEdge = dist;
	m_fontPos = SDL_Point{ m_boxRectangle.x + m_distFromBoxEdge, m_boxRectangle.y + m_distFromBoxEdge };
	generateFontSurface(renderer);
}

int DialogBox::getMessageDistFromEdge() {
	return m_distFromBoxEdge;
}

void DialogBox::generateFontSurface(SDL_Renderer *renderer) {
	m_messageSurface = TTF_RenderText_Blended_Wrapped(m_font, m_message.c_str(), m_fontColour, m_boxRectangle.w - (m_distFromBoxEdge * 2));
	m_messageTexture = SDL_CreateTextureFromSurface(renderer, m_messageSurface);
	m_fontRect = SDL_Rect{ m_fontPos.x, m_fontPos.y, m_messageSurface->w, m_messageSurface->h };
}

void DialogBox::addBorder(int thickness, SDL_Color colour) {
	if (m_borderAdded == false) {
		m_borderRectangle = SDL_Rect{ m_boxRectangle.x - thickness, m_boxRectangle.y - thickness, m_boxRectangle.w + (thickness * 2) , m_boxRectangle.h + (thickness * 2) };
		m_borderColour = colour;
		m_borderAdded = true;
	}
}

SDL_Point DialogBox::getPosWithBorder() {
	return SDL_Point{ m_borderRectangle.x, m_borderRectangle.y };
}

float DialogBox::getXWithBorder() {
	return m_borderRectangle.x;
}

float DialogBox::getYWithBorder() {
	return m_borderRectangle.y;
}

float DialogBox::getWidthWithBorder() {
	return m_borderRectangle.w;
}

float DialogBox::getHeightWithBorder() {
	return m_borderRectangle.h;
}

void DialogBox::addButton() {
	m_buttons.push_back(new Button());
}

void DialogBox::addButton(string id, SDL_Rect rectangle, SDL_Color boxColour, string message, string fontLocation, int fontSize) {
	m_buttons.push_back(new Button(id, SDL_Rect{ rectangle.x + m_boxRectangle.x, rectangle.y + m_boxRectangle.y, rectangle.w, rectangle.h }, boxColour));
	m_buttons.at(m_buttons.size() - 1)->setFont(fontLocation, fontSize);
	m_buttons.at(m_buttons.size() - 1)->setMessage(message);
}

void DialogBox::addButtonWithBorder(string id, SDL_Rect rectangle, SDL_Color boxColour, string message, string fontLocation, int fontSize, int thickness, SDL_Color borderColour) {
	m_buttons.push_back(new Button(id, SDL_Rect{rectangle.x + m_boxRectangle.x, rectangle.y + m_boxRectangle.y, rectangle.w, rectangle.h }, boxColour));
	m_buttons.at(m_buttons.size() - 1)->setFont(fontLocation, fontSize);
	m_buttons.at(m_buttons.size() - 1)->setMessage(message);
	m_buttons.at(m_buttons.size() - 1)->addBorder(thickness, borderColour);
}

void DialogBox::removeButton(string id) {
	for (int i = 0; i < m_buttons.size(); i++) {
		if (m_buttons.at(i)->getID() == id) {
			m_buttons.erase(m_buttons.begin() + i);
			break;
		}
	}
}

vector<Button*> DialogBox::getButtons() {
	return m_buttons;
}

InputField* DialogBox::getInputField() {
	return m_inputField;
}

void DialogBox::addInputField(SDL_Rect rectangle, string fontLocation, int fontSize) {
	m_inputField = new InputField(rectangle);
	m_inputField->setFont(fontLocation, fontSize);
}

void DialogBox::addInputFieldWithBorder(SDL_Rect rectangle, int thickness, SDL_Color borderColour, string fontLocation, int fontSize) {
	m_inputField = new InputField(rectangle);
	m_inputField->setFont(fontLocation, fontSize);
	m_inputField->addBorder(thickness, borderColour);
}

void DialogBox::removeInputField() {
	delete m_inputField;
}

void DialogBox::setWindowSize(int width, int height) {
	m_windowWidth = width;
	m_windowHeight = height;
}