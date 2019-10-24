#ifndef __SINGALTON_CLASS__
#define __SINGALTON_CLASS__

#include "iostream"

class CConfig
{
private:
	CConfig()
	{
		status = false;
	}
private:
	static CConfig* config;	
public:
	static CConfig* initilize_config();
	bool status;
	~CConfig()
	{
		delete config;
		config = false;
	}
	void displayStatus()
	{
		std::cout << "Status:"<<status<<"\n";
	}
};
CConfig* CConfig::config;
#endif //__SINGALTON_CLASS__