/*
ID: jacob4
PROG: crypt1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool digits[10] = {false};

bool isValid(int in, int maxlen) {
	int len = 0;
	while(in > 0) {
		if(!digits[in % 10]) return false;
		in /= 10;
		len++;
	}
	return len > 0 && len <= maxlen;
}

int main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	
	int solcount = 0;
	int digitCount;
	fin >> digitCount;
	
	for(int i = 0; i < digitCount; i++) {
		int v;
		fin >> v;
		digits[v] = true;
	}

	for(int a = 1; a < 10; a++) // disallow leading 0
	for(int b = 0; b < 10; b++)
	for(int c = 0; c < 10; c++)
	for(int d = 1; d < 10; d++) // disallow leading 0
	for(int e = 0; e < 10; e++) {
		int val1 = 100*a+10*b+c;
		int val2 = 10*d+e;
		if(isValid(val1, 3) && isValid(val2, 2) && 
			isValid(d*val1, 3) && isValid(e*val1, 3) &&
				isValid(val1*val2, 4)) solcount++;
	}
	fout << solcount << endl;
	
	return 0;
}
