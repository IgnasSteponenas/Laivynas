#pragma once
#include <vector>
using namespace std;

class game
{
private:
	const static int plotis = 10;
	const static int ilgis = 10;

	vector <int> zmogausX;
	vector <int> zmogausY;

	vector <int> BOTX;
	vector <int> BOTY;

	char lentele[plotis][ilgis];
	char lenteleBOTmatoma[plotis][ilgis];
	char lenteleBOT[plotis][ilgis];

	int x, y;
	char kryptis;
public:
	game();
	void pradzia();
	void surasymas(int x, int y, char kryptis, int vieta);
	void surasymasBOT(int x, int y, char kryptis, int vieta);
	void zaidejoPradiniaiLaivai();
	bool statimoTikrinimas(int kiekVietu, char puse, int x, int y);
	bool statimoTikrinimasBOT(int kiekVietu, char puse, int x, int y);
	void spausdinimas();
	void zaidejoLaivuIvedimas(int & x, int & y, char & kryptis, bool reikia);
	void BOTlaivuIvedimas();
	void numustoLaivoTikrinimas(int x, int y);
	void numustoLaivoTikrinimasBOT(int x, int y);
	void saudimasZmogaus();
	void saudimasBOT();
	~game();

};

