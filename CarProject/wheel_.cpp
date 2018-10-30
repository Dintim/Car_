#include "wheel_.h"

wheel_::wheel_(double diametr, string type)
{
	this->setDiametr(diametr);
	this->setType(type);
}

void wheel_::setDiametr(double diametr)
{
	if (diametr < 14)
		diametr = 14;
	this->diametr = diametr;
}

void wheel_::setType(string type)
{
	this->type = type;
}

double wheel_::getDiametr() const
{
	return this->diametr;
}

string wheel_::getType() const
{
	return this->type;
}

string wheel_::getInfo() const
{
	string res = "wheel diametr = ";
	res += to_string(this->diametr);
	res += "\nwheel type = " + this->type;
	return res;
}

ostream & operator<<(ostream & os, const wheel_ & obj)
{
	os << obj.getInfo();
	return os;
}

istream & operator>>(istream & is, wheel_ & obj)
{
	double isDiametr;
	string isType;
	cout << "enter wheel diametr: ";
	is >> isDiametr;
	obj.setDiametr(isDiametr);
	cout << "enter wheel type: ";
	is >> isType;
	obj.setType(isType);
	return is;
}
