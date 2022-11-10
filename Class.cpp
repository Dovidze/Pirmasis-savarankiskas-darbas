#include "Class.h"

Student::Student() {
	this->vardas = "";
	this->pavarde = "";
	this->egzpaz = 1;
};

Student::Student(string vardas, string pavarde, vector<int>paz, int final) {
	this->vardas = vardas;
	this->pavarde = pavarde;
	this->paz = paz;
	this->egzpaz = final;
};

Student::~Student() {
	paz.clear();
}

Student::Student(const Student& p1) {
	this->vardas = p1.vardas;
	this->pavarde = p1.pavarde;
	this->paz = p1.paz;
	this->egzpaz = p1.egzpaz;
}

string Student::Getpavarde() {
	return this->pavarde;
}

vector<int> Student::Getpaz() {
	return this->paz;
}

double Student::Getegzpaz() {
	return this->egzpaz;
}

void Student::Deletepaz() {
	paz.clear();
}

void Student::PrintMediana() {
	double math = std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
	double fscore = (0.4 * math) + (0.6 * egzpaz);
	std::nth_element(paz.begin(), paz.begin() + paz.size() / 2, paz.end());
	cout << left << setw(15) << pavarde << left << setw(15) << vardas << std::setprecision(2) << fscore << "/" << "(" << paz[paz.size() / 2] << ")" << endl;
}

void Student::PrintFile() {
	double math = std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
	double fscore = (0.4 * math) + (0.6 * egzpaz);
	std::nth_element(paz.begin(), paz.begin() + paz.size() / 2, paz.end());
	cout << left << setw(15) << pavarde << left << setw(15) << vardas << std::setprecision(2) << fscore << "/" << std::setprecision(2) << "(" << math << ")" << "(" << paz[paz.size() / 2] << ")" << endl;

};

//(PERDENGIMAS CIN
std::istream& operator >>(std::istream& input, Student& x) {
	int nr;
	int sk = 1;
	char check;
	cout << "--------------------------------Naujas Studentas-----------------------" << endl;
	cout << "***********************************************************************" << endl;
	cout << "" << endl;
	cout << " Studento vardas : ";
	cin >> x.vardas;
	cout << " Studento pavarde : ";
	cin >> x.pavarde;
	cout << "" << endl;
	cout << "**********************************************************************" << endl;
	cout << "" << endl;
	cout << "Iveskite pazymius, noredami baigti pazymiu ivedima - irasykite 000 " << endl;
	cout << "Noredami jog automatiskai butu parinkti pazymiai, iveskite 111" << endl;
	while (true) {
		
		cin >> nr;
		check = sk;

		if (isalpha(nr)) {
			break;
		}
		if (nr == 000) {
			break;
		}

		if (nr == 111) { 
			cout << "Kiek pazymiu sukurti?" << endl;
			cin >> nr;
			for (int i = 1; i < nr; i++) { // generuoja random skaicius
				x.paz.push_back(rand() % 10 + 1);
			}
			x.egzpaz = rand() % 10 + 1;
			return	input;
		}
		
		if (nr > 10 || nr < 0) { // pazymys maziau negu 0 arba daugiau negu 10
			cout << "Ivedete neteisinga skaiciu, iveskite pazymi tap 0 ir 10 " << endl;
			continue;
		}
		cout << "Ivestas pazymys nr" << sk << endl;
		x.paz.push_back(nr);
		sk++;
	};
	cout << endl << "Iveskite Egzamino pazymi :" << endl;
	cin >> x.egzpaz;
	system("CLS");
	return input;
};

std::ostream& operator <<(std::ostream& output, const Student& x) { //(PERDENGIMAS COUT
	double vid = std::accumulate(x.paz.begin(), x.paz.end(), 0.0) / x.paz.size();
	double galutinis = (0.4 * vid) + (0.6 * x.egzpaz);
	cout << left << setw(15) << x.pavarde << left << setw(15) << x.vardas << std::setprecision(2) << galutinis << endl;
	return output;
};

int wordnum(string wordnume) {
	int countinger = 0;
	std::string word;
	std::stringstream strm(wordnume);

	while (strm >> word) {
		++countinger;
	};
	return countinger;
};