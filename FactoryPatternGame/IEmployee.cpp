
#include "stdafx.h"
#include "iostream"
#include "IEmployee.h"
#include "Employee.h"

IEmployee* IEmployee::CreateEmployee(EMP_TYPE empType)
{

	if(empType == ENGINEER)
	{
	    return new Engineer();
	}
	else if(empType == MANAGER)
	{
	    return new Manager();
	}

	return new IEmployee;
}

void IEmployee::CreateAndAddBenefit(AlItems ben)
{
    list.push_back(ben);
}

void IEmployee::PrintBenefits()
{
	std::vector<AlItems>::iterator it;
    for(it = list.begin(); it != list.end(); ++it)
    {
        std::string name = (*it).getname();
		printf ("\n Name=%s", name.c_str());
    }
}