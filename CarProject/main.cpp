#include "car_.h"


void main()
{
	car_ c;
	c.setColor(colors::RED);
	cout << c;
	c.getEngine().setVolume(1.5);
	cout << c;
	system("pause");
}