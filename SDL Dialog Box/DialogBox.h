#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

using namespace std;

class DialogBox {
public:
	DialogBox();
	DialogBox(SDL_Rect rectangle, SDL_Color colour);
	DialogBox(SDL_Point position, float width, float height, SDL_Color colour);
	DialogBox(float x, float y, float width, float height, SDL_Color colour);

	void render(SDL_Renderer *renderer);

	void setPos(SDL_Point pos);
	void setPos(float x, float y);
	SDL_Point getPos();

	void setX(float x);
	float getX();

	void setY(float y);
	float getY();

	void setWidth(float w);
	float getWidth();

	void setHeight(float h);
	float getHeight();

	void setColour(SDL_Color colour);
	void setColour(float r, float b, float g);
	void setColour(float r, float b, float g, float a);
	void setAlpha(float a);
	SDL_Color getColour();

	void setFont(TTF_Font *font);
	void setFont(string fontFileLocation);
	void setFontSize(int size);

	void setMessage(string message);
	string getMessage();

private:
	SDL_Rect m_rectangle;

	SDL_Color m_colour;

	TTF_Font *m_font;
	int m_fontSize;

	string m_message;
};