#pragma once
#include "stdafx.h"
#include "Employee.h"

Manager::Manager(void)
{
	CreateAndAddBenefit(Car());
    CreateAndAddBenefit(CellPhone());
    CreateAndAddBenefit(LapTop());
    CreateAndAddBenefit(EntertainmentAllowance());
    CreateAndAddBenefit(TravelAllowance());
    CreateAndAddBenefit(Salary());
    CreateAndAddBenefit(Incentives());
}




Engineer::Engineer(void)
{
	CreateAndAddBenefit(Computer());
    CreateAndAddBenefit(MotorBike());
    CreateAndAddBenefit(TravelAllowance());
    CreateAndAddBenefit(Salary());
}	
