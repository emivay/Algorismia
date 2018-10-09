//Sebastian's toy friends

#include <iostream>
#include <vector>

using namespace std;
using VE = vector<int>;
using VS = vector<char>;
VE Hu, Bu, Lu, B, T;
VS H, L;

int n;

void f(int p1, int p2, int p3, int n) {
	if (p1 == 2) return print();
	if (p1 == 0) {
		for (int j = 0; j < n; ++j) {
			T[p1] = j;
			Hu[j] = true;		//esto es necesario?
			f(1, 1, 0, n);
			Hu[j] = false;
		}
	}
	if (p2 == 1) {
		for (int j = 0; j < n; ++j) {
			T[p2] = j;
			Bu[j] = true;		//esto es necesario?
			f(1, 2, 2, n);
			Bu[j] = false;
		}
	}
	if (p3 == 2) {
		for (int j = 0; j < n; ++j) {
			T[p3] = j;
			Lu[j] = true;		//esto es necesario?
			f(2, 1, 2, n);
			Lu[j] = false;
		}
	}
}
		
	

int main () {
	while (cin >> n) {
		if (n == 0) cout << endl;
		T = VE(3);
		f(0, 0, 0, n);
