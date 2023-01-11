#pragma once
#include "Movable.h"
#include "Shape.h"

class Circle :public Movable, public Shape {
private:
	int radius;

public:
	Circle(int x, int y, int r);
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
	void toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	friend ostream& operator<< (ostream& output, const Circle& obj);
	//no destructor as no memory is allocated

};