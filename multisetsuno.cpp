//Dado n y r, escribir todos los subconjuntos de {1,...,n} en los que se puede repetir hasta r veces cada número. Puede variar el tamaño.
#include <iostream>
#include <vector>

using namespace std;
using VE = vector<int>;

int n, r;
VE c;

void escribir () {
	cout << '{' ;
	for (int i = 0; i < n; ++i) 
		for (int rep = 0; rep < c[i]; ++rep) cout << i + 1 << ' ' ;		//no sé cómo evitar el espacio inicial/final y me vuelve loca.
	cout << '}' << endl;	
	
}
	


void f(int i) {
	if (i == n) return escribir ();
	
	for (int j = 0; j <= r; ++j) {		//Con este for voy "abriendo" el árbol: en el f(i+1) uso el siguiente número mientras que cuando vuelvo a entrar a la iteración repito el mismo.
		c[i] = j;
		f(i + 1);
	}
}

int main () {
	cin >> n >> r;
	c = VE(n);		//en este vector voy a guardar la cantidad de veces que usé un número.
	f(0);
}

