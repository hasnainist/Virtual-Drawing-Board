#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands
	int x=0, y=0, h=0, w=0, r = 0,e=0;


	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";

		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		// implement a string tokenizer to populate the parameters vector 
		
		stringstream ss(userCommand);
		parameters.clear();
		string token;
		while (ss >> token) {
			parameters.push_back(token);
		}
		if (parameters.size() == 0)
		{
			cout << "\nPlease enter a command.. !\n\n\n";
			continue;
		}
	
		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		string command = parameters[0];
	

		// in the following code, consider checking for the arguments.
		// in case of too few arguments, you may remind the user the correct format

		if (command.compare("addR") == 0) {
			// get parameters in the correct order
			

			if (parameters.size() != 5)
			{
				cout << "\nWrong number of parameters for Rectangle. Kindly input right no. of parameters !\n";
				continue;
			}

			//stoi function to convert char to int
			x = stoi(parameters[1].c_str()); 
			y = stoi(parameters[2].c_str());
			h = stoi(parameters[3].c_str());
			w = stoi(parameters[4].c_str());

			

			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.push_back(r);
			//used operator overloadig instead of toString()
			cout << *r;           
									
		}
		else if (command.compare("addS") == 0) {
			// get parameters
			

			if (parameters.size() != 4)
			{
				cout << "\nWrong number of parameters for Square. Kindly input right no. of parameters !\n";
				continue;
			}

			x = stoi(parameters[1].c_str());
			y = stoi(parameters[2].c_str());
			e = stoi(parameters[3].c_str());

			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << *s;                                //operator overloading
		}

		if (command.compare("addC") == 0) {
			// get parameters
			// ...

			if (parameters.size() != 4)
			{
				cout << "\nWrong number of parameters for Circle. Kindly input right no. of parameters !\n";
				continue;
			}

			x = stoi(parameters[1].c_str());
			y = stoi(parameters[2].c_str());
			r = stoi(parameters[3].c_str());

			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << *c;  //operator overloading

		}
		else if (command.compare("scale") == 0) {
			
			//checking for any out of range index
			if (stoi(parameters[1]) - 1 > shapes.size() || stoi(parameters[1]) - 1 < 0) //subtraction 1 to start shapes index from 1
			{
				cout << "\nIndex out of range !\n\n";
				continue;
			}

			Movable* m = dynamic_cast<Movable*>(shapes[stoi(parameters[1])-1]);
			m->scale(stof(parameters[2]), stof(parameters[3]));   //stoi(1.4)=1, it ignores the decimal part. hence using stof for floats

			shapes[stoi(parameters[1])-1]->toString();
			
		}
		else if (command.compare("move") == 0) {
			// move object at index 
			int shapeNo; // read from parameters
			
			
			if (stoi(parameters[1])-1 > shapes.size() || stoi(parameters[1])-1<0) //subtraction 1 to start shapes index from 1
			{
				cout << "\nIndex out of range !\n\n";
				continue;
			}

			Movable* m = dynamic_cast<Movable*>(shapes[stoi(parameters[1])-1]);
			m->move( stoi(parameters[2]), stoi(parameters[3]) );
			

			shapes[stoi(parameters[1])-1]->toString();
			
		}
		else if (command.compare("display") == 0) {
			//additional function to display all the shapes in memory.

		
			if (shapes.size() == 0)
			{
				cout << "\n-------No Shapes in memory to display-------\n\n";
			}
			else {
				cout << "\nDisplaying all the shapes: \n\n";
				for (int i = 0; i < shapes.size(); i++)
				{
					cout << "Shape number #" << i + 1;
					shapes[i]->toString();
				}
			}

		}
		//additional command to delete all shapes in memory
		else if (command.compare("clear") == 0)
		{
			//deallocating memory for every single shape in a loop
			for (int i = 0; i < shapes.size(); i++)
			{
				delete shapes[i];
			}
			shapes.clear();
			cout << "\n-------Cleared all shapes-------\n\n";

		}

	
		cout << endl << endl;
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}