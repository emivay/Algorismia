//Escribir todas las particiones de n palabras dadas en p conjuntos

#include <iostream>
#include <vector>
using namespace std;

using VE = vector<int>
using ME = vector<ME>
using VS = vector<string>


void escribir() {
	for (int i = 0; i < p; i++) {
		cout << "subset" << ' ' << i;
			for (int j = 0; j < n; j++) {
				cout << ',' << pal[j];
			}
		cout << endl;
	}
}
	

void f(int i, int j) {
	if (i == p) return escribir();
	
	if (j == n) return f(i + 1, 0);
	
	if (M[i][j]) return f(i, j + 1);
	
	if (j < n and not M[i][j]);
	M[i][j] = true;
	f(i, j + 1);
	M[i][j] = false;
}

int main() {
	cin >> n >> p;
	pal = VS(n);
	for (int i = 0; i < n; ++i) cin >> pal[i];	//leo palabras que me dan
	while (cin >> n >> p) {
		M = ME(n, VE(p, false));				//creo la matriz que guarda si la palabra se uso en un conjunto o no
	}
	f(0, 0);
}
