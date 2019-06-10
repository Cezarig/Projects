#include <iostream>
#include <algorithm>

using std::cout;

int ElemMin(int v[], int i, int j) {
	
	if (i == j) {
		return i;
	}

	int k = ElemMin(v, i + 1, j);

	return (v[i] > v[k]) ? k : i;
}

void RecursiveSelection(int v[], int n, int start = 0) {

	if (start == n) {
		return;
	}

	int k = ElemMin(v, start, n - 1);

	if (k != start) {

		std::swap(v[k], v[start]);
	}
	
	RecursiveSelection(v, n, start + 1);
}

void main() {

	int v[] = { 3, 1, 5, 2, 7, 0 };

	RecursiveSelection(v, 6);
	
	for (int i = 0; i < 6; i++) {

		cout << v[i] << " ";
	}
}