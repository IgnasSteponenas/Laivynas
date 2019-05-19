#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

void zaidejoLaivuIvedimas(int &x, int &y, char &kryptis, bool reikia);
bool statimoTikrinimas(int kiekVietu, char puse, int x, int y);
bool statimoTikrinimasBOT(int kiekVietu, char puse, int x, int y);
void zaidejoPradiniaiLaivai();
void BOTlaivuIvedimas();
void spausdinimas();

using namespace std;

int const plotis = 10;
int const ilgis = 10;

vector <int> zmogausX;
vector <int> zmogausY;

vector <int> BOTX;
vector <int> BOTY;

char lentele[plotis][ilgis];
char lenteleBOTmatoma[plotis][ilgis];
char lenteleBOT[plotis][ilgis];

bool nesibaige;

void pradzia()
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

void surasymas(int x, int y, char kryptis, int vieta)
{
	if (vieta == 0)
	{
		if (kryptis == 'v')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x);
			zmogausX.push_back(x);
			zmogausX.push_back(x);

			zmogausY.push_back(y);
			zmogausY.push_back(y - 1);
			zmogausY.push_back(y - 2);
			zmogausY.push_back(y - 3);
		}
		else if (kryptis == 'k')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x - 1);
			zmogausX.push_back(x - 2);
			zmogausX.push_back(x - 3);

			zmogausY.push_back(y);
			zmogausY.push_back(y);
			zmogausY.push_back(y);
			zmogausY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x);
			zmogausX.push_back(x);
			zmogausX.push_back(x);

			zmogausY.push_back(y);
			zmogausY.push_back(y + 1);
			zmogausY.push_back(y + 2);
			zmogausY.push_back(y + 3);
		}
		else if (kryptis == 'd')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x + 1);
			zmogausX.push_back(x + 2);
			zmogausX.push_back(x + 3);

			zmogausY.push_back(y);
			zmogausY.push_back(y);
			zmogausY.push_back(y);
			zmogausY.push_back(y);
		}
	}
	else if (vieta == 1)
	{
		if (kryptis == 'v')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x);
			zmogausX.push_back(x);

			zmogausY.push_back(y);
			zmogausY.push_back(y - 1);
			zmogausY.push_back(y - 2);
		}
		else if (kryptis == 'k')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x - 1);
			zmogausX.push_back(x - 2);

			zmogausY.push_back(y);
			zmogausY.push_back(y);
			zmogausY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x);
			zmogausX.push_back(x);

			zmogausY.push_back(y);
			zmogausY.push_back(y + 1);
			zmogausY.push_back(y + 2);
		}
		else if (kryptis == 'd')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x + 1);
			zmogausX.push_back(x + 2);

			zmogausY.push_back(y);
			zmogausY.push_back(y);
			zmogausY.push_back(y);
		}
	}
	else if (vieta == 2)
	{
		if (kryptis == 'v')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x);

			zmogausY.push_back(y);
			zmogausY.push_back(y - 1);
		}
		else if (kryptis == 'k')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x - 1);

			zmogausY.push_back(y);
			zmogausY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x);

			zmogausY.push_back(y);
			zmogausY.push_back(y + 1);
		}
		else if (kryptis == 'd')
		{
			zmogausX.push_back(x);
			zmogausX.push_back(x + 1);

			zmogausY.push_back(y);
			zmogausY.push_back(y);
		}
		}
	else if (vieta == 3)
	{
		if (kryptis == 'v')
		{
			zmogausX.push_back(x);

			zmogausY.push_back(y);
		}
		else if (kryptis == 'k')
		{
			zmogausX.push_back(x);

			zmogausY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			zmogausX.push_back(x);

			zmogausY.push_back(y);
		}
		else if (kryptis == 'd')
		{
			zmogausX.push_back(x);

			zmogausY.push_back(y);
		}
	}
}

