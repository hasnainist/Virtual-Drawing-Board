#pragma once
#include "Point.h"
#include <vector>
#include <iostream>
using namespace std;
class Shape {
protected:
	float area;
	float perimeter;
	bool isCircular;
	Point *leftTop;
	vector<Point*> points;

public:
	Shape();
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;
	virtual void toString() = 0;
	virtual ~Shape();  // making it virtual so correct destructor for child classes can be called to deallocate shapes vector in driver.cpp

};