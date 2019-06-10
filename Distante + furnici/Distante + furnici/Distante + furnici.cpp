#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 

char orase[50][50] = {
	"Oradea",//0
	"Zerind",
	"Arad",
	"Timisoara",
	"Lugoj",
	"Mehadia",
	"Drobeta",
	"Sibiu",
	"RamniculValcea",
	"Craiova",
	"Fagaras",
	"Pitesti",
	"Bucuresti",
	"Giurgiu",
	"Urziceni",
	"Hirsova",
	"Eforie",
	"Vaslui",
	"Iasi",
	"Neamt" //19
};


int start = 0;
int stop = 0;
float cale[21][21]{};
struct lista1 {
	int nr = 0;
	int lista[100]{};
};
lista1 listaTabu[300];
int nrfurnici = 100;

bool verificare(int furnica, int i) {

	for (int j = 0; j < listaTabu[furnica].nr; j++) {

		if (listaTabu[furnica].lista[j] == i) {

			return false;
		}
	}
	return true;
}

void print() {
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {

			std::cout << cale[i][j] << "  ";

		}
		std::cout << std::endl;
	}
}

void depunemFeromon() {
	for (int furnica = 0; furnica <= nrfurnici; furnica++) {
		float suma = 0;
		for (int i = 0; i < listaTabu[furnica].nr; i++) {
			suma += cale[listaTabu[furnica].lista[i]][listaTabu[furnica].lista[i + 1]];
		}
		for (int i = 0; i < listaTabu[furnica].nr; i++) {
			cale[listaTabu[furnica].lista[i]][listaTabu[furnica].lista[i + 1]] = cale[listaTabu[furnica].lista[i]][listaTabu[furnica].lista[i + 1]] / suma;
			cale[listaTabu[furnica].lista[i + 1]][listaTabu[furnica].lista[i]] = cale[listaTabu[furnica].lista[i]][listaTabu[furnica].lista[i + 1]];
		}
	}
}


void evaporareFeromon() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (cale[i][j] != 0)
				cale[i][j] = cale[i][j] * 0.99;
		}
	}
}

void curatareLista() {
	for (int i = 0; i <= nrfurnici; i++) {
		for (int j = 0; j < 100; j++) {
			listaTabu[i].lista[j] = 0;
		}
		listaTabu[i].nr = 0;
	}
}

void afisareCale() {
	bool solutie = false;
	float cale1[400]{};
	int cale2[400]{};
	cale2[0] = start;
	int k1 = 0;
	int k2 = 0;
	while (solutie == false) {
		k1++;
		int indice = 0;
		for (int i = 0; i < 20; i++) {
			if (cale[cale2[k2]][i] != 0 && cale1[k1] < cale[cale2[k2]][i]) {
				bool sol = true;
				for (int j = 0; j < k2; j++) {
					if (cale2[j] == i) {
						sol = false;
					}
				}
				if (sol == true || k2 == 0) {
					cale1[k1] = cale[cale2[k2]][i];
					indice = i;
				}
			}
		}
		if (cale1[k1] == 0) {
			k2--;
			cale[cale2[k2]][cale2[k2 + 1]] = 0;
			cale2[k2 + 1] = 0;
			cale1[k1] = 0;
			k1--;
		}
		else {
			k2++;
			cale2[k2] = indice;
			if (cale2[k2] == stop)
				solutie = true;
		}
	}
	std::cout << "\n-------------------------------------------------Calea este--------------------------------------------------\n\n";
	for (int i = 0; i <= k2; i++) {
		std::cout << orase[cale2[i]];
		if (i != k2)
			std::cout << " -> ";
	}
}

