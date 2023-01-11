#pragma once
#include "Movable.h"
#include "Shape.h"


class Rectangle :public Movable, public Shape {
private:
	int height;
	int width;
 
public:
	Rectangle(int x, int y, int h, int w);
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
	void toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	friend ostream& operator<< (ostream& output, const Rectangle& obj);
	//no destructor as no memory is allocated
};

