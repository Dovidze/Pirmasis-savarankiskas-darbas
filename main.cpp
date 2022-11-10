#include "Header.h"

int menu() {
	int nr;
	cout << "--------------------------------MENIU------------------------------" << endl;
	cout << "*******************************************************************" << endl;
	cout << "" << endl;
	cout << "1 = Ivesti studento duomenis" << endl;
	cout << "2 = Isvesti studentu vidurkius" << endl;
	cout << "3 = Isvesti studentu medianas" << endl;
	cout << "4 = Nuskaityti Faila ir surikiuoti pagal vardus.  Apskaiciuotas Vidurkis / Mediana" << endl;
	cout << "" << endl;
	cout << "5 = Iseiti " << endl;
	cout << "" << endl;
	cout << "********************************************" << endl;
	cin >> nr;
	system("CLS");
	return nr;
};

int main()
{
	vector<Student> list; // Studento duomenys
	vector<int> fgrades;
	Student student;
	int possibility = 0;
	int provisional = 0;
	possibility = menu();

	while (possibility != 0) {
		try {
			if (possibility < 0 or possibility > 5) {
				throw 422;
			};
			while (possibility == 1) {
				cin >> student; // PERDEGNIMAS >> 
				list.push_back(student);
				student.Deletepaz();
				system("CLS"); // Isvalo konsoles langa
				cout << "********************************************" << endl;
				cout << " Studentas pridetas!" << endl;
				cout << "********************************************" << endl;
				cout << endl << "1 = Prideti sekanti studenta : " << endl;
				cout << "2 = Grizti i pagrindini meniu : " << endl;
				cin >> provisional;
				if (provisional == 2) { system("CLS"); possibility = menu(); };
				system("CLS");
			};
			while (possibility == 2) {
				cout << left << setw(14) << "Pavarde" << left << setw(20) << "Vardas" << "Galutinis(Vid.)" << endl;
				cout << "---------------------------------------------" << endl;
				for (int i = 0; i < list.size(); i++) { cout << list[i]; } // Isveda studentu duomenis (naudoja << perdengima, studentu klaseje)
				cout << "---------------------------------------------" << endl;
				cout << endl << "1 = Grizti i pagrindini meniu" << endl;
				cin >> provisional;
				if (provisional == 1) { system("CLS"); possibility = menu(); };
			};
			while (possibility == 3) {
				cout << left << setw(14) << "Pavarde" << left << setw(20) << "Vardas" << "Galutinis(Med.)" << endl;
				cout << "---------------------------------------------" << endl;
				for (int i = 0; i < list.size(); i++) { list[i].PrintMediana(); }
				cout << "---------------------------------------------" << endl;
				cout << endl << "1 = Grizti i pagrindini meniu" << endl;
				cin >> provisional;
				if (provisional == 1) { system("CLS"); possibility = menu(); };
			};
			while (possibility == 4) {
				int checked = 0;
				if (checked == 0) {
					std::ifstream datafile; // Skaitymo streama
					datafile.open("duomenis/data.txt"); // pasirenka faila
					string str = "", fname = "", fsurname = "";
					double fscore = 0;
					string arr[50];
					std::getline(datafile, str);
					int counter = wordnum(str);
					while (datafile.peek() != EOF) {
						std::getline(datafile, str);
						std::stringstream ss(str);
						for (int i = 0; i < counter; i++) {
							ss >> arr[i];
							if (i == 0) { fname = arr[i]; }
							if (i == 1) { fsurname = arr[i]; }
							if (i > 1 && i < counter - 1) { fgrades.push_back(stoi(arr[i])); }
							if (i + 1 == counter) { fscore = stoi(arr[i]); }
						};
						Student fscholar(fname, fsurname, fgrades, fscore);
						list.push_back(fscholar);
						fgrades.clear();
					};
					checked++;
					std::sort(list.begin(), list.end(), [](const Student& lhs, const Student& rhs) {return lhs.vardas < rhs.vardas; });
				};
				cout << left << setw(14) << "Pavarde" << left << setw(20) << "Vardas" << "FinalScore(avg/med)" << setw(15) << endl;
				cout << "---------------------------------------------" << endl;
				for (int i = 0; i < list.size(); i++) { list[i].PrintFile(); }
				cout << "---------------------------------------------" << endl;
				cout << endl << "1 = Return To Main Menu" << endl;
				cin >> provisional;
				if (provisional == 1) { system("CLS"); possibility = menu(); };
			}
			while (possibility == 5) { possibility = 0; };
		}
		catch (int ExceptionERR) {
			cout << "ERROR " << ExceptionERR << ": Menu option is invalid" << endl;
			system("pause");
			system("CLS");
			possibility = menu();

		};
	};
	return 0;
};
