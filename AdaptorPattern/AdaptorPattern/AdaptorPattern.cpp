// AdaptorPattern.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"

typedef int coordinate;
typedef int dimension;

class Rectangle
{
public:
	virtual void draw() = 0;
};

class LagecyRectangle : public Rectangle
{
private:
	int _x1, _y1, _x2, _y2;
public:
	LagecyRectangle(coordinate x1, coordinate y1, coordinate x2, coordinate y2): _x1(x1), _y1(y1), _x2(x2), _y2(y2)
	{
	}
	void oldDraw()
	{
		std::cout << "LegacyRectangle:  oldDraw.  (" << _x1 << "," << _y1 << 
          ") => (" << _x2 << "," << _y2 << ")" << std::endl;
	}
	virtual void draw() = 0;
};

class RectangleAdaptor : public LagecyRectangle
{
private:
	int _x1, _y1, _w, _h;
public:
	RectangleAdaptor (coordinate _x1, coordinate _y1, dimension _w, dimension _h) :LagecyRectangle (_x1, _y1, _x1+_w, _y1+_h)
	{
		this->_x1	=	_x1;
		this->_w	=	_w;
		this->_y1	=	_y1;
		this->_h	=	_h;
	}

	void draw()
	{
		oldDraw();
		std::cout << "adaptor Rectangle: (x1, y1):" << _x1 <<"," <<_y1 << "height="<<_h <<"width"<<_w;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Rectangle *rec = new RectangleAdaptor(120, 200, 60, 40);
	rec->draw();

	getchar();
	return 0;
}