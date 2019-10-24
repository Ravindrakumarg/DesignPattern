#include "stdafx.h"
#include "iostream"

using namespace std;

class Button
{
public:
	virtual void draw() = 0;
};
class IphoneButton :public Button
{
public:
	void draw() { cout << "IphoneButton" << endl; }
};
class WindowButton :public Button
{
public:
	void draw() { cout << "WindowButton" << endl; }
};

class Layout
{
public:
	virtual void paint() = 0;
};
class IphoneLayout :public Layout
{
public:
	void paint() { cout << "Iphonelayout" << endl; }
};
class Windowlayout : public Layout
{
public:
	void paint() { cout << "Windowlayout" << endl; }
};

class UIFactory
{
public:
	virtual Button* createButton() = 0;
	virtual Layout* createLayout() = 0;

	static UIFactory* create_factory(char*);
};

class IphoneFactory :public UIFactory
{
	Button* createButton()
	{
		return new IphoneButton();
	}
	Layout* createLayout()
	{
		return new IphoneLayout();
	}
};

class WindowFactory : public UIFactory
{
	Button* createButton()
	{
		return new WindowButton();
	}
	Layout* createLayout()
	{
		return new Windowlayout();
	}
};

UIFactory* UIFactory::create_factory(char* fact_type)
{
	if (fact_type == "Iphone")
		return new IphoneFactory;
	if (fact_type == "Windows")
		return new WindowFactory;
}

int main()
{
	UIFactory *factory = UIFactory::create_factory("Iphone");

	Button* btn = factory->createButton();
	btn->draw();

	Layout* lyt = factory->createLayout();
	lyt->paint();

	delete factory;

	factory = UIFactory::create_factory("Windows");

	btn = factory->createButton();
	btn->draw();

	lyt = factory->createLayout();
	lyt->paint();

    return 0;
}