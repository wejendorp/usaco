/*
ID: jacob4
PROG: transform
LANG: C++
*/
#include <fstream>
#define IFILE "transform.in"
#define OFILE "transform.out"
using namespace std;

int main() {
	ifstream fin(IFILE);
	ofstream fout(OFILE);

	int n;
	fin >> n;

	char a[n][n];
	char b[n][n];
	char c[n][n];
	
	for(int i = 0; i < n; i++) {
		fin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		fin >> b[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			c[i][j] = a[i][n-j-1];
		}
	}


	/* The simple options */
	bool check[6] = {true, true, true, true, true, true};
	bool comb[3] = {true, true, true};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			/* 90 degree rotation */
			if(a[n-j-1][i] != b[i][j]) {
				check[0] = false;
			}
			/* 180 */
			if(a[i][j] != b[n-i-1][n-j-1]) {
				check[1] = false;
			}
			/* 270 */
			if(a[i][j] != b[n-j-1][i]) {
				check[2] = false;
			}
			/* reflect */
			if(b[i][j] != c[i][j]) {
				check[3] = false;
			}
			
			comb[0] = comb[0] && (c[n-j-1][i] == b[i][j]);
			comb[1] = comb[1] && (c[i][j] == b[n-i-1][n-j-1]);
			comb[2] = comb[2] && (c[i][j] == b[n-j-1][i]);
			check[4] = comb[0] || comb[1] || comb[2];
			/* unchanged */
			if(a[i][j] != b[i][j]) {
				check[5] = false;
			}
		}
	}
	/* print out */
	for(int i = 0; i < 6; i++) {
		if(check[i]) {
			fout << (i+1) << endl;
			return 0;
		}
	}
	/* invalid */
	fout << 7 << endl;
	return 0;
}
