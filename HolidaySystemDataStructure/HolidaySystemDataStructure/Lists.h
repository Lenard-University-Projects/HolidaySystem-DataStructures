#pragma once
#include "Link.h"
#include "Holiday.h"
#include "Queues.h"

class Lists 
{
public:		
	Lists();

private:
	Queues* holidayList;
	Link* first;
	int count;

public:
	void Insert(Link *newLink);
	void Display(Queues* HList);

	Link *GetFirstLink();

	Link *FindLink(int id);
	Link *DeleteLink(int id);

	bool IsEmpty();
	int GetCount();
};