#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

	/*
	������� ��������� ��������� ������� �������� ��������� ������� �� ��� �������.
	��� ������� �������� �������� ����� ���� ������������ ��������� ����������.
	���������������� ���� ���������� ������ ������-��������� ������ �������������� ����
	� ����������� ����������� ���������� ������ ������,  � ������ ���������� �������������� ����������.
	� ��� ������ ��������� ������ ����� ��������, ����� �������� ��������� ������� ��� ���������.
	*/

class RouteStrategy abstract
{
public:
	virtual void Pass(int lengh) abstract;
};

class WalkWay: public RouteStrategy
{
public:
	void Pass(int lengh) override
	{
		cout << "Passed by Walk\n";
	}
};

class BusWay: public RouteStrategy
{
public:
	void Pass(int lengh) override
	{
		cout << "Passed by Bus\n";
	}
};

class TrainWay: public RouteStrategy
{
public:
	void Pass(int lengh) override
	{
		cout << "Passed by Train\n";
	}
};

class PassedArray
{
	int lengh;
	RouteStrategy* routeStrategy;

public:
	void SetRouteStrategy(RouteStrategy* RouteStrategy)
	{
		this->routeStrategy = RouteStrategy;
	}
	void Add(int Lengh)
	{
		this->lengh = Lengh;
	}
	void Pass()
	{
		routeStrategy->Pass(lengh);

		cout << "Lengh: " << this->lengh << " km";
		cout << endl;
	}
};

int main()
{
	PassedArray ar;

	ar.Add(10);

	BusWay bus;
	ar.SetRouteStrategy(&bus);
	ar.Pass();

	ar.Add(2);

	WalkWay walk;
	ar.SetRouteStrategy(&walk);
	ar.Pass();

	ar.Add(50);

	TrainWay train;
	ar.SetRouteStrategy(&train);
	ar.Pass();

	system("pause");
	return 0;
}
	
