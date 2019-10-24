
#ifndef __IEMPLOYEE__
#define __IEMPLOYEE__

#include "iostream"
#include "vector"
#include "AlItems.h"

class IEmployee
{
public:
	std::vector<AlItems> list;	

	enum EMP_TYPE
	{
		ENGINEER,
		MANAGER
	};

	void	CreateAndAddBenefit(AlItems ben);
	void	PrintBenefits();
	static	IEmployee *CreateEmployee(EMP_TYPE emp_type);
};

#endif