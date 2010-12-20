/*
ID: jacob4
PROG: beads
LANG: C++
*/
#include <fstream>

using namespace std;

int main() {
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	
	int n;
	fin >> n;
	
	char *beads = new char[n+1];
	fin >> beads;
	
	char cur;
	int max = 0;
	/* start from */
	for(int i = 0; i < n; i++) {
		/* BRB or RBR */
		bool broke = false;
		int c = 1;
		cur = beads[i];
		while(c < n) {
			if(cur == 'w') {
				cur = beads[(i+c)%n];
			} else {
				if(beads[(i+c)%n] != 'w' && beads[(i+c)%n] != cur) {
					if(broke) break;
					broke = true;
					cur = beads[(i+c)%n];
				}
			}
			c++;
		}
		max = c > max ? c : max;
	}
	fout << max << endl;
	
	return 0;
}
