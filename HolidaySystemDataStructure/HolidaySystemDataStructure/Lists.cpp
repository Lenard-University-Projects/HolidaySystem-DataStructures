/*
Name: Lenard Denisz Pop
Identity: 21404349
Date: 21/05/2018
Description: Managing any new Lists created via code using the code below.
*/

#include "StdAfx.h"
#include "Lists.h"

Lists::Lists()
{
	first = 0;
}

void Lists::Insert(Link* newLink)
{
	newLink->SetNextLink(first);

	first = newLink;

	count++;
}

/*
- Because the list is not an array it's harder to loop through all the elements since we don't know how many there are.
- So every time we insert a new element we have to keep track of it so we know how many have been added.
- Using that count we can use a for loop to check the data of that item.
*/
void Lists::Display(Queues* HList)
{
	this->holidayList = HList;

	Link *current = first;

	for (int i = 0; i < count; i++)
	{
		current->Display();
		current = current->GetNextLink();
	}
}

bool Lists::IsEmpty()
{
	return (first == 0);
}

int Lists::GetCount()
{
	return count;
}

Link* Lists::GetFirstLink()
{
	return first;
}

/*
- Checking if the current Link id is similar to the one we are looking for and if it isn't perform a check
- If the next item is null simply return null if it isn't null update the current current link.
- At some point the current link will have the same id which will be the one we are looking for.
*/
Link* Lists::FindLink(int id)
{
	Link* current = first;

	while (current->GetData()->GetID() != id)
	{
		if (current->GetNextLink() == nullptr)
			return nullptr;
		else
			current = current->GetNextLink();
	}

	return current;
}

/*
- Similar thing to what we did when we looked for a link but this time also keep track of the previous link.
- When we delete a link we also update the count since we don't want to loop through a link that doesn't exist.
*/
Link* Lists::DeleteLink(int id)
{
	Link* current  = first;
	Link* previous = first;

	while (current->GetData()->GetID() != id)
	{
		if (current->GetNextLink() == nullptr)
			return nullptr;

		if (current->GetNextLink() != nullptr)
		{
			previous = current;
			current = current->GetNextLink();
		}
	}

	if (current == first)
		first = first->GetNextLink();
	else
		previous->SetNextLink(current->GetNextLink());

	count--;
	return current;
}