#pragma once
#include "engine_.h"
#include "wheel_.h"

enum colors {
	WHITE,
	BLACK,
	RED,
	GREEN
};
class car_
{
	engine_ engine;
	wheel_ wheels[4];
	string model;
	colors color;
	int year;
public:
	car_(double engineVolume = 1.8, int engineCylinder = 4, string engineType = "gas", double wheelDiametr = 14.0, string wheelType = "all season", string model = "toyota carina", colors color = colors::WHITE, int year = 1990);
	void setModel(string model);
	void setColor(colors color);
	void setYear(int year);
	void setEngine(engine_& engine);
	void setWheel(wheel_ &wheel, int index);
	string getModel()const;
	colors getColor()const;
	int getYear()const;
	engine_ getEngine()const;
	engine_& getEngine();
	wheel_ getWheel(int index)const;
	wheel_& getWheel(int index);
	string getCarInfo()const;
};

ostream&operator<<(ostream&os, const car_&obj);
//istream&operator>>(istream&is, car_&obj);

