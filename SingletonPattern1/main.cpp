#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class SingletonTest
{
private:
	SingletonTest() {};
	SingletonTest& operator=(const SingletonTest&){}
	~SingletonTest() {}

public:
	static SingletonTest* _instance;
	static SingletonTest* get_instance();
	static mutex _mutex;
};
SingletonTest* SingletonTest::_instance = 0;
mutex SingletonTest::_mutex;

SingletonTest* SingletonTest::get_instance()
{
	if (_instance == 0)
	{
		_mutex.lock;
	    if(_instance == 0)
            _instance = new SingletonTest();
		_mutex.unlock;

		cout << "New object" << endl;
		return _instance;
	}
	else
	{
		cout << "Existing object" << endl;
		return _instance;
	}
}

int main()
{
    SingletonTest *obj1 = SingletonTest::get_instance();
	SingletonTest *obj2 = SingletonTest::get_instance();
	SingletonTest *obj3 = SingletonTest::get_instance();
    return 0;
}
