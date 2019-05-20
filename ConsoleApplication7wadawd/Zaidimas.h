#pragma once

#include<vector>
using namespace std;

class Zaidimas
{
private:
	const static int plotis = 10;
	const static int ilgis = 10;

	char lentele[plotis][ilgis];
	char lenteleBOTmatoma[plotis][ilgis];
	char lenteleBOT[plotis][ilgis];

	vector<int> zmogausX;
	vector<int> zmogausY;

	vector<int> BOTX;
	vector<int> BOTY;

	//int x, y;
	//char kryptis;
public:
	Zaidimas();
	void pradzia();
	void zaidejoLaivuIvedimas(int & x, int & y, char & kryptis, bool reikia);
	void BOTlaivuIvedimas();
	void numustoLaivoTikrinimas(int x, int y, char irasomaLentele[][10], char tikrinamaLentele[][10], vector<int>& kurpaimtiX, vector<int>& kurpaimtiY);
	void saudimasZmogaus();
	void saudimasBOT();
	void saudimas(int x, int y, char irasomaLentele[][10], char tikrinamaLentele[][10], vector<int>& kurpaimtiX, vector<int>& kurpaimtiY);
	~Zaidimas();
	void spausdinimas();
	void surasymas(int x, int y, char kryptis, int vieta, vector<int>& kurIrasytiX, vector<int>& kurIrasytiY);
	void zaidejoPradiniaiLaivai();
	bool statimoTikrinimas(int kiekVietu, char puse, int x, int y, char kurilentele[][10]);
};

