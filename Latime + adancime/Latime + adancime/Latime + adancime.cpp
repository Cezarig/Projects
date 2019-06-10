#include <iostream>

using std::cin;
using std::cout;
using std::endl;

enum Orase {

	Arad = 0,
	Zerind,
	Oradea,
	Timisoara,
	Lugoj,
	Mehedia,
	Dobreta,
	Craiova,
	Rimnicu_Valcea,
	Sibiu,
	Fagaras,
	Pitesti,
	Bucuresti,
	Giurgiu,
	Urziceni,
	Hirsova,
	Eforie,
	Vaslui,
	Iasi,
	Neamt
};

 char const* nume[20] = { "Arad", "Zerind", "Oradea", "Timisoara", "Lugoj", "Mehedia", "Dobreta", "Craiova", "Rimnicu Valcea", "Sibiu", "Fagaras", "Pitesti", "Bucuresti", "Giurgiu", "Urziceni", "Hirsova", "Eforie", "Vaslui", "Iasi", "Neamt" };


void ParcurgereLatime(int a[20][20], int orase, int start1, int stop1) {

	int viz[20], nod;
	int start = start1, stop = stop1;
	int noduri[20], nrNoduri = 0;
	int parinte[20]; // parinte[i] = j inseamna ca la i am ajuns din j
	int gasit = 0; // nu am gasit solutia

	int Distanta = 0;

	for (int i = 0; i < 20; i++) {

		viz[i] = 0;
	}

	noduri[nrNoduri++] = start;
	viz[start] = 1;
	int ok = 0;
	while (gasit == 0 && nrNoduri != 0) {

		int nod = noduri[0];
		//                cout << nume[nod] << " ";

				//        for(int i=0; i<nrNoduri; i++){
				//
				//            cout << nume[noduri[i]] << "    ";
				//        }

		for (int i = 0; i < nrNoduri - 1; i++) {

			noduri[i] = noduri[i + 1];
		}
		nrNoduri--;
		if (nod == stop) {

			gasit = 1;
		}
		else {

			for (int i = 0; i < 20; i++) {

				if (a[nod][i] != 0 && viz[i] == 0) {

					if (ok >= 1)

					{
						Distanta += a[nod][i];
					}
					ok++;
					noduri[nrNoduri++] = i;
					viz[i] = 1;
					parinte[i] = nod;
				}
			}
		}
	}

	int parintiStop[20], k = 0, altStop = stop;
	parintiStop[k++] = stop;

	while (altStop != start) {

		altStop = parinte[altStop];
		parintiStop[k++] = altStop;
	}

	cout << "Cautare in latime de la " << nume[start] << " la " << nume[stop] << " este : " << endl;

	for (int i = k - 1; i >= 0; i--) {

		cout << nume[parintiStop[i]] << " ";
	}

	cout << "Distanta este : " << Distanta;

}

void ParcurgereAdancime(int a[20][20], int orase, int start1, int stop1) {

	int viz[20], nod;
	int start = start1, stop = stop1;
	int noduri[20], nrNoduri = 0;
	int parinte[20]; // parinte[i] = j inseamna ca la i am ajuns din j
	int gasit = 0; // nu am gasit solutia

	int Distanta = 0;

	for (int i = 0; i < 20; i++) {

		viz[i] = 0;
	}

	noduri[nrNoduri++] = start;
	viz[start] = 1;



	while (gasit == 0 && nrNoduri != 0) {

		int nod = noduri[0];
		//                cout << nume[nod] << " ";

				//        for(int i=0; i<nrNoduri; i++){
				//
				//            cout << nume[noduri[i]] << "    ";
				//        }

		for (int i = 0; i < nrNoduri - 1; i++) {

			noduri[i] = noduri[i + 1];
		}
		nrNoduri--;
		if (nod == stop) {

			gasit = 1;
		}
		else {

			for (int i = 0; i < 20; i++) {

				if (a[nod][i] != 0 && viz[i] == 0) {

					Distanta += a[nod][i];

					for (int i = nrNoduri; i > 0; i--) {

						noduri[i] = noduri[i - 1];
					}

					noduri[0] = i;
					nrNoduri++;
					viz[i] = 1;
					parinte[i] = nod;
				}
			}
		}
	}

	int parintiStop[20], k = 0, altStop = stop;
	parintiStop[k++] = stop;

	while (altStop != start) {

		altStop = parinte[altStop];
		parintiStop[k++] = altStop;
	}

	cout << "Cautare in adancime de la " << nume[start] << " la " << nume[stop] << " este : " << endl;

	for (int i = k - 1; i >= 0; i--) {

		cout << nume[parintiStop[i]] << " ";
	}

	cout << "Distanta este : " << Distanta;


}

int main() {

	int a[20][20];

	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {

			a[i][j] = 0;
		}
	}

	a[Oradea][Zerind] = 71;
	a[Zerind][Oradea] = 71;
	a[Oradea][Sibiu] = 151;
	a[Sibiu][Oradea] = 151;
	a[Zerind][Arad] = 75;
	a[Arad][Zerind] = 75;
	a[Arad][Timisoara] = 118;
	a[Arad][Sibiu] = 140;
	a[Sibiu][Arad] = 140;
	a[Timisoara][Arad] = 118;
	a[Timisoara][Lugoj] = 111;
	a[Lugoj][Timisoara] = 111;
	a[Lugoj][Mehedia] = 70;
	a[Mehedia][Lugoj] = 70;
	a[Mehedia][Dobreta] = 75;
	a[Dobreta][Mehedia] = 75;
	a[Dobreta][Craiova] = 120;
	a[Craiova][Dobreta] = 120;
	a[Craiova][Pitesti] = 133;
	a[Pitesti][Craiova] = 133;
	a[Craiova][Rimnicu_Valcea] = 140;
	a[Rimnicu_Valcea][Craiova] = 140;
	a[Sibiu][Rimnicu_Valcea] = 80;
	a[Rimnicu_Valcea][Sibiu] = 80;
	a[Sibiu][Fagaras] = 99;
	a[Fagaras][Sibiu] = 99;
	a[Pitesti][Bucuresti] = 101;
	a[Bucuresti][Pitesti] = 101;
	a[Fagaras][Bucuresti] = 211;
	a[Bucuresti][Fagaras] = 211;
	a[Bucuresti][Giurgiu] = 90;
	a[Giurgiu][Bucuresti] = 90;
	a[Bucuresti][Urziceni] = 85;
	a[Urziceni][Bucuresti] = 85;
	a[Urziceni][Hirsova] = 98;
	a[Hirsova][Urziceni] = 98;
	a[Hirsova][Eforie] = 80;
	a[Eforie][Hirsova] = 80;
	a[Urziceni][Vaslui] = 142;
	a[Vaslui][Urziceni] = 142;
	a[Vaslui][Iasi] = 92;
	a[Iasi][Vaslui] = 92;
	a[Iasi][Neamt] = 87;
	a[Neamt][Iasi] = 87;

	//    for (int i = 0;i < 20;i++)
	//     {
	//     if (a[2][i] != 0)
	//     {
	//     cout << "Distanta dintre " << nume[2] << " si " << nume[i] << " este : " << a[2][i] << endl;
	//     }
	//     }


	ParcurgereLatime(a, 20, 4, 0);

	cout << endl;
	cout << endl;

	ParcurgereAdancime(a, 20, 4, 0);

	return 0;
}