void surasymasBOT(int x, int y, char kryptis, int vieta)
{
	if (vieta == 0)
	{
		if (kryptis == 'v')
		{
			BOTX.push_back(x);
			BOTX.push_back(x);
			BOTX.push_back(x);
			BOTX.push_back(x);

			BOTY.push_back(y);
			BOTY.push_back(y - 1);
			BOTY.push_back(y - 2);
			BOTY.push_back(y - 3);
		}
		else if (kryptis == 'k')
		{
			BOTX.push_back(x);
			BOTX.push_back(x - 1);
			BOTX.push_back(x - 2);
			BOTX.push_back(x - 3);

			BOTY.push_back(y);
			BOTY.push_back(y);
			BOTY.push_back(y);
			BOTY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			BOTX.push_back(x);
			BOTX.push_back(x);
			BOTX.push_back(x);
			BOTX.push_back(x);

			BOTY.push_back(y);
			BOTY.push_back(y + 1);
			BOTY.push_back(y + 2);
			BOTY.push_back(y + 3);
		}
		else if (kryptis == 'd')
		{
			BOTX.push_back(x);
			BOTX.push_back(x + 1);
			BOTX.push_back(x + 2);
			BOTX.push_back(x + 3);

			BOTY.push_back(y);
			BOTY.push_back(y);
			BOTY.push_back(y);
			BOTY.push_back(y);
		}
	}
	else if (vieta == 1)
	{
		if (kryptis == 'v')
		{
			BOTX.push_back(x);
			BOTX.push_back(x);
			BOTX.push_back(x);

			BOTY.push_back(y);
			BOTY.push_back(y - 1);
			BOTY.push_back(y - 2);
		}
		else if (kryptis == 'k')
		{
			BOTX.push_back(x);
			BOTX.push_back(x - 1);
			BOTX.push_back(x - 2);

			BOTY.push_back(y);
			BOTY.push_back(y);
			BOTY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			BOTX.push_back(x);
			BOTX.push_back(x);
			BOTX.push_back(x);

			BOTY.push_back(y);
			BOTY.push_back(y + 1);
			BOTY.push_back(y + 2);
		}
		else if (kryptis == 'd')
		{
			BOTX.push_back(x);
			BOTX.push_back(x + 1);
			BOTX.push_back(x + 2);

			BOTY.push_back(y);
			BOTY.push_back(y);
			BOTY.push_back(y);
		}
	}
	else if (vieta == 2)
	{
		if (kryptis == 'v')
		{
			BOTX.push_back(x);
			BOTX.push_back(x);

			BOTY.push_back(y);
			BOTY.push_back(y - 1);
		}
		else if (kryptis == 'k')
		{
			BOTX.push_back(x);
			BOTX.push_back(x - 1);

			BOTY.push_back(y);
			BOTY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			BOTX.push_back(x);
			BOTX.push_back(x);

			BOTY.push_back(y);
			BOTY.push_back(y + 1);
		}
		else if (kryptis == 'd')
		{
			BOTX.push_back(x);
			BOTX.push_back(x + 1);

			BOTY.push_back(y);
			BOTY.push_back(y);
		}
	}
	else if (vieta == 3)
	{
		if (kryptis == 'v')
		{
			BOTX.push_back(x);

			BOTY.push_back(y);
		}
		else if (kryptis == 'k')
		{
			BOTX.push_back(x);

			BOTY.push_back(y);
		}
		else if (kryptis == 'a')
		{
			BOTX.push_back(x);

			BOTY.push_back(y);
		}
		else if (kryptis == 'd')
		{
			BOTX.push_back(x);

			BOTY.push_back(y);
		}
	}
}

