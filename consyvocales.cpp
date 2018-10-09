#include <iostream>
#include <vector>
using namespace std;

using VS = vector<char>;
using VB = vector<bool>;

VS C, V, palabra;
VB Vu, Cu;

int n, i;


void print() {
	for (int i = 0; i < 2*n; ++i) cout << palabra[i];
	cout << endl;
}



void f(int i) {
	if (i == 2*n) print();
	for (int j = 0; j < n; ++j) {
		if (i%2 == 0 and not Cu[j]) {		//la variable i me dice qué posición de mi vector estoy completando
			palabra[i] = C[j];				//la variable j del ciclo me hace rotar todas las posibilidades de consonantes o vocales
			Cu[j] = true;					//por eso las pongo y las saco
			f(i + 1);
			Cu[j] = false; 
		}
		if (i%2 == 1 and not Vu[j]) {
			palabra[i] = V[j];
			Vu[j] = true;
			f(i + 1);
			Vu[j] = false;
		}
			
	}
	
} 


int main() {
	cin >> n;
	C = VS(n);
	V = VS(n);
	for (int i = 0; i < n; i++) cin >> C[i];		//codifico el problema
	for (int i = 0; i < n; i++) cin >> V[i]; 
	Cu = VB(n, false);
	Vu = VB(n, false);
	palabra = VS(2*n);
	f(0);
}	
	
	

		
