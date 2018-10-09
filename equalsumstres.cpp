#include <iostream>
#include <vector>
using namespace std;


using VE = vector<int>;


int n;
VE num;
VE triat;
int s;


void escriu() {
  for (int i = 0; i < n; ++i)
    if (triat[i]) cout << ' ' << num[i];
  cout << endl;
}


void f(int i, int sum) {
  if (i == n) {
    if (sum == s) escriu();
    return;
  }

  triat[i] = false;
  f(i + 1, sum);
  if (sum + num[i] <= s) {
	triat[i] = true;
	f(i + 1, sum + num[i]);
   }
}


int main() {
  cin >> s;
  cin >> n;
  num = VE(n);
  for (int i = 0; i < n; ++i) cin >> num[i];
  triat = VE(n);			//en este vector guardo si usé el número o no
  f(0, 0);
}
