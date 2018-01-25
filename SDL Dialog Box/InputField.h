#pragma once

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class InputField {
public:
	InputField();
	InputField(string id, SDL_Rect rectangle, string fileName);

	void update(SDL_Point eventPos);
	void render(SDL_Renderer *renderer);

	void setPos(SDL_Point pos);
	void setPos(float x, float y);
	SDL_Point getLocalPos(SDL_Point dialogBoxPos);
	SDL_Point getGlobalPos();

	void setID(string id);
	string getID();

	void setFileName(string fileName);
	string getFileName();

	void setX(float x);
	float getX();

	void setY(float y);
	float getY();

	void setWidth(float w);
	float getWidth();

	void setHeight(float h);
	float getHeight();

	void setFont(string fontFileLocation, float size);
	void generateFontSurface(SDL_Renderer *renderer);
	void setMessageDistFromEdge(int dist);

	void addBorder(int thickness, SDL_Color colour);
	SDL_Point getLocalPosWithBorder(SDL_Point dialogBoxPos);
	SDL_Point getGlobalPosWithBorder();
	float getXWithBorder();
	float getYWithBorder();
	float getWidthWithBorder();
	float getHeightWithBorder();

	void appendToMessage(char *character);
	void removeEndCharacter();

	void writeToFile();

	void setSelected(bool selected);
	bool getSelected();

private:
	string m_id;
	string m_fileName;

	SDL_Rect m_rect;
	SDL_Color m_colour;

	SDL_Rect m_borderRectangle;
	SDL_Color m_borderColour;
	bool m_borderAdded;

	TTF_Font *m_font;
	int m_fontSize;
	SDL_Color m_fontColour;
	SDL_Point m_fontPos;
	SDL_Surface *m_messageSurface;
	SDL_Texture *m_messageTexture;
	SDL_Rect m_fontRect;
	int m_distFromBoxEdge;

	string m_message;

	bool m_selected;
};