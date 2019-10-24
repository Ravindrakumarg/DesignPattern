#include "stdafx.h"
#include "iostream"

/*	in this program there is two way to create object. both the way will return the same object(to the principle of singleton).
	here instance can be created with new operator also that will return the same object */

using namespace std;

class SingletonTest
{
private:
	SingletonTest& operator=(const SingletonTest&){}

public:
	SingletonTest() 
	{
		std::cout << "constructor called" << std::endl;
	};

	static SingletonTest* get_instance();
	static void* operator new(size_t size)
	{
		std::cout << "new called" << std::endl;
		if (_obj == nullptr)
		{
			_obj = (SingletonTest*)malloc(size);
		}
		return _obj;
	}
	~SingletonTest() 
	{
		_obj = nullptr;
	}

public:
	static SingletonTest* _obj;
};
SingletonTest* SingletonTest::_obj = nullptr;

SingletonTest* SingletonTest::get_instance()
{
	if (_obj == nullptr)
	{
		_obj = new SingletonTest();
		return _obj;
	}
		return _obj;
}

int main()
{
	SingletonTest *obj3 = SingletonTest::get_instance();
	SingletonTest *obj1 = new SingletonTest();
	SingletonTest *obj2 = new SingletonTest();

	delete obj1;

	getc(stdin);
    return 0;
}

