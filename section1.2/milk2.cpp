/*
ID: jacob4
PROG: milk2
LANG: C++
*/
#include <fstream>
#include <utility>
#include <list>
using namespace std;

bool lss(pair< int, bool > &a, pair< int, bool > &b) {
	return (a.first < b.first || (a.first == b.first && a.second));
}

int main() {
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	
	int n, max_occ = 0, max_free = 0;
	fin >> n;
	
	list< pair< int, bool > > times;
	
	for(int i = 0; i < n; i++) {
		int from, to;
		fin >> from >> to;
		times.push_back(make_pair(from, true));
		times.push_back(make_pair(to, false));
	}
	times.sort(lss);
	int level = 0, st_occ = 0, st_free = 0;
	list< pair< int, bool > >::iterator it;
	for(it = times.begin(); it != times.end(); ++it) {
		if((*it).second) {
			if(level == 0) {
				if(st_free) max_free = max_free < ((*it).first - st_free) ? ((*it).first - st_free) : max_free;
				st_occ = (*it).first;
			}
			level++;
		} else {
			level--;
			if(level == 0) {
				max_occ = max_occ < ((*it).first - st_occ) ? ((*it).first - st_occ) : max_occ;
				st_free = (*it).first;
			}
		}
	}
	fout << max_occ << " " << max_free << endl;
	return 0;
}
