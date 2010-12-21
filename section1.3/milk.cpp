/*
ID: jacob4
PROG: milk
LANG: C++
*/
#include <fstream>
#include <queue>

using namespace std;
struct Offer {
	int p;
	int a;
};
bool operator<(const Offer &a, const Offer &b) {
	return a.p > b.p;
}

int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	int n,m;
	fin >> n >> m;
	
	int price = 0;
	
	priority_queue<Offer> q;
	for(int i = 0; i < m; i++) {
		int p, a;
		fin >> p >> a;
		Offer o = {p,a};
		q.push(o);
	}
	while(n > 0 && !q.empty()) {
		Offer farm = q.top();
		if(farm.a < n) {
			n -= farm.a;
			price += farm.p * farm.a;
		} else {
			price += farm.p * n;
			break;
		}
		q.pop();
	}
	fout << price << endl;
	return 0;
}
