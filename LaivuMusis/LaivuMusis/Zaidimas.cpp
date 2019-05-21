#include "pch.h"
#include "Zaidimas.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

Zaidimas::Zaidimas() {}

void Zaidimas::pradzia()
{
	for (int i = 0; i < ilgis; i++)
	{
		for (int j = 0; j < plotis; j++)
		{
			lentele[i][j] = ' ';
		}
	}

	for (int i = 0; i < ilgis; i++)
	{
		for (int j = 0; j < plotis; j++)
		{
			lenteleBOTmatoma[i][j] = ' ';
		}
	}

	for (int i = 0; i < ilgis; i++)
	{
		for (int j = 0; j < plotis; j++)
		{
			lenteleBOT[i][j] = ' ';
		}
	}

	BOTlaivuIvedimas();
	spausdinimas();
	zaidejoPradiniaiLaivai();

}

void Zaidimas::spausdinimas()
{
	system("CLS");
	cout << "* nepataikete" << endl;
	cout << "x pataikete" << endl;
	cout << "- numusete visa laiva" << endl;
	cout << "-------------------BOT----------------------" << endl << endl;

	cout << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|X\n";

	for (int i = 0; i < ilgis; i++)
	{
		if (i < 9)
			cout << " " << i + 1;
		else
			cout << i + 1 << "";

		for (int j = 0; j < plotis; j++)
		{

			cout << " | " << lenteleBOTmatoma[i][j];
		}
		cout << " |" << endl;
	}
	cout << " Y" << endl;

	cout << "-------------------Zmogaus------------------" << endl << endl;

	cout << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|X\n";

	for (int i = 0; i < ilgis; i++)
	{
		if (i < 9)
			cout << " " << i + 1;
		else
			cout << i + 1 << "";

		for (int j = 0; j < plotis; j++)
		{

			cout << " | " << lentele[i][j];
		}
		cout << " |" << endl;
	}
	cout << " Y" << endl;
}

void Zaidimas::surasymas(int x, int y, char kryptis, int vieta, vector<int>& kurIrasytiX, vector<int>& kurIrasytiY)
{
	if (vieta == 0)
	{
		if (kryptis == 'v')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y - 1);
			kurIrasytiY.push_back(y - 2);
			kurIrasytiY.push_back(y - 3);
		}
		else if (kryptis == 'k')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x - 1);
			kurIrasytiX.push_back(x - 2);
			kurIrasytiX.push_back(x - 3);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y + 1);
			kurIrasytiY.push_back(y + 2);
			kurIrasytiY.push_back(y + 3);
		}
		else if (kryptis == 'd')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x + 1);
			kurIrasytiX.push_back(x + 2);
			kurIrasytiX.push_back(x + 3);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
		}
	}
	else if (vieta == 1)
	{
		if (kryptis == 'v')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y - 1);
			kurIrasytiY.push_back(y - 2);
		}
		else if (kryptis == 'k')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x - 1);
			kurIrasytiX.push_back(x - 2);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y + 1);
			kurIrasytiY.push_back(y + 2);
		}
		else if (kryptis == 'd')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x + 1);
			kurIrasytiX.push_back(x + 2);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
		}
	}
	else if (vieta == 2)
	{
		if (kryptis == 'v')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y - 1);
		}
		else if (kryptis == 'k')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x - 1);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y + 1);
		}
		else if (kryptis == 'd')
		{
			kurIrasytiX.push_back(x);
			kurIrasytiX.push_back(x + 1);

			kurIrasytiY.push_back(y);
			kurIrasytiY.push_back(y);
		}
	}
	else if (vieta == 3)
	{
		if (kryptis == 'v')
		{
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
		}
		else if (kryptis == 'k')
		{
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
		}
		else if (kryptis == 'd')
		{
			kurIrasytiX.push_back(x);

			kurIrasytiY.push_back(y);
		}
	}
}

