#include "Header.h"

int menu() {
	int nr;
	cout << "------------------------------------MENIU-----------------------------------------" << endl;
	cout << "**********************************************************************************" << endl;
	cout << "" << endl;
	cout << "1 = Ivesti studento duomenis" << endl;
	cout << "2 = Isvesti studentu vidurkius" << endl;
	cout << "3 = Isvesti studentu medianas" << endl;
	cout << "" << endl;
	cout << "4 = Nuskaityti Faila ir surikiuoti pagal vardus.  Apskaiciuotas Vidurkis / Mediana" << endl;
	cout << "" << endl;
	cout << "5 = Sugeneruoti atsitiktinius studentu sarasus 5-uose failuose. " << endl;
	cout << "6 = Surusuoti studentus failuose - Moksliukai/Vargsiukai " << endl;
	cout << "" << endl;
	cout << "7 = Iseiti " << endl;
	cout << "" << endl;
	cout << "**********************************************************************************" << endl;
	cin >> nr;
	system("CLS");
	return nr;
}
int menuS() {
	cout << "---------------SUGENERUOTI FAILA-------------" << endl;
	cout << "*********************************************" << endl;
	cout << "Pasirinkite koki faila norite sugeneruoti" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "1 = Su atsitiktiniais 1000 studentais" << endl;
	cout << "2 = Su atsitiktiniais 10000 studentais" << endl;
	cout << "3 = Su atsitiktiniais 100000 studentais" << endl;
	cout << "4 = Su atsitiktiniais 1000000 studentais" << endl;
	cout << "5 = Su atsitiktiniais 10000000 studentais" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "6 = Grizti i pagrindini meniu" << endl;
	cout << "" << endl;
	return 0;
}
int menuR() {
	cout << "-----------------RUSUOTI FAILA---------------" << endl;
	cout << "*********************************************" << endl;
	cout << "Pasirinkite koki faila norite surusuoti" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "1 = 1000 studentu" << endl;
	cout << "2 = 10000 studentu" << endl;
	cout << "3 = 100000 studentu" << endl;
	cout << "4 = 1000000 studentu" << endl;
	cout << "5 = 10000000 studentu" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "6 = Grizti i pagrindini meniu" << endl;
	cout << "" << endl;
	return 0;
}
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
			if (possibility < 0 or possibility > 7) {
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
				if (provisional == 2) { system("CLS"); possibility = menu(); }
				system("CLS");
			};
			while (possibility == 2) {
				cout << left << setw(15) << "Pavarde" << left << setw(15) << "Vardas" << "Galutinis(Vid.)" << endl;
				cout << "---------------------------------------------" << endl;
				for (int i = 0; i < list.size(); i++) { cout << list[i]; } // Isveda studentu duomenis (naudoja << perdengima, studentu klaseje)
				cout << "---------------------------------------------" << endl;
				cout << endl << "1 = Grizti i pagrindini meniu" << endl;
				cin >> provisional;
				if (provisional == 1) { system("CLS"); possibility = menu(); }
			};
			while (possibility == 3) {
				cout << left << setw(15) << "Pavarde" << left << setw(15) << "Vardas" << "Galutinis(Med.)" << endl;
				cout << "---------------------------------------------" << endl;
				for (int i = 0; i < list.size(); i++) { list[i].PrintMediana(); }
				cout << "---------------------------------------------" << endl;
				cout << endl << "1 = Grizti i pagrindini meniu" << endl;
				cin >> provisional;
				if (provisional == 1) { system("CLS"); possibility = menu(); }
			};
			while (possibility == 4) {
				int checked = 0;
				if (checked == 0) {
					std::ifstream datafile; // Skaitymo streama
					datafile.open("duomenis/kursiokai.txt"); // pasirenka faila
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
				cout << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis(Vid.)" << setw(20) << "Galutinis(Med.)" << endl;
				cout << "--------------------------------------------------------------" << endl;
				for (int i = 0; i < list.size(); i++) { list[i].PrintFile(); }
				cout << "--------------------------------------------------------------" << endl;
				cout << endl << "1 = Grizti i pagrindini meniu" << endl;
				cin >> provisional;
				if (provisional == 1) { system("CLS"); possibility = menu(); };
			}
			while (possibility == 5) {
				int nr = 0;
				std::ofstream datafile;
				possibility = menuS();
				while (nr -= 6) {
					cin >> nr;
					if (nr == 1) {
						// FAILAS SU 1000 STUDENTU
						datafile.open("duomenis/1k.txt");
						if (datafile.is_open()) {
							int rvid;
							int vid;
							float fvid;
							datafile << left << setw(14) << "Pavarde" << left << setw(20) << "Vardas" << "Galutinis(Vid.)" << endl;
							datafile << "---------------------------------------------" << endl;
							for (int i = 1; i < 1000; i++) {
								rvid = rand() % 100 + 1;
								vid = rand() % 10;
								fvid = (float)rvid / 100 + (float)vid;
								datafile << left << setw(14) << "Pavarde" + std::to_string(i) << left << setw(20) << "Vardas" + std::to_string(i) << std::setprecision(3) << fvid << endl;

							}
							datafile.close();
						}
						cout << "Failas su 1000 studentu sugeneruotas!" << endl;
					}
					if (nr == 2) {
						// FAILAS SU 10000 STUDENTU
						datafile.open("duomenis/10k.txt");
						if (datafile.is_open()) {
							int rvid;
							int vid;
							float fvid;
							datafile << left << setw(14) << "Pavarde" << left << setw(20) << "Vardas" << "Galutinis(Vid.)" << endl;
							datafile << "---------------------------------------------" << endl;
							for (int i = 1; i < 10000; i++) {
								rvid = rand() % 100 + 1;
								vid = rand() % 10;
								fvid = (float)rvid / 100 + (float)vid;
								datafile << left << setw(14) << "Pavarde" + std::to_string(i) << left << setw(20) << "Vardas" + std::to_string(i) << std::setprecision(3) << fvid << endl;

							}
							datafile.close();
						}
						cout << "Failas su 10000 studentu sugeneruotas!" << endl;
					}

					if (nr == 3) {
						// FAILAS SU 100000 STUDENTU
						datafile.open("duomenis/100k.txt");
						if (datafile.is_open()) {
							int rvid;
							int vid;
							float fvid;
							datafile << left << setw(14) << "Pavarde" << left << setw(20) << "Vardas" << "Galutinis(Vid.)" << endl;
							datafile << "---------------------------------------------" << endl;
							for (int i = 1; i < 100000; i++) {
								rvid = rand() % 100 + 1;
								vid = rand() % 10;
								fvid = (float)rvid / 100 + (float)vid;
								datafile << left << setw(14) << "Pavarde" + std::to_string(i) << left << setw(20) << "Vardas" + std::to_string(i) << std::setprecision(3) << fvid << endl;

							}
							datafile.close();
						}
						cout << "Failas su 100000 studentu sugeneruotas!" << endl;
					}
					if (nr == 4) {
						// FAILAS SU 1000000 STUDENTU
						std::ofstream datafile;
						datafile.open("duomenis/1kk.txt");
						if (datafile.is_open()) {
							int rvid;
							int vid;
							float fvid;
							datafile << left << setw(14) << "Pavarde" << left << setw(20) << "Vardas" << "Galutinis(Vid.)" << endl;
							datafile << "---------------------------------------------" << endl;
							for (int i = 1; i < 1000000; i++) {
								rvid = rand() % 100 + 1;
								vid = rand() % 10;
								fvid = (float)rvid / 100 + (float)vid;
								datafile << left << setw(14) << "Pavarde" + std::to_string(i) << left << setw(20) << "Vardas" + std::to_string(i) << std::setprecision(3) << fvid << endl;

							}
							datafile.close();
						}
						cout << "Failas su 1000000 studentu sugeneruotas!" << endl;
					}
					if (nr == 5) {
						// FAILAS SU 10000000 STUDENTU
						datafile.open("duomenis/10kk.txt");
						if (datafile.is_open()) {
							int rvid;
							int vid;
							float fvid;
							datafile << left << setw(14) << "Pavarde" << left << setw(20) << "Vardas" << "Galutinis(Vid.)" << endl;
							datafile << "---------------------------------------------" << endl;
							for (int i = 1; i < 10000000; i++) {
								rvid = rand() % 100 + 1;
								vid = rand() % 10;
								fvid = (float)rvid / 100 + (float)vid;
								datafile << left << setw(14) << "Pavarde" + std::to_string(i) << left << setw(20) << "Vardas" + std::to_string(i) << std::setprecision(3) << fvid << endl;

							}
							datafile.close();
						}
						cout << "Failas su 10000000 studentu sugeneruotas!" << endl;
					}
				}
				system("CLS");
				possibility = menu();
			}
			while (possibility == 6) {
				int nr = 0;
				std::ofstream datafile;
				possibility = menuR();
			
			
			
				//system("CLS");
				//possibility = menu();
			}
			while (possibility == 7) { possibility = 0; }
		}
		catch (int ExceptionERR) {
			cout << "ERROR " << ExceptionERR << ": Menu option is invalid" << endl;
			system("pause");
			system("CLS");
			possibility = menu();

		}
	}
	return 0;
}
