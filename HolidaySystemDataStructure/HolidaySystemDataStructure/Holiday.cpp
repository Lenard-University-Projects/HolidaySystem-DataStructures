/*
Name: Lenard Denisz Pop
Identity: 21404349
Date: 21/05/2018
Description: This holds all the information about each holiday available
			 for the user to select.
*/

#include "stdafx.h"
#include "Holiday.h"

Holiday::Holiday(int HHolidayID, string HName, string HDeparture, string HDestination, string HDate, int HPrice)
{
	this->displayID		= -99;
	this->id			= HHolidayID;

	this->name			= HName;
	this->departure		= HDeparture;
	this->destination	= HDestination;
	this->date			= HDate;
	this->price			= HPrice;
}

string Holiday::GetName() 
{ 
	return name; 
}

string Holiday::GetDeparture() 
{ 
	return departure; 
}

string Holiday::GetDestination() 
{ 
	return destination; 
}

string Holiday::GetDate() 
{ 
	return date; 
}

int Holiday::GetPrice()
{
	return price;
}

int Holiday::GetDisplayID()
{
	return displayID;
}

int Holiday::GetID()
{
	return id;
}

void Holiday::SetDisplayID(int id)
{
	this->displayID = id;
}