void Zaidimas::zaidejoPradiniaiLaivai()
{
	int x;
	int y;
	char kryptis;
	bool reikia = true;

	for (int i = 0; i < 5; i++)
	{
		//virsus - v, kaire - k, apacia - a, desine - d
		if (i == 0)
		{

			cout << "Keturvietis laivas\n";
			zaidejoLaivuIvedimas(x, y, kryptis, reikia);
			x -= 1;
			y -= 1;

			bool neveikia = true;
			while (neveikia)
			{
				if (statimoTikrinimas(i, kryptis, x, y, lentele))
				{
					if (kryptis == 'v')
					{
						lentele[y][x] = 'O';
						lentele[y - 1][x] = 'O';
						lentele[y - 2][x] = 'O';
						lentele[y - 3][x] = 'O';
					}
					else if (kryptis == 'k')
					{
						lentele[y][x] = 'O';
						lentele[y][x - 1] = 'O';
						lentele[y][x - 2] = 'O';
						lentele[y][x - 3] = 'O';
					}
					else if (kryptis == 'a')
					{
						lentele[y][x] = 'O';
						lentele[y + 1][x] = 'O';
						lentele[y + 2][x] = 'O';
						lentele[y + 3][x] = 'O';
					}
					else if (kryptis == 'd')
					{
						lentele[y][x] = 'O';
						lentele[y][x + 1] = 'O';
						lentele[y][x + 2] = 'O';
						lentele[y][x + 3] = 'O';
					}
					surasymas(x, y, kryptis, i, zmogausX, zmogausY);

					neveikia = false;
				}
				else
				{
					spausdinimas();
					cout << "Blogas pasirinkimas. ";
					zaidejoLaivuIvedimas(x, y, kryptis, reikia);
					x -= 1;
					y -= 1;
				}
			}

			spausdinimas();
		}
		else if (i == 1)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << "trivietis laivas\n";
				zaidejoLaivuIvedimas(x, y, kryptis, reikia);
				x -= 1;
				y -= 1;
				bool neveikia = true;
				while (neveikia)
				{
					if (statimoTikrinimas(i, kryptis, x, y, lentele))
					{
						if (kryptis == 'v')
						{
							lentele[y][x] = 'O';
							lentele[y - 1][x] = 'O';
							lentele[y - 2][x] = 'O';
						}
						else if (kryptis == 'k')
						{
							lentele[y][x] = 'O';
							lentele[y][x - 1] = 'O';
							lentele[y][x - 2] = 'O';
						}
						else if (kryptis == 'a')
						{
							lentele[y][x] = 'O';
							lentele[y + 1][x] = 'O';
							lentele[y + 2][x] = 'O';
						}
						else if (kryptis == 'd')
						{
							lentele[y][x] = 'O';
							lentele[y][x + 1] = 'O';
							lentele[y][x + 2] = 'O';
						}

						surasymas(x, y, kryptis, i, zmogausX, zmogausY);

						neveikia = false;
					}
					else
					{
						spausdinimas();
						cout << "Blogas pasirinkimas. ";
						zaidejoLaivuIvedimas(x, y, kryptis, reikia);
						x -= 1;
						y -= 1;
					}
				}
				spausdinimas();
			}
		}
		else if (i == 2)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << "Dvivietis laivas\n";
				zaidejoLaivuIvedimas(x, y, kryptis, reikia);

				x -= 1;
				y -= 1;
				bool neveikia = true;
				while (neveikia)
				{
					if (statimoTikrinimas(i, kryptis, x, y, lentele))
					{
						if (kryptis == 'v')
						{
							lentele[y][x] = 'O';
							lentele[y - 1][x] = 'O';
						}
						else if (kryptis == 'k')
						{
							lentele[y][x] = 'O';
							lentele[y][x - 1] = 'O';
						}
						else if (kryptis == 'a')
						{
							lentele[y][x] = 'O';
							lentele[y + 1][x] = 'O';
						}
						else if (kryptis == 'd')
						{
							lentele[y][x] = 'O';
							lentele[y][x + 1] = 'O';
						}

						surasymas(x, y, kryptis, i, zmogausX, zmogausY);

						neveikia = false;
					}
					else
					{
						spausdinimas();
						cout << "Blogas pasirinkimas. ";
						zaidejoLaivuIvedimas(x, y, kryptis, reikia);
						x -= 1;
						y -= 1;
					}
				}

				spausdinimas();
			}
		}
		else if (i == 3)
		{
			reikia = false;

			for (int j = 0; j < 4; j++)
			{
				cout << "Vienvietis laivas\n";
				zaidejoLaivuIvedimas(x, y, kryptis, reikia);

				x -= 1;
				y -= 1;
				bool neveikia = true;
				while (neveikia)
				{
					if (statimoTikrinimas(i, kryptis, x, y, lentele))
					{
						lentele[y][x] = 'O';

						surasymas(x, y, kryptis, i, zmogausX, zmogausY);

						neveikia = false;
					}
					else
					{
						spausdinimas();
						cout << "Blogas pasirinkimas. ";
						zaidejoLaivuIvedimas(x, y, kryptis, reikia);
						x -= 1;
						y -= 1;
					}
				}

				spausdinimas();
			}
		}
	}
}

