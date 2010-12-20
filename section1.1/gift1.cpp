/*
ID: jacob4
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	int NP = 0, amount = 0, friends = 0;
	string names[10];

	fin >> NP;
	map<string, int> sums;
	for(int i = 0; i < NP; i++) {
		fin >> names[i];
		sums[names[i]] = 0;
	}
	for(int i = 0; i < NP; i++) {
		string name;
		fin >> name;
		fin >> amount >> friends;
		if (friends == 0) continue;
		
		int share = amount / friends;
		sums[name] -= share * friends;
		for(int x = 0; x < friends; x++) {
			fin >> name;
			sums[name] += share;
		}
	}
	for (int i = 0; i < NP; i++) {
		fout << names[i] << " " << sums[names[i]] << endl;
	}
	
	return 0;
}

