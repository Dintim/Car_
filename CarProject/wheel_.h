#pragma once
#include <string>
#include <iostream>
using namespace std;
class wheel_
{
	double diametr;
	string type;
public:
	wheel_(double diametr=14.0, string type="all season");
	void setDiametr(double diametr);
	void setType(string type);
	double getDiametr()const;
	string getType()const;
	string getInfo()const;	
};

ostream&operator<<(ostream&os, const wheel_&obj);
istream&operator>>(istream&is, wheel_&obj);