bool Zaidimas::statimoTikrinimas(int kiekVietu, char puse, int x, int y, char kurilentele[][10])
{

	if (kiekVietu == 0)
	{
		if (puse == 'v')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&
				kurilentele[y - 1][x] != 'O' && kurilentele[y - 2][x] != 'O' && kurilentele[y][x] != 'O' && kurilentele[y - 1][x + 1] != 'O' && kurilentele[y - 1][x - 1] != 'O' &&
				kurilentele[y - 2][x] != 'O' && kurilentele[y - 3][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y - 2][x + 1] != 'O' && kurilentele[y - 2][x - 1] != 'O' &&
				kurilentele[y - 3][x] != 'O' && kurilentele[y - 4][x] != 'O' && kurilentele[y - 2][x] != 'O' && kurilentele[y - 3][x + 1] != 'O' && kurilentele[y - 3][x - 1] != 'O' &&
				//tikrina ar uz ribu
				y - 3 < ilgis && y - 3 >= 0 &&
				y - 2 < ilgis && y - 2 >= 0 &&
				y - 1 < ilgis && y - 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
		else if (puse == 'k')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&

				kurilentele[y][x - 1] != 'O' && kurilentele[y - 1][x - 1] != 'O' && kurilentele[y + 1][x - 1] != 'O' && kurilentele[y][x] != 'O' && kurilentele[y][x - 2] != 'O' &&
				kurilentele[y][x - 2] != 'O' && kurilentele[y - 1][x - 2] != 'O' && kurilentele[y + 1][x - 2] != 'O' && kurilentele[y][x - 1] != 'O' && kurilentele[y][x - 3] != 'O' &&
				kurilentele[y][x - 3] != 'O' && kurilentele[y - 1][x - 3] != 'O' && kurilentele[y + 1][x - 3] != 'O' && kurilentele[y][x - 2] != 'O' && kurilentele[y][x - 4] != 'O' &&
				//tikrina ar uz ribu
				x - 3 < ilgis && x - 3 >= 0 &&
				x - 2 < ilgis && x - 2 >= 0 &&
				x - 1 < ilgis && x - 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
		else if (puse == 'a')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&

				kurilentele[y + 1][x] != 'O' && kurilentele[y][x] != 'O' && kurilentele[y + 2][x] != 'O' && kurilentele[y + 1][x + 1] != 'O' && kurilentele[y + 1][x - 1] != 'O' &&
				kurilentele[y + 2][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y + 3][x] != 'O' && kurilentele[y + 2][x + 1] != 'O' && kurilentele[y + 2][x - 1] != 'O' &&
				kurilentele[y + 3][x] != 'O' && kurilentele[y + 2][x] != 'O' && kurilentele[y + 4][x] != 'O' && kurilentele[y + 3][x + 1] != 'O' && kurilentele[y + 3][x - 1] != 'O' &&
				//tikrina ar uz ribu
				y + 3 < ilgis && y + 3 >= 0 &&
				y + 2 < ilgis && y + 2 >= 0 &&
				y + 1 < ilgis && y + 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
		else if (puse == 'd')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&

				kurilentele[y][x + 1] != 'O' && kurilentele[y - 1][x + 1] != 'O' && kurilentele[y + 1][x + 1] != 'O' && kurilentele[y][x + 2] != 'O' && kurilentele[y][x] != 'O' &&
				kurilentele[y][x + 2] != 'O' && kurilentele[y - 1][x + 2] != 'O' && kurilentele[y + 1][x + 2] != 'O' && kurilentele[y][x + 3] != 'O' && kurilentele[y][x + 1] != 'O' &&
				kurilentele[y][x + 3] != 'O' && kurilentele[y - 1][x + 3] != 'O' && kurilentele[y + 1][x + 3] != 'O' && kurilentele[y][x + 4] != 'O' && kurilentele[y][x + 2] != 'O' &&
				//tikrina ar uz ribu
				x + 3 < ilgis && x + 3 >= 0 &&
				x + 2 < ilgis && x + 2 >= 0 &&
				x + 1 < ilgis && x + 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
	}
	else if (kiekVietu == 1)
	{
		if (puse == 'v')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&
				kurilentele[y - 1][x] != 'O' && kurilentele[y - 2][x] != 'O' && kurilentele[y][x] != 'O' && kurilentele[y - 1][x + 1] != 'O' && kurilentele[y - 1][x - 1] != 'O' &&
				kurilentele[y - 2][x] != 'O' && kurilentele[y - 3][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y - 2][x + 1] != 'O' && kurilentele[y - 2][x - 1] != 'O' &&
				//tikrina ar uz ribu
				y - 2 < ilgis && y - 2 >= 0 &&
				y - 1 < ilgis && y - 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
		else if (puse == 'k')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&

				kurilentele[y][x - 1] != 'O' && kurilentele[y - 1][x - 1] != 'O' && kurilentele[y + 1][x - 1] != 'O' && kurilentele[y][x] != 'O' && kurilentele[y][x - 2] != 'O' &&
				kurilentele[y][x - 2] != 'O' && kurilentele[y - 1][x - 2] != 'O' && kurilentele[y + 1][x - 2] != 'O' && kurilentele[y][x - 1] != 'O' && kurilentele[y][x - 3] != 'O' &&
				//tikrina ar uz ribu
				x - 2 < ilgis && x - 2 >= 0 &&
				x - 1 < ilgis && x - 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
		else if (puse == 'a')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&

				kurilentele[y + 1][x] != 'O' && kurilentele[y][x] != 'O' && kurilentele[y + 2][x] != 'O' && kurilentele[y + 1][x + 1] != 'O' && kurilentele[y + 1][x - 1] != 'O' &&
				kurilentele[y + 2][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y + 3][x] != 'O' && kurilentele[y + 2][x + 1] != 'O' && kurilentele[y + 2][x - 1] != 'O' &&
				//tikrina ar uz ribu
				y + 2 < ilgis && y + 2 >= 0 &&
				y + 1 < ilgis && y + 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
		else if (puse == 'd')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&

				kurilentele[y][x + 1] != 'O' && kurilentele[y - 1][x + 1] != 'O' && kurilentele[y + 1][x + 1] != 'O' && kurilentele[y][x + 2] != 'O' && kurilentele[y][x] != 'O' &&
				kurilentele[y][x + 2] != 'O' && kurilentele[y - 1][x + 2] != 'O' && kurilentele[y + 1][x + 2] != 'O' && kurilentele[y][x + 3] != 'O' && kurilentele[y][x + 1] != 'O' &&
				//tikrina ar uz ribu
				x + 2 < ilgis && x + 2 >= 0 &&
				x + 1 < ilgis && x + 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
	}
	else if (kiekVietu == 2)
	{
		if (puse == 'v')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&
				kurilentele[y - 1][x] != 'O' && kurilentele[y - 2][x] != 'O' && kurilentele[y][x] != 'O' && kurilentele[y - 1][x + 1] != 'O' && kurilentele[y - 1][x - 1] != 'O' &&
				//tikrina ar uz ribu
				y - 1 < ilgis && y - 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
		else if (puse == 'k')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&

				kurilentele[y][x - 1] != 'O' && kurilentele[y - 1][x - 1] != 'O' && kurilentele[y + 1][x - 1] != 'O' && kurilentele[y][x] != 'O' && kurilentele[y][x - 2] != 'O' &&
				//tikrina ar uz ribu
				x - 1 < ilgis && x - 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
		else if (puse == 'a')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&

				kurilentele[y + 1][x] != 'O' && kurilentele[y][x] != 'O' && kurilentele[y + 2][x] != 'O' && kurilentele[y + 1][x + 1] != 'O' && kurilentele[y + 1][x - 1] != 'O' &&
				//tikrina ar uz ribu
				y + 1 < ilgis && y + 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}
		else if (puse == 'd')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&

				kurilentele[y][x + 1] != 'O' && kurilentele[y - 1][x + 1] != 'O' && kurilentele[y + 1][x + 1] != 'O' && kurilentele[y][x + 2] != 'O' && kurilentele[y][x] != 'O' &&
				//tikrina ar uz ribu
				x + 1 < ilgis && x + 1 >= 0 &&
				y < ilgis && y >= 0 &&
				x < ilgis && x >= 0)
			{
				return true;
			}
			else
			{

				return false;
			}
		}

	}
	else
	{
		//Tikrina ar yra kitas laivas salia
			//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
		if (kurilentele[y][x] != 'O' && kurilentele[y - 1][x] != 'O' && kurilentele[y + 1][x] != 'O' && kurilentele[y][x + 1] != 'O' && kurilentele[y][x - 1] != 'O' &&
			//tikrina ar uz ribu
			y < ilgis && y >= 0 &&
			x < ilgis && x >= 0)
		{
			return true;
		}
		else
		{

			return false;
		}
	}
}

