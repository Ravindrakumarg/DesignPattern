
#ifndef __EMPLOYEE__
#define __EMPLOYEE__

//#pragma once
#include "IEmployee.h"

class Manager : public IEmployee
{
public:
	Manager(void);
	
};


class Engineer : public IEmployee
{
public:
	Engineer(void);
};

#endif