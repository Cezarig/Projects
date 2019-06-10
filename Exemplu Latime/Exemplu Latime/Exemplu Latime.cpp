#include <iostream>

using std::cin;
using std::cout;
using std::endl;

enum {

	A=0,
	B,
	C,
	D,
	E
};

char const* nume[5] = { "A", "B", "C", "D", "E" };

int main()
{
	int a[5][5];

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			a[i][j] = 0;
		}
	}

	a[A][B] = 15;
	a[B][A] = 15;
	a[A][C] = 10;
	a[C][A] = 10;
	a[A][E] = 25;
	a[E][A] = 25;
	a[B][C] = 20;
	a[C][B] = 20;
	a[B][D] = 30;
	a[D][B] = 30;
	a[C][D] = 40;
	a[D][C] = 40;
	a[D][E] = 30;
	a[E][D] = 30;

	int parinte[5], nod, nrNoduri = 0, start, sfarsit, noduri[5], vizitat[5], gasit = 0;

	cout << "Dati nodul start : ";
	cin >> start;

	cout << "Dati nodul sfarsit : ";
	cin >> sfarsit;

	for (int i = 0; i < 5; i++) {

		vizitat[i] = 0;
	}

	noduri[nrNoduri++] = start;
	vizitat[start] = 1;

	while ((gasit == 0) && (nrNoduri != 0)) {

		nod = noduri[0];

		for (int i = 0; i < nrNoduri - 1; i++) {

			noduri[i] = noduri[i + 1];
		}
		nrNoduri--;

		if (nod == sfarsit) {

			gasit = 1;
		}
		else {

			for (int i = 0; i < 5; i++) {

				if (a[nod][i] != 0 && viz[i] == 0) {

					noduri[nrNoduri++] = i;
					viz[i] = 1;
					parinte[i] = nod;
				}
			}
		}
	}
}

