/*
ID: jacob4
PROG: barn1
LANG: C++
*/
#include <fstream>

using namespace std;

int main() {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int m,s,c;
	fin >> m >> s >> c;

	int stalls[s];
	for(int i = 0; i < s; i++) {
		stalls[i] = 0;
	}
	int l, fst = s, lst = 0;
	for(int i = 0; i < c; i++) {
		fin >> l;
		stalls[l] = 1;
		fst = l < fst ? l : fst;
		lst = l > lst ? l : lst;
	}
	
	
	int covered = lst - fst+1;
	//fout << covered << endl;
	// Create a gap for m-1
	for(int i = 0; i < m-1; i++) {
		// find greatest gap
		int maxGap = 0, maxStartAt = 0,
				gap = 0, startAt = 0;
		for(int j = fst; j <= lst; j++) {
			if(stalls[j] <= 0) {
				if(gap == 0) startAt = j;
				gap++;
			} else {
				if(gap > maxGap && stalls[startAt] != -1) {
					maxGap = gap;
					maxStartAt = startAt;
				}
				gap = 0;
			}
		}
		// and split the board at position "startAt"
		covered -= maxGap;
		stalls[maxStartAt] = -1;
	}
	fout << covered << endl;
	return 0;
}
