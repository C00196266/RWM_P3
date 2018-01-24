#include "Button.h"

Button::Button() {
	m_pressed = false;
}

void Button::render(SDL_Renderer *renderer) {
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

void Button::setPos(SDL_Point pos) {
	m_rect.x = pos.x;
	m_rect.y = pos.y;
}

void Button::setPos(float x, float y) {
	m_rect.x = x;
	m_rect.y = y;
}

SDL_Point Button::getGlobalPos() {
	return SDL_Point{ m_rect.x, m_rect.y };
}

SDL_Point Button::getLocalPos(SDL_Point dialogBoxPos) {
	return SDL_Point{ m_rect.x - dialogBoxPos.x, m_rect.y - dialogBoxPos.y };
}

void Button::setX(float x) {
	m_rect.x = x;
}

float Button::getX() {
	return m_rect.x;
}

void Button::setY(float y) {
	m_rect.y = y;
}

float Button::getY() {
	return m_rect.y;
}

void Button::setWidth(float w) {
	m_rect.w = w;
}

float Button::getWidth() {
	return m_rect.w;
}

void Button::setHeight(float h) {
	m_rect.h = h;
}

float Button::getHeight() {
	return m_rect.h;
}

void Button::setButtonColour(SDL_Color colour) {
	m_colour = colour;
}

void Button::setButtonColour(float r, float g, float b) {
	m_colour.r = r;
	m_colour.b = b;
	m_colour.g = g;
}

void Button::setButtonColour(float r, float g, float b, float a) {
	m_colour.r = r;
	m_colour.b = b;
	m_colour.g = g;
	m_colour.a = a;
}

void Button::setButtonAlpha(float a) {
	m_colour.a = a;
}

SDL_Color Button::getButtonColour() {
	return m_colour;
}

void Button::setFont(TTF_Font *font) {
	m_font = font;
}

void Button::setFont(string fontFileLocation, float size) {
	m_fontSize = size;

	if (!TTF_OpenFont(fontFileLocation.c_str(), m_fontSize)) {
		cout << "Could not load font at " << fontFileLocation << endl;
	}
	else {
		m_font = TTF_OpenFont(fontFileLocation.c_str(), m_fontSize);
	}
}

void Button::setFontSize(int size) {
	m_fontSize = size;
}

void Button::setFontColour(SDL_Color colour) {
	m_fontColour = colour;
}

void Button::setFontPos(SDL_Point pos) {
	m_fontPos = pos;
}

void Button::setFontPos(float x, float y) {
	m_fontPos.x = x;
	m_fontPos.y = y;
}

void Button::setFontColour(float r, float g, float b) {
	m_fontColour.r = r;
	m_fontColour.b = b;
	m_fontColour.g = g;
}

void Button::setFontColour(float r, float g, float b, float a) {
	m_fontColour.r = r;
	m_fontColour.b = b;
	m_fontColour.g = g;
	m_fontColour.a = a;
}

void Button::setFontAlpha(float a) {
	m_fontColour.a = a;
}

SDL_Color Button::getFontColour() {
	return m_fontColour;
}

SDL_Point Button::getFontLocalPos() {
	return SDL_Point{ m_fontPos.x - m_rect.x, m_fontPos.y - m_rect.y };
}

SDL_Point Button::getFontGlobalPos() {
	return m_fontPos;
}

void Button::setMessageDistFromEdge(int dist, SDL_Renderer *renderer) {
	m_distFromBoxEdge = dist;
	m_fontPos = SDL_Point{ m_rect.x + m_distFromBoxEdge, m_rect.y + m_distFromBoxEdge };
	generateFontSurface(renderer);
}

int Button::getMessageDistFromEdge() {
	return m_distFromBoxEdge;
}

void Button::generateFontSurface(SDL_Renderer *renderer) {
	m_messageSurface = TTF_RenderText_Blended_Wrapped(m_font, m_message.c_str(), m_fontColour, m_rect.w - (m_distFromBoxEdge * 2));
	m_messageTexture = SDL_CreateTextureFromSurface(renderer, m_messageSurface);
	m_fontRect = SDL_Rect{ m_fontPos.x, m_fontPos.y, m_messageSurface->w, m_messageSurface->h };
}

void Button::addBorder(int thickness, SDL_Color colour) {
	m_borderRectangle = SDL_Rect{ m_rect.x - thickness, m_rect.y - thickness, m_rect.w + (thickness * 2) , m_rect.h + (thickness * 2) };
	m_borderColour = colour;
	m_borderAdded = true;
}

SDL_Point Button::getGlobalPosWithBorder() {
	return SDL_Point{ m_borderRectangle.x, m_borderRectangle.y };
}

SDL_Point Button::getLocalPosWithBorder(SDL_Point dialogBoxPos) {
	return SDL_Point{ m_borderRectangle.x - dialogBoxPos.x, m_borderRectangle.y - dialogBoxPos.y };
}

float Button::getXWithBorder() {
	return m_borderRectangle.x;
}

float Button::getYWithBorder() {
	return m_borderRectangle.y;
}

float Button::getWidthWithBorder() {
	return m_borderRectangle.w;
}

float Button::getHeightWithBorder() {
	return m_borderRectangle.h;
}

void Button::setPressed(bool pressed) {
	m_pressed = pressed;
}

bool Button::getPressed() {
	return m_pressed;
}