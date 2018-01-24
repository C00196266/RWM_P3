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
	m_borderRectangle = SDL_Rect{ m_boxRectangle.x - thickness, m_boxRectangle.y - thickness, m_boxRectangle.w + (thickness * 2) , m_boxRectangle.h + (thickness * 2) };
	m_borderColour = colour;
	m_borderAdded = true;
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