#include "pch.h"
#include <iostream>
#include "Zaidimas.h"

int main()
{
	Zaidimas Zaid;

	Zaid.pradzia();

	while (true)
	{
		Zaid.saudimasBOT();
		Zaid.spausdinimas();
		Zaid.saudimasZmogaus();
	}
}