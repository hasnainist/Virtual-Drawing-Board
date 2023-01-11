#include "Circle.h"
#include <iomanip> //to manipulate float decimal points in cout

Circle::Circle(int x = 0, int y = 0, int r = 0)
{
	this->radius = r;
	this->leftTop = new Point(x, y);
	isCircular = true;
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}


void Circle::calculateArea()
{
	area= 3.14*radius*radius;
}

void Circle::calculatePerimeter()
{
	 perimeter=2*3.14*radius;
}


void Circle::calculatePoints()
{
	points.push_back(leftTop);
	int x = points[0]->x;
	int y = points[0]->y;
	Point* rightBottom = new Point(x + 2*radius, y+2*radius);
	points.push_back(rightBottom);
	
}

void Circle::move(int newX, int newY) {

	points[0]->x = newX;
	points[0]->y = newY;

	//updating other points
	points[1]->x = newX + 2*radius;
	points[1]->y = newY+2*radius;




}

void Circle::scale(float scaleX, float scaleY)
{
	
	if (scaleX < 1 || scaleY < 1)
	{
		cout << "\nWrong parameters in scaling function!\n";
		return;
	}
	else
	{
		//left top point will remain same, other points will shift
		radius = int(radius * scaleX);

		int newX = points[0]->x;
		int newY = points[0]->y;

		points[1]->x = newX + 2*radius;
		points[1]->y = newY+ 2*radius;


		//recalculating area and parameter
		calculateArea();
		calculatePerimeter();


	}

}

void Circle::toString()
{
	cout << "\n\n";
	cout << "Shape Type: \tCircle\n";
	cout << "Area: \t\t" << fixed << setprecision(1) << area << "\n";
	cout << "Circumference: \t" << fixed << setprecision(1) << perimeter << "\n";
	cout << "Left Top: \t" << "(" << points[0]->x << "," << points[0]->y << ")" << "\n";
	cout << "Right Bottom: \t" << "(" << points[1]->x << "," << points[1]->y << ")" << "\n";
	cout << "\n__________________________________________\n\n\n";
}

ostream& operator<< (ostream& output, const Circle& obj)
{
	output << "\n\n";
	output << "Shape Type: \tCircle\n";
	output << "Area: \t\t" << fixed << setprecision(1) << obj.area << "\n";
	output << "Circumference: \t" << fixed << setprecision(1) << obj.perimeter << "\n";
	output << "Left Top: \t" << "(" << obj.points[0]->x << "," << obj.points[0]->y << ")" << "\n";
	output << "Right Bottom: \t" << "(" << obj.points[1]->x << "," << obj.points[1]->y << ")" << "\n";
	output << "\n__________________________________________\n\n\n";
	return output;
}