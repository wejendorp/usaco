/*
ID: jacob4
PROG: friday
LANG: C++
*/
#include <fstream>

using namespace std;

int main() {
	int days[7] = {0,0,0,0,0,0,0};
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	
	int n;
	fin >> n;
	
	int day = 0; /* saturday, sunday, monday. Offset by 13 days, start @ 13th */
	/* For each year */
	for(int i = 0; i < n; i++) {
		int leap = 0;
		if(i % 4 == 0 && (i % 100 != 0 || (i+1900) % 400 == 0)) leap = 1;
		/* For each month */
		for(int m = 0; m < 12; m++) {
			days[day] += 1;
			if(m == 1) {
				day = (day + months[m] + leap) % 7;
			} else {
				day = (day + months[m]) % 7;
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		fout << days[i] << " ";
	}
	fout << days[6] << endl;
	
	return 0;
}