void zaidejoPradiniaiLaivai()
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
				if (statimoTikrinimas(i, kryptis, x, y))
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
					surasymas(x, y, kryptis, i);

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
					if (statimoTikrinimas(i, kryptis, x, y))
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

						surasymas(x, y, kryptis, i);

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
					if (statimoTikrinimas(i, kryptis, x, y))
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

						surasymas(x, y, kryptis, i);

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
					if (statimoTikrinimas(i, kryptis, x, y))
					{
						lentele[y][x] = 'O';

						surasymas(x, y, kryptis, i);

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

bool statimoTikrinimas(int kiekVietu, char puse, int x, int y)
{
	
	if (kiekVietu == 0)
	{
		if (puse == 'v')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&
				lentele[y - 1][x] != 'O' && lentele[y - 2][x] != 'O' && lentele[y][x] != 'O' && lentele[y - 1][x + 1] != 'O' && lentele[y - 1][x - 1] != 'O' &&
				lentele[y - 2][x] != 'O' && lentele[y - 3][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y - 2][x + 1] != 'O' && lentele[y - 2][x - 1] != 'O' &&
				lentele[y - 3][x] != 'O' && lentele[y - 4][x] != 'O' && lentele[y - 2][x] != 'O' && lentele[y - 3][x + 1] != 'O' && lentele[y - 3][x - 1] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&

				lentele[y][x - 1] != 'O' && lentele[y - 1][x - 1] != 'O' && lentele[y + 1][x - 1] != 'O' && lentele[y][x] != 'O' && lentele[y][x - 2] != 'O' &&
				lentele[y][x - 2] != 'O' && lentele[y - 1][x - 2] != 'O' && lentele[y + 1][x - 2] != 'O' && lentele[y][x - 1] != 'O' && lentele[y][x - 3] != 'O' &&
				lentele[y][x - 3] != 'O' && lentele[y - 1][x - 3] != 'O' && lentele[y + 1][x - 3] != 'O' && lentele[y][x - 2] != 'O' && lentele[y][x - 4] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&

				lentele[y + 1][x] != 'O' && lentele[y][x] != 'O' && lentele[y + 2][x] != 'O' && lentele[y + 1][x + 1] != 'O' && lentele[y + 1][x - 1] != 'O' &&
				lentele[y + 2][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y + 3][x] != 'O' && lentele[y + 2][x + 1] != 'O' && lentele[y + 2][x - 1] != 'O' &&
				lentele[y + 3][x] != 'O' && lentele[y + 2][x] != 'O' && lentele[y + 4][x] != 'O' && lentele[y + 3][x + 1] != 'O' && lentele[y + 3][x - 1] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&

				lentele[y][x + 1] != 'O' && lentele[y - 1][x + 1] != 'O' && lentele[y + 1][x + 1] != 'O' && lentele[y][x + 2] != 'O' && lentele[y][x] != 'O' &&
				lentele[y][x + 2] != 'O' && lentele[y - 1][x + 2] != 'O' && lentele[y + 1][x + 2] != 'O' && lentele[y][x + 3] != 'O' && lentele[y][x + 1] != 'O' &&
				lentele[y][x + 3] != 'O' && lentele[y - 1][x + 3] != 'O' && lentele[y + 1][x + 3] != 'O' && lentele[y][x + 4] != 'O' && lentele[y][x + 2] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&
				lentele[y - 1][x] != 'O' && lentele[y - 2][x] != 'O' && lentele[y][x] != 'O' && lentele[y - 1][x + 1] != 'O' && lentele[y - 1][x - 1] != 'O' &&
				lentele[y - 2][x] != 'O' && lentele[y - 3][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y - 2][x + 1] != 'O' && lentele[y - 2][x - 1] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&

				lentele[y][x - 1] != 'O' && lentele[y - 1][x - 1] != 'O' && lentele[y + 1][x - 1] != 'O' && lentele[y][x] != 'O' && lentele[y][x - 2] != 'O' &&
				lentele[y][x - 2] != 'O' && lentele[y - 1][x - 2] != 'O' && lentele[y + 1][x - 2] != 'O' && lentele[y][x - 1] != 'O' && lentele[y][x - 3] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&

				lentele[y + 1][x] != 'O' && lentele[y][x] != 'O' && lentele[y + 2][x] != 'O' && lentele[y + 1][x + 1] != 'O' && lentele[y + 1][x - 1] != 'O' &&
				lentele[y + 2][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y + 3][x] != 'O' && lentele[y + 2][x + 1] != 'O' && lentele[y + 2][x - 1] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&

				lentele[y][x + 1] != 'O' && lentele[y - 1][x + 1] != 'O' && lentele[y + 1][x + 1] != 'O' && lentele[y][x + 2] != 'O' && lentele[y][x] != 'O' &&
				lentele[y][x + 2] != 'O' && lentele[y - 1][x + 2] != 'O' && lentele[y + 1][x + 2] != 'O' && lentele[y][x + 3] != 'O' && lentele[y][x + 1] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&
				lentele[y - 1][x] != 'O' && lentele[y - 2][x] != 'O' && lentele[y][x] != 'O' && lentele[y - 1][x + 1] != 'O' && lentele[y - 1][x - 1] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&

				lentele[y][x - 1] != 'O' && lentele[y - 1][x - 1] != 'O' && lentele[y + 1][x - 1] != 'O' && lentele[y][x] != 'O' && lentele[y][x - 2] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&

				lentele[y + 1][x] != 'O' && lentele[y][x] != 'O' && lentele[y + 2][x] != 'O' && lentele[y + 1][x + 1] != 'O' && lentele[y + 1][x - 1] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&

				lentele[y][x + 1] != 'O' && lentele[y - 1][x + 1] != 'O' && lentele[y + 1][x + 1] != 'O' && lentele[y][x + 2] != 'O' && lentele[y][x] != 'O' &&
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
			if (lentele[y][x] != 'O' && lentele[y - 1][x] != 'O' && lentele[y + 1][x] != 'O' && lentele[y][x + 1] != 'O' && lentele[y][x - 1] != 'O' &&
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

bool statimoTikrinimasBOT(int kiekVietu, char puse, int x, int y)
{

	if (kiekVietu == 0)
	{
		if (puse == 'v')
		{
			//Tikrina ar yra kitas laivas salia
				//pradinis taskas,            i virsu,                         i apacia,                      i desine,                   i kaire.
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&
				lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y - 2][x] != 'O' && lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x + 1] != 'O' && lenteleBOT[y - 1][x - 1] != 'O' &&
				lenteleBOT[y - 2][x] != 'O' && lenteleBOT[y - 3][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y - 2][x + 1] != 'O' && lenteleBOT[y - 2][x - 1] != 'O' &&
				lenteleBOT[y - 3][x] != 'O' && lenteleBOT[y - 4][x] != 'O' && lenteleBOT[y - 2][x] != 'O' && lenteleBOT[y - 3][x + 1] != 'O' && lenteleBOT[y - 3][x - 1] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&

				lenteleBOT[y][x - 1] != 'O' && lenteleBOT[y - 1][x - 1] != 'O' && lenteleBOT[y + 1][x - 1] != 'O' && lenteleBOT[y][x] != 'O' && lenteleBOT[y][x - 2] != 'O' &&
				lenteleBOT[y][x - 2] != 'O' && lenteleBOT[y - 1][x - 2] != 'O' && lenteleBOT[y + 1][x - 2] != 'O' && lenteleBOT[y][x - 1] != 'O' && lenteleBOT[y][x - 3] != 'O' &&
				lenteleBOT[y][x - 3] != 'O' && lenteleBOT[y - 1][x - 3] != 'O' && lenteleBOT[y + 1][x - 3] != 'O' && lenteleBOT[y][x - 2] != 'O' && lenteleBOT[y][x - 4] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&

				lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x] != 'O' && lenteleBOT[y + 2][x] != 'O' && lenteleBOT[y + 1][x + 1] != 'O' && lenteleBOT[y + 1][x - 1] != 'O' &&
				lenteleBOT[y + 2][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y + 3][x] != 'O' && lenteleBOT[y + 2][x + 1] != 'O' && lenteleBOT[y + 2][x - 1] != 'O' &&
				lenteleBOT[y + 3][x] != 'O' && lenteleBOT[y + 2][x] != 'O' && lenteleBOT[y + 4][x] != 'O' && lenteleBOT[y + 3][x + 1] != 'O' && lenteleBOT[y + 3][x - 1] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&

				lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y - 1][x + 1] != 'O' && lenteleBOT[y + 1][x + 1] != 'O' && lenteleBOT[y][x + 2] != 'O' && lenteleBOT[y][x] != 'O' &&
				lenteleBOT[y][x + 2] != 'O' && lenteleBOT[y - 1][x + 2] != 'O' && lenteleBOT[y + 1][x + 2] != 'O' && lenteleBOT[y][x + 3] != 'O' && lenteleBOT[y][x + 1] != 'O' &&
				lenteleBOT[y][x + 3] != 'O' && lenteleBOT[y - 1][x + 3] != 'O' && lenteleBOT[y + 1][x + 3] != 'O' && lenteleBOT[y][x + 4] != 'O' && lenteleBOT[y][x + 2] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&
				lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y - 2][x] != 'O' && lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x + 1] != 'O' && lenteleBOT[y - 1][x - 1] != 'O' &&
				lenteleBOT[y - 2][x] != 'O' && lenteleBOT[y - 3][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y - 2][x + 1] != 'O' && lenteleBOT[y - 2][x - 1] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&

				lenteleBOT[y][x - 1] != 'O' && lenteleBOT[y - 1][x - 1] != 'O' && lenteleBOT[y + 1][x - 1] != 'O' && lenteleBOT[y][x] != 'O' && lenteleBOT[y][x - 2] != 'O' &&
				lenteleBOT[y][x - 2] != 'O' && lenteleBOT[y - 1][x - 2] != 'O' && lenteleBOT[y + 1][x - 2] != 'O' && lenteleBOT[y][x - 1] != 'O' && lenteleBOT[y][x - 3] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&

				lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x] != 'O' && lenteleBOT[y + 2][x] != 'O' && lenteleBOT[y + 1][x + 1] != 'O' && lenteleBOT[y + 1][x - 1] != 'O' &&
				lenteleBOT[y + 2][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y + 3][x] != 'O' && lenteleBOT[y + 2][x + 1] != 'O' && lenteleBOT[y + 2][x - 1] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&

				lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y - 1][x + 1] != 'O' && lenteleBOT[y + 1][x + 1] != 'O' && lenteleBOT[y][x + 2] != 'O' && lenteleBOT[y][x] != 'O' &&
				lenteleBOT[y][x + 2] != 'O' && lenteleBOT[y - 1][x + 2] != 'O' && lenteleBOT[y + 1][x + 2] != 'O' && lenteleBOT[y][x + 3] != 'O' && lenteleBOT[y][x + 1] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&
				lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y - 2][x] != 'O' && lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x + 1] != 'O' && lenteleBOT[y - 1][x - 1] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&

				lenteleBOT[y][x - 1] != 'O' && lenteleBOT[y - 1][x - 1] != 'O' && lenteleBOT[y + 1][x - 1] != 'O' && lenteleBOT[y][x] != 'O' && lenteleBOT[y][x - 2] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&

				lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x] != 'O' && lenteleBOT[y + 2][x] != 'O' && lenteleBOT[y + 1][x + 1] != 'O' && lenteleBOT[y + 1][x - 1] != 'O' &&
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
			if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&

				lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y - 1][x + 1] != 'O' && lenteleBOT[y + 1][x + 1] != 'O' && lenteleBOT[y][x + 2] != 'O' && lenteleBOT[y][x] != 'O' &&
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
		if (lenteleBOT[y][x] != 'O' && lenteleBOT[y - 1][x] != 'O' && lenteleBOT[y + 1][x] != 'O' && lenteleBOT[y][x + 1] != 'O' && lenteleBOT[y][x - 1] != 'O' &&
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

void spausdinimas()
{
	system("CLS");
	cout << "-------------------BOT----------------------" << endl << endl;
	cout << "-------------------BOT----------------------" << endl << endl;

	cout << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n";

	for (int i = 0; i < ilgis; i++)
	{
		//cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
	//cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	//cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "-------------------Zmogaus------------------" << endl << endl;

	cout << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n";

	for (int i = 0; i < ilgis; i++)
	{
		//cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		if (i < 9)
			cout << " " << i + 1;
		else
			cout << i + 1 << "";

		for (int j = 0; j < plotis; j++)
		{
			
			cout  << " | " << lentele[i][j];
		}
		cout << " |" <<endl;
	}
	//cout << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void zaidejoLaivuIvedimas(int &x, int &y, char &kryptis, bool reikia)
{

	cout << "Irasykite koordinate x: ";
	cin >> x;
	if (x > plotis || x < 1)
	{
		while (true)
		{
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
	if (y > ilgis || y < 1)
	{
		while (true)
		{
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

void BOTlaivuIvedimas()
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
				if (statimoTikrinimasBOT(i, puse, x, y))
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

					surasymasBOT(x, y, puse, i);

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
					if (statimoTikrinimasBOT(i, puse, x, y))
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

						surasymasBOT(x, y, puse, i);

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
					if (statimoTikrinimasBOT(i, puse, x, y))
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

						surasymasBOT(x, y, puse, i);

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
					if (statimoTikrinimasBOT(i, puse, x, y))
					{
						lenteleBOT[y][x] = 'O';

						surasymasBOT(x, y, puse, i);

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

void numustoLaivoTikrinimas(int x, int y)
{
	for (int i = 0; i < 20; i++)
	{
		if (BOTX[i] == x && BOTY[i] == y)
		{
			lenteleBOT[BOTY[i]][BOTX[i]] = 'x';
			lenteleBOTmatoma[BOTY[i]][BOTX[i]] = 'x';
			if (i >= 0 && i <= 3)//keturvietis
			{
				if (lenteleBOT[BOTY[0]][BOTX[0]] == 'x' &&
					lenteleBOT[BOTY[1]][BOTX[1]] == 'x' &&
					lenteleBOT[BOTY[2]][BOTX[2]] == 'x' &&
					lenteleBOT[BOTY[3]][BOTX[3]] == 'x')
				{
					lenteleBOT[BOTY[0]][BOTX[0]] = '-';//bot laivai
					lenteleBOT[BOTY[1]][BOTX[1]] = '-';
					lenteleBOT[BOTY[2]][BOTX[2]] = '-';
					lenteleBOT[BOTY[3]][BOTX[3]] = '-';

					lenteleBOTmatoma[BOTY[0]][BOTX[0]] = '-';//vaizdas
					lenteleBOTmatoma[BOTY[1]][BOTX[1]] = '-';
					lenteleBOTmatoma[BOTY[2]][BOTX[2]] = '-';
					lenteleBOTmatoma[BOTY[3]][BOTX[3]] = '-';
				}

			}
			else if (i >= 4 && i <= 6)//trivietis
			{
				if (lenteleBOT[BOTY[4]][BOTX[4]] == 'x' &&
					lenteleBOT[BOTY[5]][BOTX[5]] == 'x' &&
					lenteleBOT[BOTY[6]][BOTX[6]] == 'x')
				{
					lenteleBOT[BOTY[4]][BOTX[4]] = '-';
					lenteleBOT[BOTY[5]][BOTX[5]] = '-';
					lenteleBOT[BOTY[6]][BOTX[6]] = '-';

					lenteleBOTmatoma[BOTY[4]][BOTX[4]] = '-';
					lenteleBOTmatoma[BOTY[5]][BOTX[5]] = '-';
					lenteleBOTmatoma[BOTY[6]][BOTX[6]] = '-';
				}
			}
			else if (i >= 7 && i <= 9)//trivietis
			{
				if (lenteleBOT[BOTY[7]][BOTX[7]] == 'x' &&
					lenteleBOT[BOTY[8]][BOTX[8]] == 'x' &&
					lenteleBOT[BOTY[9]][BOTX[9]] == 'x')
				{
					lenteleBOT[BOTY[7]][BOTX[7]] = '-';
					lenteleBOT[BOTY[8]][BOTX[8]] = '-';
					lenteleBOT[BOTY[9]][BOTX[9]] = '-';

					lenteleBOTmatoma[BOTY[7]][BOTX[7]] = '-';
					lenteleBOTmatoma[BOTY[8]][BOTX[8]] = '-';
					lenteleBOTmatoma[BOTY[9]][BOTX[9]] = '-';
				}
			}
			else if (i >= 10 && i <= 11)//dvivietis
			{
				if (lenteleBOT[BOTY[10]][BOTX[10]] == 'x' &&
					lenteleBOT[BOTY[11]][BOTX[11]] == 'x' )
				{
					lenteleBOT[BOTY[10]][BOTX[10]] = '-';
					lenteleBOT[BOTY[11]][BOTX[11]] = '-';

					lenteleBOTmatoma[BOTY[10]][BOTX[10]] = '-';
					lenteleBOTmatoma[BOTY[11]][BOTX[11]] = '-';
				}
			}
			else if (i >= 12 && i <= 13)//dvivietis
			{
				if (lenteleBOT[BOTY[12]][BOTX[12]] == 'x' &&
					lenteleBOT[BOTY[13]][BOTX[13]] == 'x' )
				{
					lenteleBOT[BOTY[12]][BOTX[12]] = '-';
					lenteleBOT[BOTY[13]][BOTX[13]] = '-';

					lenteleBOTmatoma[BOTY[12]][BOTX[12]] = '-';
					lenteleBOTmatoma[BOTY[13]][BOTX[13]] = '-';
				}
			}
			else if (i >= 14 && i <= 15)//dvivietis
			{
				if (lenteleBOT[BOTY[14]][BOTX[14]] == 'x' &&
					lenteleBOT[BOTY[15]][BOTX[15]] == 'x' )
				{
					lenteleBOT[BOTY[14]][BOTX[14]] = '-';
					lenteleBOT[BOTY[15]][BOTX[15]] = '-';

					lenteleBOTmatoma[BOTY[14]][BOTX[14]] = '-';
					lenteleBOTmatoma[BOTY[15]][BOTX[15]] = '-';
				}
			}
			else if (i >= 16 && i <=19)//vienvietis
			{
					lenteleBOT[BOTY[i]][BOTX[i]] = '-';

					lenteleBOTmatoma[BOTY[i]][BOTX[i]] = '-';
			}
			break;
		}
	}
}

void numustoLaivoTikrinimasBOT(int x, int y)
{
	for (int i = 0; i < 20; i++)
	{
		if (zmogausX[i] == x && zmogausY[i] == y)
		{
			lentele[zmogausY[i]][zmogausX[i]] = 'x';
			if (i >= 0 && i <= 3)//keturvietis
			{
				if (lentele[zmogausY[0]][zmogausX[0]] == 'x' &&
					lentele[zmogausY[1]][zmogausX[1]] == 'x' &&
					lentele[zmogausY[2]][zmogausX[2]] == 'x' &&
					lentele[zmogausY[3]][zmogausX[3]] == 'x')
				{
					lentele[zmogausY[0]][zmogausX[0]] = '-';
					lentele[zmogausY[1]][zmogausX[1]] = '-';
					lentele[zmogausY[2]][zmogausX[2]] = '-';
					lentele[zmogausY[3]][zmogausX[3]] = '-';
				}

			}
			else if (i >= 4 && i <= 6)//trivietis
			{
				if (lentele[zmogausY[4]][zmogausX[4]] == 'x' &&
					lentele[zmogausY[5]][zmogausX[5]] == 'x' &&
					lentele[zmogausY[6]][zmogausX[6]] == 'x')
				{
					lentele[zmogausY[4]][zmogausX[4]] = '-';
					lentele[zmogausY[5]][zmogausX[5]] = '-';
					lentele[zmogausY[6]][zmogausX[6]] = '-';
				}
			}
			else if (i >= 7 && i <= 9)//trivietis
			{
				if (lentele[zmogausY[7]][zmogausX[7]] == 'x' &&
					lentele[zmogausY[8]][zmogausX[8]] == 'x' &&
					lentele[zmogausY[9]][zmogausX[9]] == 'x')
				{
					lentele[zmogausY[7]][zmogausX[7]] = '-';
					lentele[zmogausY[8]][zmogausX[8]] = '-';
					lentele[zmogausY[9]][zmogausX[9]] = '-';
				}
			}
			else if (i >= 10 && i <= 11)//dvivietis
			{
				if (lentele[zmogausY[10]][zmogausX[10]] == 'x' &&
					lentele[zmogausY[11]][zmogausX[11]] == 'x')
				{
					lentele[zmogausY[10]][zmogausX[10]] = '-';
					lentele[zmogausY[11]][zmogausX[11]] = '-';
				}
			}
			else if (i >= 12 && i <= 13)//dvivietis
			{
				if (lentele[zmogausY[12]][zmogausX[12]] == 'x' &&
					lentele[zmogausY[13]][zmogausX[13]] == 'x')
				{
					lentele[zmogausY[12]][zmogausX[12]] = '-';
					lentele[zmogausY[13]][zmogausX[13]] = '-';
				}
			}
			else if (i >= 14 && i <= 15)//dvivietis
			{
				if (lentele[zmogausY[14]][zmogausX[14]] == 'x' &&
					lentele[zmogausY[15]][zmogausX[15]] == 'x')
				{
					lentele[zmogausY[14]][zmogausX[14]] = '-';
					lentele[zmogausY[15]][zmogausX[15]] = '-';
				}
			}
			else if (i >= 16 && i <= 19)//vienvietis
			{
				lentele[zmogausY[i]][zmogausX[i]] = '-';

			}
			break;
		}
	}
}

void saudimasZmogaus()
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
				for(int i=0; i<20; i++)
				{
					if (BOTX[i] == x && BOTY[i] == y)
					{
						numustoLaivoTikrinimas(x, y);

						break;
					}
				}

				netinka = false;
			}
		}
	}
	else if (lenteleBOT[y][x] == ' ')
	{
		lenteleBOT[y][x] = '*';
		lenteleBOTmatoma[y][x] = '*';
	}
	else
	{
		for (int i = 0; i < 20; i++)
		{
			if (BOTX[i] == x && BOTY[i] == y)
			{
				numustoLaivoTikrinimas(x, y);

				break;
			}
		}
	}
}

void saudimasBOT()
{
	int x, y;

	srand(time(NULL));
	x = rand() % 10 + 1;
	y = rand() % 10 + 1;

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
						numustoLaivoTikrinimasBOT(x, y);

						break;
					}
				}

				netinka = false;
			}
		}
	}
	else if (lentele[y][x] == ' ')
	{
		lentele[y][x] = '*';
	}
	else
	{
		for (int i = 0; i < 20; i++)
		{
			if (zmogausX[i] == x && zmogausY[i] == y)
			{
				numustoLaivoTikrinimasBOT(x, y);

				break;
			}
		}
	}
}

int main()
{
	nesibaige = true;

	pradzia();


	while(nesibaige)
	{
		saudimasBOT();
		spausdinimas();
		saudimasZmogaus();
	}



	return 0;
}