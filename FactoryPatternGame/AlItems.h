

#ifndef __ALL_ITEM__
#define __ALL_ITEM__

#include "iostream"
#include "string.h"

class AlItems
{
private:
	std::string _name;
public:
	AlItems(std::string name):_name(name)
	{
	}

	std::string getname()
	{
		return _name;
	}
};

class Car : public AlItems
{
public:
	Car():AlItems("Car")
	{
	}
};

class CellPhone :public  AlItems
{
public: CellPhone()
        :AlItems("CellPhone"){}
};

class Computer : public AlItems
{
public: Computer()
        :AlItems("Computer"){}
};

class LapTop : public AlItems
{
public: LapTop()
        :AlItems("LapTop"){}
};

class MotorBike : public AlItems
{
public: MotorBike()
        :AlItems("MotorBike"){}
};

class EntertainmentAllowance : public AlItems
{
public: EntertainmentAllowance()
        :AlItems("EntertainmentAllowance"){}
};

class TravelAllowance : public AlItems
{
public: TravelAllowance()
        :AlItems("TravelAllowance"){}
};
class Salary : public AlItems
{
public: Salary()
        :AlItems("Salary"){}
};

class Incentives : public AlItems
{
public: Incentives()
        :AlItems("Incentives"){}
};

#endif