#include "stdafx.h"
#include "iostream"

using namespace std;

// Provide a surrogate or placeholder for another object to control access to it.


class RealImage
{
	int obj_count;
public:
	RealImage(int i)
	{
		obj_count = i;
		std::cout << "referance count constructor"<<obj_count<<"\n";
	}
	~RealImage()
	{
		std::cout << "referance count distructor"<<obj_count<<"\n";
	}
	void draw()
	{
		cout << "   drawing image " << obj_count << '\n';
	}
};

class ImageProxy
{
	int obj_count;
	int static ref_count;
	RealImage *realImage;
public:
	ImageProxy()
	{
		obj_count = ref_count++;
		realImage = 0;
		cout << "proxy constructor:"<<obj_count<<"\n";
	}
	~ImageProxy()
	{
		cout << "proxy destructor"<<obj_count<<"\n";
		delete realImage;
	}
	void draw()
	{
		realImage = new RealImage(obj_count);
		realImage->draw();
	}
};
int ImageProxy::ref_count=0;


int _tmain(int argc, _TCHAR* argv[])
{
	ImageProxy image[5];

	for (int i; true;)
	{
		cout << "Exit[0], Image[1-5]: ";
		cin >> i;
		if (i == 0)
		  break;
		image[i - 1].draw();
	}

	return 0;
}