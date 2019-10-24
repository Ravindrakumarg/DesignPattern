#include <iostream>
#include <vector>
using namespace std;

class Observer;

class Subject
{
public:
    virtual void register_observer(Observer*)	=	0;
    virtual void unregister_observer(Observer*)	=	0;
    virtual void notify_observer()=0;
};

class CricketData : public Subject
{
    int run, wicket;
    float over;
    std::vector<Observer*> observer_list;
public:
    void register_observer(Observer* observer)
    {
        observer_list.push_back(observer);
    }
    void unregister_observer(Observer* observer)
    {
        observer_list.pop_back();
    }
    void notify_observer()
    {
        int count = observer_list.size();
        for(int i=0; i< count ;i++)
            observer_list[i]->update(run, wicket, over);
    }

    void dataChanged(int run, int wicket, float over)
    {
        this->run = run;
        this->wicket = wicket;
        this->over = over;
        notify_observer();
    }
};

class Observer
{
public:
    virtual void update(int run, int wicket, float over)=0;
};

class TotalRunDisplay:public Observer
{
public:
    void update(int run, int wicket, float over)
    {
        cout << "Run: "<<run <<" Wicket: "<<wicket <<" Over:"<<over<<endl;
    }
};

class FuturePrediction:public Observer
{
public:
    void update(int run, int wicket, float over)
    {
        cout << "1Run: "<<run <<" Wicket: "<<wicket <<" Over:"<<over<<endl;
    }
};

int main()
{
	TotalRunDisplay *total_run_display = new TotalRunDisplay();
	FuturePrediction *future_prediction = new FuturePrediction();

	CricketData *cricket_data = new CricketData();
	cricket_data->register_observer(total_run_display);
	cricket_data->register_observer(future_prediction);

	cricket_data->dataChanged(130, 3, 10.3);
	return 0;
}