void cautare() {
	int iteratii = 0;

	while (iteratii != 500) {
		iteratii++;
		depunemFeromon();
		curatareLista();
		for (int furnica = 0; furnica <= nrfurnici; furnica++) {
			bool solutie = false;
			while (solutie == false) {
				int nuexista = 0;
				int nRezultat = -1;
				struct rez {
					int indice = 0;
					float distanta = 0;
				};
				rez rezultat[10];
				float suma = 0;
				for (int i = 0; i < 20; i++) {
					if (i == 0)
						listaTabu[furnica].lista[i] = start;
					if (verificare(furnica, i) == true && cale[listaTabu[furnica].lista[listaTabu[furnica].nr]][i] != 0) {
						nRezultat++;
						nuexista++;
						rezultat[nRezultat].distanta = 1 / cale[listaTabu[furnica].lista[listaTabu[furnica].nr]][i];
						suma += rezultat[nRezultat].distanta;
						rezultat[nRezultat].indice = i;
					}
				}
				if (nuexista == 0) {
					for (int l = 0; l < 100; l++)
						listaTabu[furnica].lista[l] = 0;
					listaTabu[furnica].nr = 0;
				}
				if (nuexista != 0) {
					int k = -1;

					for (int i = 0; i < 20; i++) {
						if (verificare(furnica, i) == true && cale[listaTabu[furnica].lista[listaTabu[furnica].nr]][i] != 0) {
							k++;
							rezultat[k].distanta = rezultat[k].distanta / suma;
							if (k != 0) {
								rezultat[k].distanta += rezultat[k - 1].distanta;
							}
						}
					}

					int temp = 0;
					float r = rand() % 10;
					if (r != 0)
						r = 1 / r;
					else
						r = 0;

					for (int i = 0; i <= nRezultat; i++) {
						if (r <= rezultat[i].distanta && r >= temp) {
							listaTabu[furnica].nr++;
							listaTabu[furnica].lista[listaTabu[furnica].nr] = rezultat[i].indice;

							if (listaTabu[furnica].lista[listaTabu[furnica].nr] == stop)
								solutie = true;
							break;
						}
						temp = rezultat[i].distanta;
					}
				}

			}
		}
		evaporareFeromon();
	}
	print();
}


void main() {
	cale[0][1] = 71; // Oradea-Zerind
	cale[1][0] = 71;

	cale[0][7] = 151; // Oradea-Sibiu
	cale[7][0] = 151;

	cale[1][2] = 75; // Zerind-Arad
	cale[2][1] = 75;

	cale[2][7] = 140; // Arad-Sibiu
	cale[7][2] = 140;

	cale[2][3] = 118; // Arad-Timisoara
	cale[3][2] = 118;

	cale[3][4] = 111; // Timisoara-Lugoj
	cale[4][3] = 111;

	cale[4][5] = 70; // Lugoj-Mehedia
	cale[5][4] = 70;

	cale[5][6] = 75; // Mehedia-Drobeta
	cale[6][5] = 75;

	cale[6][9] = 120; // Drobeta-Craiova
	cale[9][6] = 120;

	cale[9][11] = 138;// Craiova-Pitesti
	cale[11][9] = 138;

	cale[8][9] = 146; // RamniculValcea-Craiova
	cale[9][8] = 146;

	cale[7][8] = 80; // Sibiu-RamniculValcea
	cale[8][7] = 80;

	cale[7][10] = 99;// Sibiu-Fagaras
	cale[10][7] = 99;

	cale[8][11] = 97;// RamniculValcea-Pitesti
	cale[11][8] = 97;

	cale[10][12] = 211;// Fagaras-Bucuresti
	cale[12][10] = 211;

	cale[11][12] = 101;// Pitesti-Bucuresti
	cale[12][11] = 101;

	cale[12][13] = 90;// Bucuresti-Giurgiu
	cale[13][12] = 90;

	cale[12][14] = 85;// Bucuresti-Urziceni
	cale[14][12] = 85;

	cale[14][15] = 98;// Urziceni-Hirsova
	cale[15][14] = 98;

	cale[15][16] = 86;// Hirsova-Eforie
	cale[16][15] = 86;

	cale[14][17] = 142;// Urziceni-Vaslui
	cale[17][14] = 142;

	cale[17][18] = 92;// Vaslui-Iasi
	cale[18][17] = 92;

	cale[18][19] = 87;// Iasi-Neamt
	cale[19][18] = 87;



	print();
	std::cout << std::endl;
	for (int i = 0; i < 20; i++) {
		std::cout << i << "->" << orase[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Start:";
	std::cin >> start;
	std::cout << "Stop:";
	std::cin >> stop;
	std::cout << std::endl;
	cautare();
	afisareCale();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	system("pause");
}