/*
Name: Lenard Denisz Pop
Identity: 21404349
Date: 21/05/2018
Description: All the available holidays are created here and accessed from the Queues list called `holidayList`
			 Also we display the available holidays from here
*/

#include "stdafx.h"
#include "HolidaysManager.h"

HolidaysManager::HolidaysManager()
{
	Holiday* makadi			= new Holiday(15, "Steigenberger Makadi", "Birmingham", "in Hurghada, Red Sea and Sinai, Egypt", "16-07-2018", 1387);
	Holiday* leReve			= new Holiday(51, "Premier Le Reve", "Birmingham", "Hurghada, Red Sea and Sinai, Egypt", "20-07-2018", 1635);
	Holiday* grandGaube		= new Holiday(61, "LUX Grand Gaube", "Birmingham", "in Grand Gaube, Mauritius", "15-07-2018", 3902);
	Holiday* sansSouci		= new Holiday(89, "Couples Sans Souci", "Birmingham", "in Ocho Rios, Jamaica", "18- 07- 2018", 3445);
	Holiday* saniClub		= new Holiday(99, "Sani Club", "Manchester", "in Sani, Halkidiki, Greece", "19-07-2018", 5753);
	Holiday* fincaVeritat	= new Holiday(16, "Bou Ros Finca Can Veritat", "Bristol", "in Felanitx, Majorca, Balearic Islands, Spain", "22-07-2018", 4433);
	Holiday* turtleBeach	= new Holiday(13, "Turtle Beach Resort", "Manchester", "in St Lawrence, Barbados", "19-07-2018", 4209);
	Holiday* rioPark		= new Holiday(42, "Hotel Rio Park", "Manchester", "in Benidorm, Costa Blanca, Valencia, Spain", "24-07-2018", 808);
	Holiday* jadeMountain	= new Holiday(40, "Jade Mountain", "London Gatwick", "in Soufriere, St Lucia", "23-07-2018", 7341);
	Holiday* playaMujeres	= new Holiday(35, "Finest Playa Mujeres", "Birmingham", "in Cancun, Mexico - Caribbean Coast, Mexico", "20-07-2018", 3992);

	holidayList = new Queues(10);
	holidayList->Insert(makadi);
	holidayList->Insert(leReve);
	holidayList->Insert(grandGaube);
	holidayList->Insert(sansSouci);
	holidayList->Insert(saniClub);
	holidayList->Insert(fincaVeritat);
	holidayList->Insert(turtleBeach);
	holidayList->Insert(rioPark);
	holidayList->Insert(jadeMountain);
	holidayList->Insert(playaMujeres);

	for (int i = 0; i < holidayList->GetCount(); i++)
	{
		if (holidayList->GetHoliday(i)->GetDisplayID() == -99)
			holidayList->GetHoliday(i)->SetDisplayID(i);
	}
}

Queues* HolidaysManager::GetAllHolidays()
{
	return holidayList;
}

void HolidaysManager::DisplayHolidays()
{
	for (int i = 0; i < holidayList->GetCount(); i++)
	{
		holidayList->GetHoliday(i)->SetDisplayID(i);

		cout << holidayList->GetHoliday(i)->GetDisplayID() << " - "
			<< holidayList->GetHoliday(i)->GetName() << " - "
			<< holidayList->GetHoliday(i)->GetDeparture() << " - "
			<< holidayList->GetHoliday(i)->GetDestination() << " - "
			<< holidayList->GetHoliday(i)->GetDate() << " - $"
			<< holidayList->GetHoliday(i)->GetPrice()
			<< endl;
	}
}