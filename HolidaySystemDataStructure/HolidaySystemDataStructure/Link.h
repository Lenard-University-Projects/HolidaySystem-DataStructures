#pragma once
#include "Holiday.h"

#include <iostream>

using namespace std;

class Link 
{
public:
	Link(Holiday* data);

private:
	Holiday* data;
	Link* next;

public:	
	Holiday* GetData();

	Link* GetNextLink();
	void SetNextLink(Link* newLink);

	void Display();
};