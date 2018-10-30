#include "car_.h"

car_::car_(double engineVolume, int engineCylinder, string engineType, double wheelDiametr, string wheelType, string model, colors color, int year)
{
	engine_ eng_tmp(engineVolume, engineCylinder, engineType);
	this->engine = eng_tmp;
	wheel_ wheel_tmp(wheelDiametr, wheelType);
	this->setWheel(wheel_tmp, 0);
	this->setWheel(wheel_tmp, 1);
	this->setWheel(wheel_tmp, 2);
	this->setWheel(wheel_tmp, 3);
	this->setModel(model);
	this->setColor(color);
	this->setYear(year);

}

void car_::setModel(string model)
{
	this->model = model;
}

void car_::setColor(colors color)
{
	this->color = color;
}

void car_::setYear(int year)
{
	if (year < 1990)
		year = 1990;
	this->year = year;
}

void car_::setEngine(engine_ & engine)
{
	/*this->engine.setVolume(engine.getVolume());
	this->engine.setCylinder(engine.getCylinder());
	this->engine.setType(engine.getType());*/
	this->engine = engine;
}

void car_::setWheel(wheel_ & wheel, int index)
{
	this->wheels[index] = wheel;
}

string car_::getModel() const
{
	return this->model;
}

colors car_::getColor() const
{
	return this->color;
}

int car_::getYear() const
{	
	return this->year;
}

engine_ car_::getEngine() const
{
	return this->engine;
}

engine_ & car_::getEngine()
{
	return this->engine;
}

wheel_ car_::getWheel(int index) const
{
	return this->wheels[index];
}

wheel_ & car_::getWheel(int index)
{
	return this->wheels[index];
}

string car_::getCarInfo() const
{
	string res = "car model = ";
	res += this->model;
	res += "\ncar color = ";
	switch (color) {
	case WHITE:
		res += "white";
		break;
	case BLACK:
		res += "black";
		break;
	case RED:
		res += "red";
		break;
	case GREEN:
		res += "green";
		break;
	}
		
	res += "\ncar year = " + to_string(this->year);
	res += "\n" + engine.getInfo();
	for (int i = 0; i < 4; i++)
		res += "\nwheel #" + to_string(i) + "\n" + wheels[i].getInfo();
	return res;
	
}

ostream & operator<<(ostream & os, const car_ & obj)
{
	os << obj.getCarInfo();
	return os;
}

istream & operator>>(istream & is, car_ & obj)
{
	double engVolume;
	int engCylinder;
	string engType;
	cout << "enter engine volume: ";
	is >> engVolume;
	cout << "enter engine cylinder: ";
	is >> engCylinder;
	cout << "enter engine type: ";	
	is >> engType;
	engine_ isEngine(engVolume, engCylinder, engType);
	obj.setEngine(isEngine);
	
	double wheelDiametr;
	string wheelType;
	cout << "enter wheel diameter: ";
	is >> wheelDiametr;
	cout << "enter wheel type: ";
	is >> wheelType;
	wheel_ isWheel(wheelDiametr, wheelType);
	for (int i = 0; i < 4; i++) {
		obj.setWheel(isWheel, i);
	}

	string model;
	cout << "enter model: ";	
	is >> model;
	obj.setModel(model);
	
	int index;
	cout << "enter color code (1-WHITE, 2-BLACK, 3-RED, 4-GREEN): ";
	is >> index;
	switch (index) {
	case 1: 
	{
		obj.setColor(colors::WHITE);
	}
		break;
	case 2:
	{
		obj.setColor(colors::BLACK);
	}
		break;
	case 3:
	{
		obj.setColor(colors::RED);
	}
		break;
	case 4:
	{
		obj.setColor(colors::GREEN);
	}
		break;
	}

	int isYear;
	cout << "enter car's year: ";
	is >> isYear;
	obj.setYear(isYear);

	return is;
}
