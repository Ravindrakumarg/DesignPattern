// DynamicFactoryPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

class IMobile
{
public:
	virtual void camera()= 0;
	virtual void processor()= 0;
	virtual void companyName() = 0;

public:
	void deviceInfo();
};

void IMobile :: deviceInfo()
{
	camera();
	processor();
	companyName();
}


class Nexus : public IMobile
{
public:
	void camera()
	{
		std::cout << "camera is 8 mp and Good"<<std::endl;
	}
	void processor()
	{
		std::cout << "Processor is 2.5 GHz"<<std::endl;
	}
	void companyName()
	{
		std::cout << "Google"<<std::endl;
	}
};

class Samsung : public IMobile
{
public:
	void camera()
	{
		std::cout << "camera is 8 mp but sucks" <<std::endl;
	}
	void processor()
	{
		std::cout << "processor is 2.5GHz"<<std::endl;
	}
	void companyName()
	{
		std::cout << "Samsung"<<std::endl;
	}
};

class Micromax : public IMobile
{
public:
	void camera()
	{
		std::cout << "camera is not supporting" <<std::endl;
	}
	void processor()
	{
		std::cout << "processor is 1.5GHz"<<std::endl;
	}
	void companyName()
	{
		std::cout << "Micromax"<<std::endl;
	}
};


class MobileFactory
{
public:
	IMobile* createMobile(string mobileType);
};

IMobile* MobileFactory:: createMobile(string mobileType)
{
	IMobile *mobile;
	if(mobileType.compare("Nexus"))
	{
		mobile = new Nexus();
	}
	if(mobileType.compare("Samsung"))
	{
		mobile = new Samsung();
	}
	if(mobileType.compare("Micromax"))
	{
		mobile = new Micromax();
	}
	return mobile;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MobileFactory* mFactory = new MobileFactory();
	
	IMobile * mobile;
	mobile = mFactory->createMobile("Nexus");
	mobile->deviceInfo();

	mobile = mFactory->createMobile("Samsung");
	mobile->deviceInfo();

	mobile = mFactory->createMobile("Micromax");
	mobile->deviceInfo();

	return 0;
	}