void Zaidimas::zaidejoLaivuIvedimas(int &x, int &y, char &kryptis, bool reikia)
{

	cout << "Irasykite koordinate x: ";
	cin >> x;
	if (x > plotis || x < 1 || cin.fail())
	{
		while (true)
		{
			cin.clear();
			cin.ignore();
			cout << "Bloga koordinate y, bandykite dar karta: ";
			cin >> x;
			if (x <= plotis && x >= 1)
			{
				break;
			}
		}
	}

	cout << "Irasykite koordinate y: ";
	cin >> y;
	if (y > ilgis || y < 1 || cin.fail())
	{
		while (true)
		{
			cin.clear();
			cin.ignore();
			cout << "Bloga koordinate y, bandykite dar karta: ";
			cin >> y;
			if (y <= ilgis && y >= 1)
			{
				break;
			}
		}
	}

	if (reikia)
	{
		cout << "Irasykite kuria kriptimi stoves laivas (virsus - v, kaire - k, apacia - a, desine - d): ";
		cin >> kryptis;
		if (kryptis != 'v' && kryptis != 'k' && kryptis != 'a' && kryptis != 'd')
		{
			while (true)
			{
				cout << "Bloga kryptis, bandykite dar karta: ";
				cin >> kryptis;
				if (kryptis == 'v' || kryptis == 'k' || kryptis == 'a' || kryptis == 'd')
				{
					break;
				}
			}
		}
	}
}

