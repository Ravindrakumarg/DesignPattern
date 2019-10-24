#include "stdafx.h"
#include "iostream"

using namespace std;

class Button
{
public:
	virtual void draw() = 0;
};
class windowButton:public Button
{
public:
	void draw()
	{
		cout << "Drawing windows button" << endl;
	}
};
class IphoneButton:public Button
{
public:
	void draw()
	{
		cout << "Drawing Iphone button" << endl;
	}
};

class UIFactory
{
public:
	virtual Button* create_button(char *) = 0;
};
class Factory : public UIFactory
{
public:
	Button* create_button(char *type)
	{
		if (type == "Windows")
			return new windowButton;
		if (type == "Iphone")
			return new IphoneButton;
	}
};

int main()
{
	UIFactory *fact = new Factory();
	Button *btn = fact->create_button("Windows");
	btn->draw();

	delete btn;
	btn = fact->create_button("Iphone");
	btn->draw();

    return 0;
}