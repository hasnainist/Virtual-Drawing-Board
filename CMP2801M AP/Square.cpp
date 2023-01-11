#include "Square.h"
#include <iomanip> //to manipulate float decimal points in cout

Square::Square(int x = 0, int y = 0, int e = 0)
{
	this->edge = e;
	this->leftTop = new Point(x, y);
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}

void Square::calculateArea()
{
	area = edge * edge;
}

void Square::calculatePerimeter()
{
	perimeter = 4 * edge;
}

void Square::calculatePoints()
{
	points.push_back(leftTop);
	int x = points[0]->x;
	int y = points[0]->y;
	Point* rightTop = new Point(x + edge, y);
	points.push_back(rightTop);
	Point* rightBottom = new Point(x + edge, y + edge);
	points.push_back(rightBottom);
	Point* leftBottom = new Point(x, y + edge);
	points.push_back(leftBottom);

}

void Square::move(int newX, int newY) {

	points[0]->x = newX;
	points[0]->y = newY;

	//updating other points
	points[1]->x = newX + edge;
	points[1]->y = newY;


	points[2]->x = newX + edge;
	points[2]->y = newY + edge;

	points[3]->x = newX;
	points[3]->y = newY + edge;

}

void Square::scale(float scaleX, float scaleY)
{
	
	if (scaleX < 1 || scaleY < 1)
	{
		cout << "\nWrong parameters in scaling function!\n";
		return;
	}
	else
	{
		//left top point will remain same, other points will shift
		edge = int(edge * scaleX);
		
		int newX = points[0]->x;
		int newY = points[0]->y;

		points[1]->x = newX + edge;
		points[1]->y = newY;


		points[2]->x = newX + edge;
		points[2]->y = newY + edge;

		points[3]->x = newX;
		points[3]->y = newY + edge;

		//recalculating area and parameter
		calculateArea();
		calculatePerimeter();


	}

}

void Square::toString()
{
	cout << "\n\n";
	cout << "Shape Type: \tSquare\n";
	cout << "Area: \t\t" << fixed << setprecision(1) << area << "\n";
	cout << "Perimeter: \t" << fixed << setprecision(1) << perimeter << "\n";
	cout << "Left Top: \t" << "(" << points[0]->x << "," << points[0]->y << ")" << "\n";
	cout << "Right Top: \t" << "(" << points[1]->x << "," << points[1]->y << ")" << "\n";
	cout << "Right Bottom: \t" << "(" << points[2]->x << "," << points[2]->y << ")" << "\n";
	cout << "Left Bottom: \t" << "(" << points[3]->x << "," << points[3]->y << ")" << "\n";
	cout << "\n__________________________________________\n\n\n";
}

ostream& operator<< (ostream& output, const Square& obj)
{

	output << "\n\n";
	output << "Shape Type: \tSquare\n";
	output << "Area:\t \t" << fixed << setprecision(1) << obj.area << "\n";
	output << "Perimeter: \t" << fixed << setprecision(1) << obj.perimeter << "\n";
	output << "Left Top: \t" << "(" << obj.points[0]->x << "," << obj.points[0]->y << ")" << "\n";
	output << "Right Top: \t" << "(" << obj.points[1]->x << "," << obj.points[1]->y << ")" << "\n";
	output << "Right Bottom: \t" << "(" << obj.points[2]->x << "," << obj.points[2]->y << ")" << "\n";
	output << "Left Bottom: \t" << "(" << obj.points[3]->x << "," << obj.points[3]->y << ")" << "\n";
	output << "\n__________________________________________\n\n\n";
	return output;
}