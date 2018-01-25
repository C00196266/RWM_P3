#include "pch.h"
#include <DialogBox.h>

TEST(CreateDialogBox, Rectangle) {
	SDL_Rect rect = { 0, 0, 200, 50 };
	SDL_Color col = { 150, 150, 150, 255 };

	DialogBox box(rect, col);

	EXPECT_EQ(0, box.getX());
	EXPECT_EQ(0, box.getY());
	EXPECT_EQ(200, box.getWidth());
	EXPECT_EQ(50, box.getHeight());
}

TEST(CreateDialogBox, Point) {
	SDL_Point pt = { 0, 72 };
	float width = 100;
	float height = 80;
	SDL_Color col = { 150, 150, 150, 255 };

	DialogBox box(pt, width, height, col);

	EXPECT_EQ(0, box.getX());
	EXPECT_EQ(72, box.getY());
	EXPECT_EQ(100, box.getWidth());
	EXPECT_EQ(80, box.getHeight());
}

TEST(CreateDialogBox, floats) {
	float x = 90;
	float y = 200;
	float width = 700;
	float height = 85;
	SDL_Color col = { 150, 150, 150, 255 };

	DialogBox box(x, y, width, height, col);

	EXPECT_EQ(90, box.getX());
	EXPECT_EQ(200, box.getY());
	EXPECT_EQ(700, box.getWidth());
	EXPECT_EQ(85, box.getHeight());
}