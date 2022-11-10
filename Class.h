#pragma once
#include "Header.h"

class Student {
private:
	string pavarde;
	vector<int> paz;
	int egzpaz;
public:
	string vardas;
	Student();
	Student(string, string, vector<int>, int);
	Student(const Student& p1);
	~Student();
	string Getpavarde();
	vector<int> Getpaz();
	double Getegzpaz();
	void Deletepaz();
	void PrintMediana();
	void PrintFile();
	friend std::istream& operator >>(std::istream& input, Student& x);
	friend std::ostream& operator <<(std::ostream& output, const Student& x);
};

int wordnum(string);