void Zaidimas::BOTlaivuIvedimas()
{
	srand(time(NULL));

	bool reikia = true;

	for (int i = 0; i < 5; i++)
	{
		//virsus - v, kaire - k, apacia - a, desine - d
		char puse;
		int temp;
		int x;
		int y;

		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		temp = rand() % 4 + 1;

		if (temp == 1)
		{
			puse = 'v';
		}
		else if (temp == 2)
		{
			puse = 'k';
		}
		else if (temp == 3)
		{
			puse = 'a';
		}
		else if (temp == 4)
		{
			puse = 'd';
		}

		if (i == 0)
		{
			x -= 1;
			y -= 1;

			bool neveikia = true;
			while (neveikia)
			{
				if (statimoTikrinimas(i, puse, x, y, lenteleBOT))
				{
					if (puse == 'v')
					{
						lenteleBOT[y][x] = 'O';
						lenteleBOT[y - 1][x] = 'O';
						lenteleBOT[y - 2][x] = 'O';
						lenteleBOT[y - 3][x] = 'O';
					}
					else if (puse == 'k')
					{
						lenteleBOT[y][x] = 'O';
						lenteleBOT[y][x - 1] = 'O';
						lenteleBOT[y][x - 2] = 'O';
						lenteleBOT[y][x - 3] = 'O';
					}
					else if (puse == 'a')
					{
						lenteleBOT[y][x] = 'O';
						lenteleBOT[y + 1][x] = 'O';
						lenteleBOT[y + 2][x] = 'O';
						lenteleBOT[y + 3][x] = 'O';
					}
					else if (puse == 'd')
					{
						lenteleBOT[y][x] = 'O';
						lenteleBOT[y][x + 1] = 'O';
						lenteleBOT[y][x + 2] = 'O';
						lenteleBOT[y][x + 3] = 'O';
					}

					surasymas(x, y, puse, i, BOTX, BOTY);

					neveikia = false;
				}
				else
				{
					x = rand() % 10 + 1;
					y = rand() % 10 + 1;
					temp = rand() % 4 + 1;

					if (temp == 1)
					{
						puse = 'v';
					}
					else if (temp == 2)
					{
						puse = 'k';
					}
					else if (temp == 3)
					{
						puse = 'a';
					}
					else if (temp == 4)
					{
						puse = 'd';
					}

					x -= 1;
					y -= 1;

				}
			}
		}
		else if (i == 1)
		{
			for (int j = 0; j < 2; j++)
			{
				x -= 1;
				y -= 1;
				bool neveikia = true;
				while (neveikia)
				{
					if (statimoTikrinimas(i, puse, x, y, lenteleBOT))
					{
						if (puse == 'v')
						{
							lenteleBOT[y][x] = 'O';
							lenteleBOT[y - 1][x] = 'O';
							lenteleBOT[y - 2][x] = 'O';
						}
						else if (puse == 'k')
						{
							lenteleBOT[y][x] = 'O';
							lenteleBOT[y][x - 1] = 'O';
							lenteleBOT[y][x - 2] = 'O';
						}
						else if (puse == 'a')
						{
							lenteleBOT[y][x] = 'O';
							lenteleBOT[y + 1][x] = 'O';
							lenteleBOT[y + 2][x] = 'O';
						}
						else if (puse == 'd')
						{
							lenteleBOT[y][x] = 'O';
							lenteleBOT[y][x + 1] = 'O';
							lenteleBOT[y][x + 2] = 'O';
						}

						surasymas(x, y, puse, i, BOTX, BOTY);

						neveikia = false;
					}
					else
					{
						x = rand() % 10 + 1;
						y = rand() % 10 + 1;
						temp = rand() % 4 + 1;

						if (temp == 1)
						{
							puse = 'v';
						}
						else if (temp == 2)
						{
							puse = 'k';
						}
						else if (temp == 3)
						{
							puse = 'a';
						}
						else if (temp == 4)
						{
							puse = 'd';
						}

						x -= 1;
						y -= 1;
					}
				}
			}
		}
		else if (i == 2)
		{
			for (int j = 0; j < 3; j++)
			{
				x -= 1;
				y -= 1;
				bool neveikia = true;
				while (neveikia)
				{
					if (statimoTikrinimas(i, puse, x, y, lenteleBOT))
					{
						if (puse == 'v')
						{
							lenteleBOT[y][x] = 'O';
							lenteleBOT[y - 1][x] = 'O';
						}
						else if (puse == 'k')
						{
							lenteleBOT[y][x] = 'O';
							lenteleBOT[y][x - 1] = 'O';
						}
						else if (puse == 'a')
						{
							lenteleBOT[y][x] = 'O';
							lenteleBOT[y + 1][x] = 'O';
						}
						else if (puse == 'd')
						{
							lenteleBOT[y][x] = 'O';
							lenteleBOT[y][x + 1] = 'O';
						}

						surasymas(x, y, puse, i, BOTX, BOTY);

						neveikia = false;
					}
					else
					{
						x = rand() % 10 + 1;
						y = rand() % 10 + 1;
						temp = rand() % 4 + 1;

						if (temp == 1)
						{
							puse = 'v';
						}
						else if (temp == 2)
						{
							puse = 'k';
						}
						else if (temp == 3)
						{
							puse = 'a';
						}
						else if (temp == 4)
						{
							puse = 'd';
						}

						x -= 1;
						y -= 1;
					}
				}
			}
		}
		else if (i == 3)
		{
			reikia = false;

			for (int j = 0; j < 4; j++)
			{
				x -= 1;
				y -= 1;
				bool neveikia = true;
				while (neveikia)
				{
					if (statimoTikrinimas(i, puse, x, y, lenteleBOT))
					{
						lenteleBOT[y][x] = 'O';

						surasymas(x, y, puse, i, BOTX, BOTY);

						neveikia = false;
					}
					else
					{
						x = rand() % 10 + 1;
						y = rand() % 10 + 1;
						temp = rand() % 4 + 1;

						if (temp == 1)
						{
							puse = 'v';
						}
						else if (temp == 2)
						{
							puse = 'k';
						}
						else if (temp == 3)
						{
							puse = 'a';
						}
						else if (temp == 4)
						{
							puse = 'd';
						}

						x -= 1;
						y -= 1;
					}
				}
			}
		}
	}
}

