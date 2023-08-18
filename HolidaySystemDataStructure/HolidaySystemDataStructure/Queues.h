#pragma once
#include "Holiday.h"

class Queues 
{
public:
	Queues(int size);

private:
	Holiday** data;

	int size;
	int count;

public:
	void Insert(Holiday* holiday);
	void Remove(int id);

	bool IsEmpty();
	bool IsFull();

	int GetCount();

	bool DoesHolidayExist(int id);
	Holiday* GetHoliday(int id);
	Holiday** GetHolidays();
};
