#include "pch.h"
#include "game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
	game Zaid;

	Zaid.pradzia();

	while (true)
	{
		Zaid.saudimasBOT();
		Zaid.spausdinimas();
		Zaid.saudimasZmogaus();
	}

	return 0;
}