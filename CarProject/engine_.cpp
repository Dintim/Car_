#include "engine_.h"


engine_::engine_(double volume, int cylinder, string type)
{
	this->setVolume(volume);
	this->setCylinder(cylinder);
	this->setType(type);
}

void engine_::setVolume(double volume)
{
	if (volume < 1)
		volume = 1.8;
	this->volume = volume;
}

void engine_::setCylinder(int cylinder)
{
	if (cylinder < 4)
		cylinder = 4;
	this->cylinder = cylinder;
}

void engine_::setType(string type)
{
	this->type = type;
}

double engine_::getVolume() const
{
	return this->volume;
}

int engine_::getCylinder() const
{
	return this->cylinder;
}

string engine_::getType() const
{
	return this->type;
}

string engine_::getInfo() const
{	
	string res="engine volume = ";
	res += to_string(this->volume);
	res += "\ncount of cylinders = " + to_string(this->cylinder);
	res += "\nengine type = " + this->type;
	return res;
}

ostream & operator<<(ostream & os, const engine_ & obj)
{
	os << obj.getInfo();
	return os;
}

istream & operator>>(istream & is, engine_ & obj)
{
	double isVolume;
	int isCylinder;
	string isType;
	cout << "enter engine volume: ";
	is >> isVolume;
	obj.setVolume(isVolume);
	cout << "enter engine cylinder: ";
	is >> isCylinder;
	obj.setCylinder(isCylinder);
	cout << "enter engine type: ";
	is >> isType;
	obj.setType(isType);
	return is;
}
