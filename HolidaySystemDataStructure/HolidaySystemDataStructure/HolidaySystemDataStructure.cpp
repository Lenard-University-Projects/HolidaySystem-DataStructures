/*
Name: Lenard Denisz Pop
Identity: 21404349
Date: 21/05/2018
Description: Main file where all the bits and pieces are added together.
*/

#include "stdafx.h"
#include "Queues.h"
#include "Lists.h"
#include "Link.h"
#include "HolidaysManager.h"

#include <iostream>
#include <string>

using namespace std;

// Added cash into the project when we want to pay for a holiday
int availableCash = 6500;

/*
- Simply display the main menu.
- Each selection will display something different on the screen.
*/
void DisplayMenu(int& answer)
{
	system("CLS");

	cout << "1. Display all available holidays?" << endl;
	cout << "2. Display holidays in the basket?" << endl;
	cout << endl;

	cout << "Select your answer: ";
	cin >> answer;
}

/*
- Here we display the available holidays which we haven't selected already
- A holiday that we selected will not be displayed anymore and the id will be re-updated
- When selecting a holiday we update the basket (List) and remove it from the available holidays (Queues)
*/
void DisplayAvailableHolidays(HolidaysManager* holidaysManager, Lists* holidayBasket, int& answer)
{
	system("CLS");

	cout << "ID - Holiday Name - Departure - Destination - Date - Price" << endl;
	cout << endl;

	// Checking if there are any holidays available
	if (!holidaysManager->GetAllHolidays()->IsEmpty())
	{
		// Displaying all the holidays on the screen
		holidaysManager->DisplayHolidays();

		cout << endl;
		cout << "-1. Go back to main menu!!" << endl;
		cout << endl;

		// Allow the user to input their answer
		cout << "Select a holiday: ";
		cin >> answer;

		// Based on the answer we check if the holiday exists or not and if it does 
		// we add it to the basket and remove it from the queue.
		if (holidaysManager->GetAllHolidays()->DoesHolidayExist(answer))
		{
			holidayBasket->Insert(new Link(holidaysManager->GetAllHolidays()->GetHoliday(answer)));
			holidaysManager->GetAllHolidays()->Remove(answer);

			system("CLS");

			DisplayAvailableHolidays(holidaysManager, holidayBasket, answer);
		}
		else if (answer == -1)
		{
			// -1 will simply take you back to the main menu
			DisplayMenu(answer);
		}
		else
		{
			// If any the entered value is higher or lower than the available holidays simply clear the screen and display everything again.
			system("CLS");
			DisplayAvailableHolidays(holidaysManager, holidayBasket, answer);
		}
	}
	else
	{
		// If there are no more holidays available display the message and allow the player to only answer with ony answer
		system("CLS");
		cout << "There are no more holidays available." << endl;

		cout << "-1. Go back to main menu!!" << endl;
		cout << endl;

		while (answer != -1)
		{
			cout << "Select a holiday: ";
			cin >> answer;
		}

		if (answer == -1)
		{
			DisplayMenu(answer);
		}
	}
}

/*
- Here we display all the holidays selected by the user.
- We also give the option to pay for the holiday, remove it or simply go back to the main menu.
- All that is based on the answer typed in by the user.
*/
void DisplayBasket(Lists* holidayBasket, HolidaysManager* holidaysManager, int& answer)
{
	system("CLS");
	answer = 0;

	cout << "Cash Left: $" << availableCash << endl;

	cout << "ID - Holiday Name - Departure - Destination - Date - Price" << endl;
	cout << endl;

	if (!holidayBasket->IsEmpty())
		holidayBasket->Display(holidaysManager->GetAllHolidays());

	cout << endl;

	cout << "1. Pay for holiday?" << endl;
	cout << "2. Remove Holiday?" << endl;
	cout << "3. Go Back?" << endl;

	cout << endl;

	while (answer < 1 || answer > 3)
	{
		cout << "Select your answer: ";
		cin >> answer;
	}

	if (answer == 1 && !holidayBasket->IsEmpty() )
	{
		cout << "Which holiday do you want to pay for? (Enter ID): ";
		cin >> answer;

		// Check if the link is not null and make sure we have enough cash left
		if (holidayBasket->FindLink(answer) != nullptr && (availableCash - holidayBasket->FindLink(answer)->GetData()->GetPrice()) > 0)
		{
			// Remove cash from the player
			availableCash -= holidayBasket->FindLink(answer)->GetData()->GetPrice();
			holidayBasket->DeleteLink(answer);

			DisplayBasket(holidayBasket, holidaysManager, answer);

			answer = 0;
		}
	}
	else if (answer == 2 && !holidayBasket->IsEmpty())
	{
		// If we want to delete a holiday enter the id of the holiday we want to remove
		// Once the answer has been inputed add the holiday back to the available holidays and then delete it from the list
		// At which point we display the basket again
		cout << "Which holiday do you want to remove? (Enter ID): ";
		cin >> answer;

		if (holidayBasket->FindLink(answer) != nullptr)
		{
			holidaysManager->GetAllHolidays()->Insert(holidayBasket->FindLink(answer)->GetData());
			holidayBasket->DeleteLink(answer);

			DisplayBasket(holidayBasket, holidaysManager, answer);

			answer = 0;
		}

		answer = 0;
	}
	else if (answer == 3)
	{
		// Simply reset the answer and display the main menu
		answer = 0;
		DisplayMenu(answer);
	}
}

int main()
{
	HolidaysManager* holidaysManager	= new HolidaysManager();
	Lists* holidayBasket				= new Lists();

	// Checking if any of the pointers is null
	if (holidayBasket != nullptr && holidaysManager != nullptr)
	{
		// Looping through this since we will be moving through different screens quite often.
		while (true)
		{
			int answer = 0;

			DisplayMenu(answer);
		
			if (answer == 1)
			{
				answer = 0;
				DisplayAvailableHolidays(holidaysManager, holidayBasket, answer);
			}
			else if (answer == 2)
			{
				DisplayBasket(holidayBasket, holidaysManager, answer);
			}
		}
	}

    return 0;
}