void Zaidimas::numustoLaivoTikrinimas(int x, int y, char irasomaLentele[][10], char tikrinamaLentele[][10], vector<int>& kurpaimtiX, vector<int>& kurpaimtiY)
{
	for (int i = 0; i < 20; i++)
	{
		if (kurpaimtiX[i] == x && kurpaimtiY[i] == y)
		{
			tikrinamaLentele[kurpaimtiY[i]][kurpaimtiX[i]] = 'x';
			irasomaLentele[kurpaimtiY[i]][kurpaimtiX[i]] = 'x';
			if (i >= 0 && i <= 3)//keturvietis
			{
				if (tikrinamaLentele[kurpaimtiY[0]][kurpaimtiX[0]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[1]][kurpaimtiX[1]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[2]][kurpaimtiX[2]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[3]][kurpaimtiX[3]] == 'x')
				{
					irasomaLentele[kurpaimtiY[0]][kurpaimtiX[0]] = '-';
					irasomaLentele[kurpaimtiY[1]][kurpaimtiX[1]] = '-';
					irasomaLentele[kurpaimtiY[2]][kurpaimtiX[2]] = '-';
					irasomaLentele[kurpaimtiY[3]][kurpaimtiX[3]] = '-';

					tikrinamaLentele[kurpaimtiY[0]][kurpaimtiX[0]] = '-';
					tikrinamaLentele[kurpaimtiY[1]][kurpaimtiX[1]] = '-';
					tikrinamaLentele[kurpaimtiY[2]][kurpaimtiX[2]] = '-';
					tikrinamaLentele[kurpaimtiY[3]][kurpaimtiX[3]] = '-';
				}

			}
			else if (i >= 4 && i <= 6)//trivietis
			{
				if (tikrinamaLentele[kurpaimtiY[4]][kurpaimtiX[4]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[5]][kurpaimtiX[5]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[6]][kurpaimtiX[6]] == 'x')
				{
					irasomaLentele[kurpaimtiY[4]][kurpaimtiX[4]] = '-';
					irasomaLentele[kurpaimtiY[5]][kurpaimtiX[5]] = '-';
					irasomaLentele[kurpaimtiY[6]][kurpaimtiX[6]] = '-';

					tikrinamaLentele[kurpaimtiY[4]][kurpaimtiX[4]] = '-';
					tikrinamaLentele[kurpaimtiY[5]][kurpaimtiX[5]] = '-';
					tikrinamaLentele[kurpaimtiY[6]][kurpaimtiX[6]] = '-';
				}
			}
			else if (i >= 7 && i <= 9)//trivietis
			{
				if (tikrinamaLentele[kurpaimtiY[7]][kurpaimtiX[7]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[8]][kurpaimtiX[8]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[9]][kurpaimtiX[9]] == 'x')
				{
					irasomaLentele[kurpaimtiY[7]][kurpaimtiX[7]] = '-';
					irasomaLentele[kurpaimtiY[8]][kurpaimtiX[8]] = '-';
					irasomaLentele[kurpaimtiY[9]][kurpaimtiX[9]] = '-';

					tikrinamaLentele[kurpaimtiY[7]][kurpaimtiX[7]] = '-';
					tikrinamaLentele[kurpaimtiY[8]][kurpaimtiX[8]] = '-';
					tikrinamaLentele[kurpaimtiY[9]][kurpaimtiX[9]] = '-';
				}
			}
			else if (i >= 10 && i <= 11)//dvivietis
			{
				if (tikrinamaLentele[kurpaimtiY[10]][kurpaimtiX[10]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[11]][kurpaimtiX[11]] == 'x')
				{
					irasomaLentele[kurpaimtiY[10]][kurpaimtiX[10]] = '-';
					irasomaLentele[kurpaimtiY[11]][kurpaimtiX[11]] = '-';

					tikrinamaLentele[kurpaimtiY[10]][kurpaimtiX[10]] = '-';
					tikrinamaLentele[kurpaimtiY[11]][kurpaimtiX[11]] = '-';
				}
			}
			else if (i >= 12 && i <= 13)//dvivietis
			{
				if (tikrinamaLentele[kurpaimtiY[12]][kurpaimtiX[12]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[13]][kurpaimtiX[13]] == 'x')
				{
					irasomaLentele[kurpaimtiY[12]][kurpaimtiX[12]] = '-';
					irasomaLentele[kurpaimtiY[13]][kurpaimtiX[13]] = '-';

					tikrinamaLentele[kurpaimtiY[12]][kurpaimtiX[12]] = '-';
					tikrinamaLentele[kurpaimtiY[13]][kurpaimtiX[13]] = '-';
				}
			}
			else if (i >= 14 && i <= 15)//dvivietis
			{
				if (tikrinamaLentele[kurpaimtiY[14]][kurpaimtiX[14]] == 'x' &&
					tikrinamaLentele[kurpaimtiY[15]][kurpaimtiX[15]] == 'x')
				{
					irasomaLentele[kurpaimtiY[14]][kurpaimtiX[14]] = '-';
					irasomaLentele[kurpaimtiY[15]][kurpaimtiX[15]] = '-';

					tikrinamaLentele[kurpaimtiY[14]][kurpaimtiX[14]] = '-';
					tikrinamaLentele[kurpaimtiY[15]][kurpaimtiX[15]] = '-';
				}
			}
			else if (i >= 16 && i <= 19)//vienvietis
			{
				irasomaLentele[kurpaimtiY[i]][kurpaimtiX[i]] = '-';
				tikrinamaLentele[kurpaimtiY[i]][kurpaimtiX[i]] = '-';
			}
			break;
		}
	}
}

