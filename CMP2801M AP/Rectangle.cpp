#include "Rectangle.h"
#include <iomanip> //to manipulate float decimal points in cout

Rectangle::Rectangle(int x,int y,int h,int w) {

	this->height = h;
	this->width = w;
	this->leftTop = new Point(x, y);
	calculatePoints();
	calculateArea();
	calculatePerimeter();

}

void Rectangle::calculateArea()
{
	area= height * width;
}

void Rectangle::calculatePerimeter()
{
	perimeter= 2*(height + width);
}

void Rectangle::calculatePoints()
{
	points.push_back(leftTop);
	int x = points[0]->x;
	int y = points[0]->y;
	Point* rightTop = new Point(x + width, y);
	points.push_back(rightTop);
	Point* rightBottom = new Point(x + width, y+height);
	points.push_back(rightBottom);
	Point* leftBottom = new Point(x , y + height);
	points.push_back(leftBottom);

}

void Rectangle::move(int newX, int newY) {

	points[0]->x = newX;
	points[0]->y = newY;

	//updating other points
	points[1]->x = newX+width;
	points[1]->y = newY;


	points[2]->x = newX+width;
	points[2]->y = newY+height;

	points[3]->x = newX;
	points[3]->y = newY+height;

}

void Rectangle::scale(float scaleX, float scaleY)
{
	
	if (scaleX < 1 || scaleY < 1)
	{
		cout << "\nWrong parameters in scaling function!\n";
		return;
	}
	else
	{
		//left top point will remain same, other points will shift
		width = int(width * scaleX);
		height =int( height * scaleY);
		int newX = points[0]->x;
		int newY = points[0]->y;

		points[1]->x = newX+width;
		points[1]->y = newY;


		points[2]->x = newX+width;
		points[2]->y = newY+height;

		points[3]->x = newX;
		points[3]->y = newY+height;

		//recalculating area and parameter
		calculateArea();
		calculatePerimeter();


	}

}

void Rectangle::toString()
{
	cout << "\n\n";
	cout << "Shape Type: \tRectangle\n";
	cout << "Area:\t \t" << fixed << setprecision(1) <<area<<"\n";
	cout << "Perimeter: \t" << fixed << setprecision(1) << perimeter << "\n";
	cout << "Left Top: \t" << "(" << points[0]->x << "," << points[0]->y << ")" << "\n";
	cout << "Right Top: \t" << "(" << points[1]->x << "," << points[1]->y << ")" << "\n";
	cout << "Right Bottom: \t" << "(" << points[2]->x << "," << points[2]->y << ")" << "\n";
	cout << "Left Bottom: \t" << "(" << points[3]->x << "," << points[3]->y << ")" << "\n";
	cout << "\n__________________________________________\n\n\n";
}

ostream& operator<< (ostream& output,const Rectangle &obj) { //const keyword denotes that this operator overloading function cannot modify calling object.
	
	output << "\n\n";
	output << "Shape Type: \tRectangle\n";
	output << "Area:\t \t" << fixed << setprecision(1) << obj.area << "\n";
	output << "Perimeter: \t" <<fixed<< setprecision(1) << obj.perimeter << "\n";
	output << "Left Top: \t" << "(" << obj.points[0]->x << "," << obj.points[0]->y << ")" << "\n";
	output << "Right Top: \t" << "(" << obj.points[1]->x << "," << obj.points[1]->y << ")" << "\n";
	output << "Right Bottom: \t" << "(" << obj.points[2]->x << "," << obj.points[2]->y << ")" << "\n";
	output << "Left Bottom: \t" << "(" << obj.points[3]->x << "," << obj.points[3]->y << ")" << "\n";
	output << "\n__________________________________________\n\n\n";
	return output;
}

