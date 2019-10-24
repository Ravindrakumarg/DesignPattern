// FactoryPattern.cpp : Defines the entry point for the console application.
// A factory pattern example

#include "stdafx.h"
#include "iostream"
#include "vector"

using namespace std;

class Larry;	//
class Moe;		// forward declration 
class Curly;	//

class Stooge
{
  public:
	static Stooge* getallocated(int choice);
    virtual void slap_stick() = 0;
};

class Larry: public Stooge
{
  public:
	  Larry(){}
    void slap_stick()
    {
        cout << "Larry: poke eyes\n";
    }
};
class Moe: public Stooge
{
  public:
	  Moe(){}
    void slap_stick()
    {
        cout << "Moe: slap head\n";
    }
};
class Curly: public Stooge
{
  public:
	  Curly(){}
    void slap_stick()
    {
        cout << "Curly: suffer abuse\n";
    }
};

Stooge* Stooge::getallocated (int choice)
{
	Stooge *tmp;

	if (choice == 1)
		tmp = new Larry();
	if (choice == 2)
		tmp = new Moe();
	if (choice == 3)
		tmp = new Curly();

	return tmp; 
}


int _tmain()
{
  vector<Stooge*> roles;
  int choice;

  while (true)
  {
	cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
	cin >> choice;
	if (choice == 0)
		break;
	roles.push_back(Stooge::getallocated(choice));
  }

  for (int i = 0; i < roles.size(); i++)
    roles[i]->slap_stick();


  for (int i = 0; i < roles.size(); i++)
    delete roles[i];

	return 0;
}