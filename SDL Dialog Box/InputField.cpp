#include "InputField.h"

InputField::InputField() {
	m_rect = SDL_Rect{ 10, 20, 100, 100 };
	m_colour = SDL_Color{ 255, 255, 255, 255 };
	m_font = NULL;
	m_messageSurface = NULL;
	m_messageTexture = NULL;
	m_fontSize = 12;
	m_fontColour = SDL_Color{ 0, 0, 0, 255 };
	m_distFromBoxEdge = 2;
	m_fontPos = SDL_Point{ m_rect.x + m_distFromBoxEdge, m_rect.y + m_distFromBoxEdge };
	m_borderAdded = false;
	m_selected = false;
	m_message = "";
}

InputField::InputField(SDL_Rect rectangle) {
	m_rect = SDL_Rect{ 10, 20, 100, 100 };
	m_colour = SDL_Color{ 255, 255, 255, 255 };
	m_font = NULL;
	m_messageSurface = NULL;
	m_messageTexture = NULL;
	m_fontSize = 12;
	m_fontColour = SDL_Color{ 0, 0, 0, 255 };
	m_distFromBoxEdge = 2;
	m_fontPos = SDL_Point{ m_rect.x + m_distFromBoxEdge, m_rect.y + m_distFromBoxEdge };
	m_borderAdded = false;
	m_selected = false;
	m_message = "";
}

void InputField::render(SDL_Renderer *renderer) {
	if (m_borderAdded == true) {
		SDL_SetRenderDrawColor(renderer, m_borderColour.r, m_borderColour.g, m_borderColour.b, m_borderColour.a);
		SDL_RenderFillRect(renderer, &m_borderRectangle);
	}

	SDL_SetRenderDrawColor(renderer, m_colour.r, m_colour.g, m_colour.b, m_colour.a);
	SDL_RenderFillRect(renderer, &m_rect);

	if (m_messageTexture == NULL) {
		if (m_font != NULL && m_message != "") {
			generateFontSurface(renderer);
		}
	}
	else {
		SDL_RenderCopy(renderer, m_messageTexture, NULL, &m_fontRect);
	}
}

void InputField::setPos(SDL_Point pos) {
	m_rect.x = pos.x;
	m_rect.y = pos.y;
}

void InputField::setPos(float x, float y) {
	m_rect.x = x;
	m_rect.y = y;
}

SDL_Point InputField::getGlobalPos() {
	return SDL_Point{ m_rect.x, m_rect.y };
}

SDL_Point InputField::getLocalPos(SDL_Point dialogBoxPos) {
	return SDL_Point{ m_rect.x - dialogBoxPos.x, m_rect.y - dialogBoxPos.y };
}

void InputField::setX(float x) {
	m_rect.x = x;
}

float InputField::getX() {
	return m_rect.x;
}

void InputField::setY(float y) {
	m_rect.y = y;
}

float InputField::getY() {
	return m_rect.y;
}

void InputField::setWidth(float w) {
	m_rect.w = w;
}

float InputField::getWidth() {
	return m_rect.w;
}

void InputField::setHeight(float h) {
	m_rect.h = h;
}

float InputField::getHeight() {
	return m_rect.h;
}

void InputField::setFont(string fontFileLocation, float size) {
	m_fontSize = size;

	if (!TTF_OpenFont(fontFileLocation.c_str(), m_fontSize)) {
		cout << "Could not load font at " << fontFileLocation << endl;
	}
	else {
		m_font = TTF_OpenFont(fontFileLocation.c_str(), m_fontSize);
	}
}

void InputField::generateFontSurface(SDL_Renderer *renderer) {
	m_messageSurface = TTF_RenderText_Blended_Wrapped(m_font, m_message.c_str(), m_fontColour, m_rect.w - (m_distFromBoxEdge * 2));
	m_messageTexture = SDL_CreateTextureFromSurface(renderer, m_messageSurface);
	m_fontRect = SDL_Rect{ m_fontPos.x, m_fontPos.y, m_messageSurface->w, m_messageSurface->h };
}

void InputField::setMessageDistFromEdge(int dist) {
	m_distFromBoxEdge = dist;
	m_fontPos = SDL_Point{ m_rect.x + m_distFromBoxEdge, m_rect.y + m_distFromBoxEdge };
}

void InputField::addBorder(int thickness, SDL_Color colour) {
	if (m_borderAdded == false) {
		m_borderRectangle = SDL_Rect{ m_rect.x - thickness, m_rect.y - thickness, m_rect.w + (thickness * 2) , m_rect.h + (thickness * 2) };
		m_borderColour = colour;
		m_borderAdded = true;
	}
}

SDL_Point InputField::getGlobalPosWithBorder() {
	return SDL_Point{ m_borderRectangle.x, m_borderRectangle.y };
}

SDL_Point InputField::getLocalPosWithBorder(SDL_Point dialogBoxPos) {
	return SDL_Point{ m_borderRectangle.x - dialogBoxPos.x, m_borderRectangle.y - dialogBoxPos.y };
}

float InputField::getXWithBorder() {
	return m_borderRectangle.x;
}

float InputField::getYWithBorder() {
	return m_borderRectangle.y;
}

float InputField::getWidthWithBorder() {
	return m_borderRectangle.w;
}

float InputField::getHeightWithBorder() {
	return m_borderRectangle.h;
}

void InputField::appendToMessage(char *character) {
	m_message.append(character);
}

void InputField::removeEndCharacter() {
	if (m_message.empty() == false) {
		m_message.pop_back();
	}
}