#pragma once
#include "Lists.h"
#include "Holiday.h"
#include "Queues.h"

class HolidaysManager
{
public:
	HolidaysManager();

private:	
	Queues* holidayList;

public:
	void DisplayHolidays();
	Queues* GetAllHolidays();
};