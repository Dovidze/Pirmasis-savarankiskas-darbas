#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

using std::endl;
using std::string;
using std::cout;
using std::cin;

int main() {
	string vardas, pavarde;
	double galutinis = 0, vid = 0;
	int egzpaz, paz, pazsk;

	cout << "Iveskite studento Varda" << endl;
	cin >> vardas;
	cout << "Iveskite studento Pavarde" << endl;
	cin >> pavarde;
	cout << "Iveskite studento pazymiu skaiciu" << endl;
	cin >> pazsk;
	cout << "Iveskite studento pazymius" << endl;
	for (int i = 0; i < pazsk; i++) 
	{
		cin >> paz;
		vid = vid + paz;
	}
	vid = (vid / pazsk) * 0.4;
	cout << "Iveskite egzamino pazymi" << endl;
	cin >> egzpaz;
	galutinis = vid + 0.6 * egzpaz;
	cout << "Studento " << vardas << " " << pavarde << "galutinis pazymis yra " << galutinis;

}
