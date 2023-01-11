#pragma once
#include "Movable.h"
#include "Shape.h"

class Square :public Movable, public Shape {
private:
	int edge;
	

public:
	Square(int x, int y, int e);
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
	void toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	friend ostream& operator<< (ostream& output, const Square& obj);
	//no destructor as no memory is allocated

};