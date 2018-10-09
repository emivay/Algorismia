#include <iostream>
#include <vector>
#include <string>

using namespace std;
using VE = vector<int>;
using VS = vector<string>;

VS species, inc;
VE usado, comb;

int n, m;

void print() {
	for (int j = 0; j < n; ++j) {
		cout << comb[j];
	}
	cout << endl;
}

bool incompatible (int a, int b) {
	string stra = "";
	stra.push_back(species[a]);
	stra.push_back(species[b]);
	string strb = "";
	strb.push_back(species[b]);
	strb.push_back(species[a]);
	for (int j = 0; j < m; ++j) {
		if (stra == inc[j]) return true;
		if (strb == inc[j]) return true;
	}
	return false;
}
		
	
}

void f(int i) {
	if (i == n) print();
	if (i == 0) {
		for (j = 0; j < n; ++j) {
			if (not usado[j]) {
				usado[j] = true;
				comb[i] = j;
				f(i + 1);
				usado[j] = false;
			}
		}
	}
	for (j = 0; j < n; ++j) {
		if (not usado[j] and not imcompatible(comb[i - 1], j)) {
			usado[j] = true;
			comb[i] = j;
			f(i + 1);
			usado[j] = false;
		}
	}
}



int main() {
	cin >> n;
	species = VS(n);
	for (int i = 0; i < n; ++i) cin >> species[i];
	cin >> m;
	inc = VS(m);
	for (int i = 0, i < m; ++i) cin >> inc[i];
	usado = VE(n, false);
	comb = VE(n);
	f(0);
}
	
	 

