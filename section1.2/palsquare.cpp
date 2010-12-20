/*
ID: jacob4
PROG: palsquare
LANG: C++
*/
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

bool isPalindrome(string in) {
	return (in.length() <= 1) || ((in[0] == in[in.length()-1]) && isPalindrome(in.substr(1,in.length()-2)));
}

int main() {
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	char chars[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	int base;
	fin >> base;
	
	for(int i = 1; i <= 300; i++) {
		int square = i * i;
		string inBase = "";
		while(square >= base) {
			inBase = chars[square % base] + inBase;
			square = square / base;
		}
		inBase = chars[square % base] + inBase;
		if(isPalindrome(inBase)) {
			string iBaseB = "";
			int temp = i;
			while(temp >= base) {
				iBaseB = chars[temp % base] + iBaseB;
				temp = temp / base;
			}
			iBaseB = chars[temp % base] + iBaseB;
			fout << iBaseB << " " << inBase << endl;
		}
	}

	return 0;
}
