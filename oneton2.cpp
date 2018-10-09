#include <iostream>
#include <vector>

using namespace std;

using VE = vector <int>;
int n;
VE perm, pos, num;

void print() {
	cout << '{';
	for (int i = 0; i < n - 1 ; ++i) cout << perm[i] + 1 << ',';
	cout << perm[n-1] + 1 << '}' << endl;
}

void f(int i, int s) {
	if (s == n - 1) {
		perm[i] = 0;
		print();
	}
	for (int j = 0; j < n; ++j) {
		if ( i != j) {
			if (num[j] == false and pos[j] == false) {	
				perm[i] = j;
				pos[i] = true;
				num[j]= true;
				f(j, s + 1);
				num[j] = false;
			}
		}
	}
}
		

int main() {
	cin >> n;
	perm = VE(n);
	pos = VE(n, false);
	num = VE(n, false);
	f(0, 0);
}
	
