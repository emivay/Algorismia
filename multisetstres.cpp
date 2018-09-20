//Dado n y t escribir todos los subconjuntos de {1,...,n} de cardinal t que se pueden escribir. Se pueden repetir números.

#include <iostream>
#include <vector>

using namespace std;
using VE = vector<int>;

int n, t;
VE c;

void escribir () {
	cout << '{' ;
	for (int i = 0; i < n; ++i) 
		for (int rep = 0; rep < c[i]; ++rep) cout << i + 1 << ' ' ;		//no se como sacar el espacio.
	cout << '}' << endl;	
	
}
	


void f(int i, int t) {
	if (i == n - 1) {
        c[i] = t;
        return escribir ();
	}
	for (int j = 0; j <= t; ++j) {		//Con este for voy "abriendo" el árbol: en el f(i+1) uso el siguiente número mientras que cuando vuelvo a entrar a la iteración repito el mismo.
		c[i] = j;
		f(i + 1, t - j);
	}
}

int main () {
	cin >> n >> t;
	c = VE(n);		//en este vector voy a guardar la cantidad de veces que usé un número.
	f(0, t);
}

