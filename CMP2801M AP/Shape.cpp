#include "Shape.h"

Shape::Shape()
{
	this->area = 0;
	this->perimeter = 0;
	this->isCircular = false; 

}

Shape::~Shape(){
    delete leftTop;
    //deallocation memory for all the points in shape
    for (int i = 1; i < points.size();i++) { //starting from 1 as leftTop already deleted above
        delete points[i];
    }
    points.clear();
}


