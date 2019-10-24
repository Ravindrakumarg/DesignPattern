// FactoryPatternGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IEmployee.h"
#include "iostream"


int _tmain(int argc, _TCHAR* argv[])
{
	IEmployee *emp = IEmployee::CreateEmployee(IEmployee::MANAGER);
	std::cout << "Recievables for Manager:\n";
    emp->PrintBenefits();

    getchar();
	delete emp;

	emp = IEmployee::CreateEmployee(IEmployee::ENGINEER);
    std::cout << "Recievables for Engineer:\n";
    emp->PrintBenefits();

    getchar();
	delete emp;

	return 0;
}

