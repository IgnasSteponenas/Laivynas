#include "pch.h"
#include "Zaidimas.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int pirmumas = rand() % 10;

	Zaidimas Zaid;

	Zaid.pradzia();

	if (pirmumas <= 5)
	{
		cout << "Kompiuteris saus pirmas\n";
		system("PAUSE");

		while (Zaid.zaidimopabaiga())
		{
			Zaid.saudimasBOT();
			Zaid.spausdinimas();
			Zaid.saudimasZmogaus();
		}
	}
	else
	{
		cout << "Jus sausite pirmas\n";
		system("PAUSE");

		while (Zaid.zaidimopabaiga())
		{
			Zaid.saudimasZmogaus();
			Zaid.spausdinimas();
			Zaid.saudimasBOT();
		}
	}


	Zaid.laimejimoPranesimas();
}