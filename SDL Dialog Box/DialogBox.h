#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <vector>

#include "Button.h"
#include "InputField.h"

using namespace std;

class DialogBox {
public:
	DialogBox();
	DialogBox(SDL_Rect rectangle, SDL_Color boxColour);
	DialogBox(SDL_Point position, float width, float height, SDL_Color boxColour);
	DialogBox(float x, float y, float width, float height, SDL_Color boxColour);

	void getInputs(SDL_Event &e, SDL_Renderer *renderer);
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

	void setDialogBoxColour(SDL_Color colour);
	void setDialogBoxColour(float r, float b, float g);
	void setDialogBoxColour(float r, float b, float g, float a);
	void setDialogBoxAlpha(float a);
	SDL_Color getDialogBoxColour();

	void setFont(TTF_Font *font);
	void setFont(string fontFileLocation, float size);
	void setFontSize(int size);
	void setFontPos(SDL_Point pos);
	void setFontPos(float x, float y);
	void setFontColour(SDL_Color colour);
	void setFontColour(float r, float b, float g);
	void setFontColour(float r, float b, float g, float a);
	void setFontAlpha(float a);
	SDL_Color getFontColour();
	SDL_Point getFontLocalPos();
	SDL_Point getFontGlobalPos();

	void setMessage(string message);
	string getMessage();

	void setMessageDistFromEdge(int dist, SDL_Renderer *renderer);
	int getMessageDistFromEdge();

	void generateFontSurface(SDL_Renderer *renderer);

	void addBorder(int thickness, SDL_Color colour);
	SDL_Point getPosWithBorder();
	float getXWithBorder();
	float getYWithBorder();
	float getWidthWithBorder();
	float getHeightWithBorder();

	void addButton();
	void addButton(SDL_Rect rectangle, SDL_Color colour, string message, string fontLocation, int fontSize);
	void addButtonWithBorder(SDL_Rect rectangle, SDL_Color colour, string message, string fontLocation, int fontSize, int thickness, SDL_Color borderColour);
	void removeButton(int id);

	vector<Button*> getButtons();

	void addInputField(SDL_Rect rectangle, string fontLocation, int fontSize);
	void addInputFieldWithBorder(SDL_Rect rectangle, int thickness, SDL_Color borderColour, string fontLocation, int fontSize);
	void removeInputField();

	void setWindowSize(int width, int height);

private:
	SDL_Rect m_boxRectangle;
	SDL_Color m_boxColour;

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

	vector<Button*> m_buttons;
	InputField *m_inputField;

	int m_windowWidth;
	int m_windowHeight;

	SDL_Point m_eventPosition;

	bool m_allowKeyPress;
};