/*
ID: jacob4
PROG: namenum
LANG: C++
*/
#include <fstream>
#include <list>
#include <stdlib.h>
#define IFILE "namenum.in"
#define OFILE "namenum.out"
using namespace std;

const string keys[8] = {"ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
int digit = 0;
int n = 0;

bool pressDigit(string s) {
	return (s.length() <= n || (s[n] != keys[digit-2][0] && s[n] != keys[digit-2][1] && s[n] != keys[digit-2][2]));
}

int main() {
	ifstream fin(IFILE);
	ifstream namefile("dict.txt");
	ofstream fout(OFILE);
	
	string brand;
	fin >> brand;

	list<string> names;
	int i = 0;
	while(!namefile.eof()) {
		string name;
		namefile >> name;
		names.push_back(name);
		i++;
	}
	for(int j=0; j < brand.length(); j++) {
		char temp = brand[j];
		digit = atoi(&temp);
		names.remove_if(pressDigit);
		n++;
	}
	if(!names.empty()) {
		list<string>::iterator it;
		for(it = names.begin(); it != names.end(); ++it) {
			if((*it).length() == brand.length()) {
				fout << (*it) << endl;
			}
		}
	} else {
		fout << "NONE" << endl;
	}
	return 0;
}
