/*
ID: jacob4
PROG: calfflac
LANG: C++
*/

#include <fstream>
#include <string>
#include <map>
#include <streambuf>

using namespace std;

int main() {
	ifstream fin("calfflac.in");
	ofstream fout("calfflac.out");
	
	string stripped = "", temp;
	string instring((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

	map<int, int> mapping;
	string::iterator it;
	int s = 0;
	for(it = instring.begin(); it < instring.end(); it++) {
		int v = int(*it);
		if((v >= 65 && v <= 90) || (v >= 97 && v <= 122)) {
			stripped += tolower(*it);
			mapping[s] = it - instring.begin();
			s++;
		}
	}

	int maxlen = 0, maxstart = 0;
	for(int i = 0; i < stripped.length(); i++) {
		// check outwards
		int roffset = 0, len = 1, j; 
		for(j = 0; j <= min(i,1000); j++) {
			if(j == 0) {
				if(stripped[i] == stripped[i+1]) {
					roffset = 1;
					len = 2;
				}
			} else {
				if(stripped[i-j] != stripped[i+j+roffset]) {
					break;
				}
				len += 2;
			}
		}
		j--;
		if(len > maxlen) {
			maxlen = len;
			maxstart = i-j;
			if(j > i) {
				fout << "wtf @ i:"<<i<< " < j:"<<j<<endl;
			}
		}
	}
	
	int fullstart = mapping[maxstart];
	int fulllen = mapping[maxstart+maxlen-1] - fullstart + 1;
//	fout << "mapping index: "<< maxstart << " and "<< maxstart+maxlen-1 << endl;
//	fout << "attempting access to offset " << fullstart << " length: " << fulllen << endl;
	fout << maxlen << endl << instring.substr(fullstart, fulllen) << endl;
	
	return 0;
}
