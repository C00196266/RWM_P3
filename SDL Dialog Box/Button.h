#pragma once

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

using namespace std;

class Button {
public:
	Button();
	Button(string id, SDL_Rect rectangle, SDL_Color boxColour);

	void update(SDL_Point eventPosition);
	void render(SDL_Renderer *renderer);

	void setID(string id);
	string getID();

	void setPos(SDL_Point pos);
	void setPos(float x, float y);
	SDL_Point getLocalPos(SDL_Point dialogBoxPos);
	SDL_Point getGlobalPos();

	void setX(float x);
	float getX();

	void setY(float y);
	float getY();

	void setWidth(float w);
	float getWidth();

	void setHeight(float h);
	float getHeight();

	void setFont(string fontFileLocation, float size);
	SDL_Point getFontLocalPos();
	SDL_Point getFontGlobalPos();

	void setMessage(string message);
	void setMessage(string message, SDL_Renderer *renderer);
	string getMessage();

	void setMessageDistFromEdge(int dist, SDL_Renderer *renderer);
	int getMessageDistFromEdge();

	void generateFontSurface(SDL_Renderer *renderer);

	void addBorder(int thickness, SDL_Color colour);
	SDL_Point getLocalPosWithBorder(SDL_Point dialogBoxPos);
	SDL_Point getGlobalPosWithBorder();
	float getXWithBorder();
	float getYWithBorder();
	float getWidthWithBorder();
	float getHeightWithBorder();

	void setPressed(bool pressed);
	bool getPressed();

private:
	string m_id;

	SDL_Rect m_rect;
	SDL_Color m_colour;

	SDL_Rect m_borderRectangle;
	SDL_Color m_borderColour;
	bool m_borderAdded;

	TTF_Font *m_font;
	int m_fontSize;
	SDL_Color m_fontColour;
	SDL_Point m_fontPos;
	SDL_Surface* m_messageSurface;
	SDL_Texture* m_messageTexture;
	SDL_Rect m_fontRect;
	int m_distFromBoxEdge;

	string m_message;

	bool m_pressed;
};