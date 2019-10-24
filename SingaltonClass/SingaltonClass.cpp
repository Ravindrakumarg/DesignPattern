// SingaltonClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SingaltonClass.h"

void hello();

CConfig* 
CConfig :: initilize_config()
{
	if (config == 0)
	{
		config = new CConfig();
	}
	return config;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CConfig *cconfig = CConfig::initilize_config();
	cconfig->displayStatus();
	cconfig->status = true;

	hello();

	getc(stdin);
	return 0;
}

void hello()
{
	CConfig *config = CConfig::initilize_config();
	config->displayStatus();
}