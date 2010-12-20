/*
ID: jacob4
PROG: dualpal
LANG: C++
*/
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

char chars[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

bool isPalindrome(string in) {
	return (in.length() <= 1) || ((in[0] == in[in.length()-1]) && isPalindrome(in.substr(1,in.length()-2)));
}

string intToBase(int in, int base) {
		string inBase = "";
		while(in >= base) {
			inBase = chars[in % base] + inBase;
			in = in / base;
		}
		return chars[in % base] + inBase;
}

int main() {
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int n, s;
	fin >> n >> s;
	
	for(s++; n > 0; s++) {
		bool match = false;
		for(int base = 2; base <= 10; base++) {
			if(isPalindrome(intToBase(s, base))) {
				if(match) {
					fout << s << endl;
					n--;
					break;
				}
				match = true;
			}
		}
	}
	return 0;
}
