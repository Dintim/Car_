#pragma once
#include <string>
#include <iostream>
using namespace std;
class engine_
{
	double volume;
	int cylinder;
	string type;
public:
	engine_(double volume=1.8, int cylinder=4, string type="gas");
	void setVolume(double volume);
	void setCylinder(int cylinder);
	void setType(string type);
	double getVolume()const;
	int getCylinder()const;
	string getType()const;
	string getInfo()const;


	
};

ostream&operator<<(ostream&os, const engine_&obj);