void Zaidimas::saudimasZmogaus()
{
	int x, y;
	cout << "Kur norite sauti?\n";
	cout << "Irasykite koordinate x: ";
	cin >> x;
	cout << "Irasykite koordinate y: ";
	cin >> y;

	x -= 1;
	y -= 1;

	if (lenteleBOT[y][x] == '*' || lenteleBOT[y][x] == 'x' || lenteleBOT[y][x] == '-' || x > 9 || x < 0 || y > 9 || y < 0)
	{
		bool netinka = true;
		while (netinka)
		{
			cout << "Netinkamas pasirinkimas\n";
			cout << "Irasykite koordinate x: ";
			cin >> x;
			cout << "Irasykite koordinate y: ";
			cin >> y;
			x -= 1;
			y -= 1;
			if (lenteleBOT[y][x] != '*' && lenteleBOT[y][x] != 'x' && lenteleBOT[y][x] != '-' && x <= 9 && x >= 0 && y <= 9 && y >= 0)
			{
				for (int i = 0; i < 20; i++)
				{
					if (BOTX[i] == x && BOTY[i] == y)
					{
						saudimas(x, y, lenteleBOTmatoma, lenteleBOT, BOTX, BOTY);

						break;
					}
				}

				netinka = false;
			}
		}
	}
	else
		saudimas(x, y, lenteleBOTmatoma, lenteleBOT, BOTX, BOTY);
}

