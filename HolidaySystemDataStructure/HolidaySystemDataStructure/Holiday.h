#pragma once

#include <string>
#include <iostream>

using namespace std;

class Holiday
{
public:
	Holiday(int HHolidayID, string HName, string HDeparture, string HDestination, string HDate, int HPrice);

private:
	int displayID;
	int id;

	string name;
	string departure;
	string destination;
	string date;

	int price;

public:
	string GetName();
	string GetDeparture();
	string GetDestination();
	string GetDate();

	int GetID();
	int GetDisplayID();

	int GetPrice();

	void SetDisplayID(int id);
};

