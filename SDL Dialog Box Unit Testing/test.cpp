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

TEST(CreateDialogBox, Floats) {
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

TEST(CreateDialogBox, Setters) {
	DialogBox box;

	box.setX(100);
	box.setY(150);
	box.setWidth(120);
	box.setHeight(200);

	EXPECT_EQ(100, box.getX());
	EXPECT_EQ(150, box.getY());
	EXPECT_EQ(120, box.getWidth());
	EXPECT_EQ(200, box.getHeight());
}

TEST(CustomiseDialogBox, Message) {
	DialogBox box;

	box.setMessage("test");

	EXPECT_EQ("test", box.getMessage());
}

TEST(CustomiseDialogBox, Border) {
	SDL_Rect rect = { 0, 0, 200, 50 };
	SDL_Color col = { 150, 150, 150, 255 };

	DialogBox box(rect, col);
	
	SDL_Color borderCol = { 150, 150, 150, 255 };
	int thickness = 2;

	box.addBorder(thickness, borderCol);

	EXPECT_EQ(-2, box.getXWithBorder());
	EXPECT_EQ(0, box.getX());
	EXPECT_EQ(-2, box.getYWithBorder());
	EXPECT_EQ(0, box.getY());
	EXPECT_EQ(204, box.getWidthWithBorder());
	EXPECT_EQ(200, box.getWidth());
	EXPECT_EQ(54, box.getHeightWithBorder());
	EXPECT_EQ(50, box.getHeight());
}