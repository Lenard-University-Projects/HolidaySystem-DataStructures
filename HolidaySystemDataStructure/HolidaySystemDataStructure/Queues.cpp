/*
Name: Lenard Denisz Pop
Identity: 21404349
Date: 21/05/2018
Description: Managing any new Queue created via code using the code below.		 
*/

#include "stdafx.h"
#include "Queues.h"

Queues::Queues(int size)
{
	this->data	= new Holiday*[size];
	this->count = 0;
	this->size	= size;
}

void Queues::Insert(Holiday* holiday) 
{	
	if (count == 0) 
	{
		data[count] = holiday;
	}
	else
	{
		// After inserting a new holiday we want to order it by date
		// We want to make sure the next holiday ready for departure will be displayed
		int j;

		for (j = (count - 1); j >= 0; j--) 
		{
			if (holiday->GetDate() < data[j]->GetDate()) 
			{
				data[j + 1] = data[j];
			}
			else 
				break;
		}

		data[j + 1] = holiday;
	}

	count++;
}

/*
- Because there is no actual way of deleting an element the work around is to start looping at that index the holiday
- is located at and simply shift the holidays in front of it back by one.
*/
void Queues::Remove(int id)
{
	for (int i = id; i < count; i++)
	{
		Holiday* tempHoliday = data[i];

		data[i]		= data[i + 1];
		data[i + 1] = tempHoliday;
	}

	count--;
}

/*
	-> Return type methods are located below
*/
bool Queues::IsEmpty() 
{
	return count == 0;
}

bool Queues::IsFull() 
{
	return count == size;
}

int Queues::GetCount() 
{
	return count;
}

/*
- Checking if the id exists within the available holidays and if it does return true otherwise false
*/
bool Queues::DoesHolidayExist(int id)
{
	for (int i = 0; i < count; i++)
	{
		if (data[i]->GetDisplayID() == id)
		{
			return true;
			break;
		}
	}

	return false;
}

Holiday* Queues::GetHoliday(int id)
{
	return data[id];
}

Holiday** Queues::GetHolidays()
{
	return data;
}