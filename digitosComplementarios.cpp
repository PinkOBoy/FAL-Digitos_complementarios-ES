/**
* @author PinkOBoy
*/
#include <iostream>
using namespace std;

/*COSTE DEL ALGORITMO
* 
*	T1(n) = c0			n = 0
*	T1(n) =	c1 * T(n-1)	n > 0
* 
* 
*	T2(n) = c0			n = 0
*	T2(n) = c1 * T(n-1) n > 0
* 
*	Desplegado
*	
*		...
* 
*	Postulado
* 
*	T1 n - k = 1 -> n - 1 = k
*	
*		kc1 + T1(n-k) = (n - 1)c1 + ... = O(n)
* 
*	T2 .... O(n)
*/

int complementario(int n) {
	if (n < 10)
		return 9 - n;
	else {
		int complementarioSinUnidades = complementario(n / 10);
		int complementarioConUnidades = 9 - n % 10;
		return complementarioSinUnidades * 10 + complementarioConUnidades;
	}
}

int inversoComplementario(int n, int m) {
	if (n / 10 == 0 && m == 0)
		return 9 - n;	
	if (n == 0)
		return m;
	else return inversoComplementario(n / 10, m * 10 + (9 - n % 10));
}

void resolver(int n) {
	cout << complementario(n) << ' ' << inversoComplementario(n, 0) << endl;
}

int main() {
	int c, n;
	cin >> c;

	while (c > 0) {
		cin >> n;
		resolver(n);
		--c;
	}

	return 0;
}