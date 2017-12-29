#include "DialogBox.h"

DialogBox::DialogBox() {
	m_rectangle = SDL_Rect{ 10, 20, 10, 10 };
	m_colour = SDL_Color{ 205, 205, 205, 255 };
	m_font = NULL;
	m_fontSize = 12;
}

DialogBox::DialogBox(SDL_Rect rectangle, SDL_Color colour) {
	m_rectangle = rectangle;
	m_colour = colour;
	m_font = NULL;
	m_fontSize = 12;
}

DialogBox::DialogBox(SDL_Point position, float width, float height, SDL_Color colour) {
	m_rectangle.x = position.x;
	m_rectangle.y = position.y;
	m_rectangle.w = width;
	m_rectangle.h = height;
	m_colour = colour;
	m_font = NULL;
	m_fontSize = 12;
}

DialogBox::DialogBox(float x, float y, float width, float height, SDL_Color colour) {
	m_rectangle.x = x;
	m_rectangle.y = y;
	m_rectangle.w = width;
	m_rectangle.h = height;
	m_colour = colour;
	m_font = NULL;
	m_fontSize = 12;
}

void DialogBox::render(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, m_colour.r, m_colour.g, m_colour.b, m_colour.a);
	SDL_RenderFillRect(renderer, &m_rectangle);
}

void DialogBox::setPos(SDL_Point pos) {
	m_rectangle.x = pos.x;
	m_rectangle.y = pos.y;
}

void DialogBox::setPos(float x, float y) {
	m_rectangle.x = x;
	m_rectangle.y = y;
}

SDL_Point DialogBox::getPos() {
	return SDL_Point { m_rectangle.x, m_rectangle.y };
}

void DialogBox::setX(float x) {
	m_rectangle.x = x;
}

float DialogBox::getX() {
	return m_rectangle.x;
}

void DialogBox::setY(float y) {
	m_rectangle.y = y;
}

float DialogBox::getY() {
	return m_rectangle.y;
}

void DialogBox::setWidth(float w) {
	m_rectangle.w = w;
}

float DialogBox::getWidth() {
	return m_rectangle.w;
}

void DialogBox::setHeight(float h) {
	m_rectangle.h = h;
}

float DialogBox::getHeight() {
	return m_rectangle.h;
}

void DialogBox::setColour(SDL_Color colour) {
	m_colour = colour;
}

void DialogBox::setColour(float r, float g, float b) {
	m_colour.r = r;
	m_colour.b = b;
	m_colour.g = g;
}

void DialogBox::setColour(float r, float g, float b, float a) {
	m_colour.r = r;
	m_colour.b = b;
	m_colour.g = g;
	m_colour.a = a;
}

void DialogBox::setAlpha(float a) {
	m_colour.a = a;
}

SDL_Color DialogBox::getColour() {
	return m_colour;
}

void DialogBox::setFont(TTF_Font *font) {
	m_font = font;
}

void DialogBox::setFont(string fontFileLocation) {
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

void DialogBox::setMessage(string message) {
	m_message = message;
}

string DialogBox::getMessage() {
	return m_message;
}