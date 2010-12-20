/*
ID: jacob4
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	char *a = new char[6],
			*b = new char[6];

	FILE *fin = fopen("ride.in", "r");
	fscanf(fin, "%s\n%s", a, b);
	fclose(fin);
	
	int prod_a = 1;
	int prod_b = 1;
	while(*a != '\0') {
		prod_a *= *a - 'A' + 1;
		a++;
	}
	while(*b != '\0') {
		prod_b *= *b - 'A' + 1;
		b++;
	}
	
	FILE *fout = fopen("ride.out", "w");
	fprintf(fout, "%s\n", (prod_a - prod_b) % 47 == 0 ? "GO" : "STAY");
	fclose(fout);
	return 0;
}

