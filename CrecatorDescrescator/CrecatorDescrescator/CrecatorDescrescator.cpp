#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Citire(int v[], int& n) {

	cout << "Introduceti numarul de elemente din vector : ";

	for (int i = 0; i < n; i++) {

		cin >> v[i];
	}
}

void Afisare(int v[], int n) {

	for (int i = 0; i < n; i++) {

		cout << v[i] << " ";
	}
	cout << endl;
}

void Ordonare(int v[], int n) {


}