void Zaidimas::saudimasBOT()
{
	srand(time(NULL));
	int x = rand() % 10 + 1;
	int y = rand() % 10 + 1;

	x -= 1;
	y -= 1;

	if (lentele[y][x] == '*' || lentele[y][x] == 'x' || lentele[y][x] == '-' || x > 9 || x < 0 || y > 9 || y < 0)
	{
		bool netinka = true;
		while (netinka)
		{
			x = rand() % 10 + 1;
			y = rand() % 10 + 1;
			x -= 1;
			y -= 1;
			if (lentele[y][x] != '*' && lentele[y][x] != 'x' && lentele[y][x] != '-' && x <= 9 && x >= 0 && y <= 9 && y >= 0)
			{
				for (int i = 0; i < 20; i++)
				{
					if (zmogausX[i] == x && zmogausY[i] == y)
					{
						saudimas(x, y, lentele, lentele, zmogausX, zmogausY);

						break;
					}
				}

				netinka = false;
			}
		}
	}
	else
		saudimas(x, y, lentele, lentele, zmogausX, zmogausY);
}

void Zaidimas::saudimas(int x, int y, char irasomaLentele[][10], char tikrinamaLentele[][10], vector<int>& kurpaimtiX, vector<int>& kurpaimtiY)
{
	if (tikrinamaLentele[y][x] == ' ')
	{
		tikrinamaLentele[y][x] = '*';
		irasomaLentele[y][x] = '*';
	}
	else
	{
		for (int i = 0; i < 20; i++)
		{
			if (kurpaimtiX[i] == x && kurpaimtiY[i] == y)
			{
				numustoLaivoTikrinimas(x, y, irasomaLentele, tikrinamaLentele, kurpaimtiX, kurpaimtiY);

				break;
			}
		}
	}
}

bool Zaidimas::laimejimas(vector<int>& kurX, vector<int>& kurY, char testtikrinamaLentele[][10])
{
	int kiekNumustu = 0;

	for (int i = 0; i < 20; i++)
	{
		if (testtikrinamaLentele[kurY[i]][kurX[i]] == '-')
		{
			kiekNumustu++;
		}
	}
	if (kiekNumustu == 5)
	{
		return true;
	}
	else
		return false;
}

bool Zaidimas::zaidimopabaiga()
{
	if (laimejimas(BOTX, BOTY, lenteleBOT) || laimejimas(zmogausX, zmogausY, lentele))
	{
		return false;
	}
	else
		return true;
}

void Zaidimas::laimejimoPranesimas()
{
	if (laimejimas(BOTX, BOTY, lenteleBOT))
	{
		cout << "Jus laimejote!" << endl;
	}
	else
	{
		cout << "Laimejo kompiuteris :(" << endl;
	}
}

Zaidimas::~Zaidimas()
{
	cout << "Aciu, kad zaidete" << endl;
}
