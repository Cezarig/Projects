#include <iostream>
#include <time.h>

using std::cout;
using std::cin;

int RandomNumber(int v[], int n) {

	srand(time(NULL));

	int x;
	x = rand() % n;
	
	return v[x];
}

void EliminareNumar(int v[], int &n, int number) {
	int ok = 1;

	for (int i = 0; i < n && ok; i++) {

		if (v[i] == number) {

			for (int j = i; j < n; j++) {

				v[j] = v[j + 1];
			}
			ok = 0;
		}
	}
	n--;
}

int main() {

	int n, number = 0;
	int v[15];
	cin >> n;

	for (int i = 0; i < n; i++) {
		v[i] = i;
	}

	while (n != 0) {

		number = RandomNumber(v, n);
		cout << number << " ";
		EliminareNumar(v, n, number);
	}
}
