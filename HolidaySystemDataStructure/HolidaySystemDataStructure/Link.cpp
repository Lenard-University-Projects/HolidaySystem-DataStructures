/*
Name: Lenard Denisz Pop
Identity: 21404349
Date: 21/05/2018
Description: This holds all the information about each link so we can use it later on inside a list.
*/


#include "StdAfx.h"
#include "Link.h"

#include <windows.h>

Link::Link(Holiday* data)
{
	this->data = data;
}

Link* Link::GetNextLink()
{
	return next;
}

void Link::SetNextLink(Link* newLink)
{
	next = newLink;
}

Holiday* Link::GetData()
{
	return data;
}

void Link::Display() 
{
	cout << data->GetID() << " - " << data->GetName() << " - " << data->GetDeparture() << " - " << data->GetDestination() << " - " << data->GetDate() << " - $" << data->GetPrice() << endl;
}