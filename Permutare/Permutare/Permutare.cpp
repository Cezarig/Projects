#include <iostream>
#include <vector> 

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void Afisare(vector<bool> v) {

	for (auto i = v.begin(); i != v.end(); i++) {
		cout << *i;
	}
	cout << endl;
}

void main() {

	int n;
	vector<bool> v;

	cout << "Introduceti numarul de elemente al combinarilor : ";
	cin >> n;

	for (int i = 0; i < n; i++) {

		v.push_back(0);
	}

	for (int i = 0; i < v.size(); i += 2) {

		for (int j = v.size() - 1; j > i; j--) {

			v[j] = 1;
			Afisare(v);
			v[j] = 0;
		}
		v[i] = 1;
		Afisare(v);
	}
	
}