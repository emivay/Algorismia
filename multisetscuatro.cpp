//Dados n, inf, sup y t imprimir en pantalla todos los multisets de {1,...,n} de cardinal
// t en los que cada número tiene que aparecer entre inf y sup veces.

#include <iostream>
#include <vector>

using namespace std;
using VE = vector<int>;

int n, inf, sup, t;
VE c;

void escribir () {
	cout << '{' ;
	for (int i = 0; i < n; ++i) 
		for (int rep = 0; rep < c[i]; ++rep) cout << i + 1 << ' ' ;		//no se como sacar el espacio.
	cout << '}' << endl;	
	
}

void f(int i, int t) {
	
	if (i == n - 1) {
		c[i] = t ;
		return escribir ();
	}
	
	if (t < sup) {
		for (int j 
		
	for (int j = inf; j <= sup); ++j) {		//Con este for voy "abriendo" el árbol: en el f(i+1) uso el siguiente número mientras que cuando vuelvo a entrar a la iteración repito el mismo.
		c[i] = j;
		f(i + 1, t - j);
	}
}

int main () {
	cin >> n >> inf >> sup >> t;
	if (inf > sup) cout << "Error, inf no puede ser mas grande que sup";
	c = VE(n);		//en este vector voy a guardar la cantidad de veces que usé un número.
	f(0, t);
}

