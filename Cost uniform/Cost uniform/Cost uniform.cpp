#include <iostream>
#include <conio.h>
//							0			1					2			3
const char* nume[21] = { "Satu Mare", "Baia Mare", "Cluj Napoca", "Bistrita",
// 4		 5			6			7
"Suceava", "Iasi", "Piatra Neamt", "Braila",
// 8		  9				10		   11            
"Tulcea", "Constanta", "Bucuresti", "Pitesti",
// 12		  13			14		 15
"Craiova", "Timisoara", "Arad", "Oradea",
// 16			17			18		    19	
"Targu Mures", "Sibiu", "Alba Iulia", "Brasov"};

int n = 20;
int a[20][20];
int h[20] = { 366, 0, 160, 242, 161, 176, 77, 151, 226, 244, 241, 234, 380, 10, 193, 253, 329, 80, 199, 374 }; // vector euristica

int main() {
	a[0][1] = 76;
	a[1][0] = 76;
	a[0][15] = 141;
	a[15][0] = 141;

	a[1][2] = 148;
	a[2][1] = 148;

	a[2][3] = 80;
	a[3][2] = 80;
	a[2][15] = 152;
	a[15][2] = 152;
	a[2][14] = 187;
	a[14][2] = 187;
	a[2][18] = 78;
	a[18][2] = 78;
	a[2][16] = 78;
	a[16][2] = 78;

	a[3][16] = 66;
	a[16][3] = 66;
	a[3][4] = 143;
	a[4][3] = 143;

	a[4][5] = 140;
	a[5][4] = 140;

	a[5][6] = 96;
	a[6][5] = 96;

	a[6][7] = 222;
	a[7][6] = 222;
	a[6][10] = 278;
	a[10][6] = 278;
	a[6][19] = 154;
	a[19][6] = 154;

	a[7][8] = 91;
	a[8][7] = 91;
	a[7][10] = 174;
	a[10][7] = 174;

	a[8][9] = 125;
	a[9][8] = 125;
	
	a[9][10] = 224;
	a[10][9] = 224;

	a[10][19] = 141;
	a[19][10] = 141;
	a[10][11] = 118;
	a[11][10] = 118;

	a[11][19] = 105;
	a[19][11] = 105;

	a[12][18] = 195;
	a[18][12] = 195;
	a[12][13] = 340;
	a[13][12] = 340;

	a[13][14] = 54;
	a[14][13] = 54;
	a[13][18] = 184;
	a[18][13] = 184;

	a[14][15] = 118;
	a[15][14] = 118;

	a[16][17] = 79;
	a[17][16] = 79;
	a[16][19] = 128;
	a[19][16] = 128;

	a[17][18] = 54;
	a[18][17] = 54;
	a[17][19] = 115;
	a[19][17] = 115;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i][j] != 0) {
				a[j][i] = a[i][j];
			}
		}
	}

	/* int ind; //indicele orasului

	std::cout << "Introduceti indicele orasului caruia sa-i afisam vecinii: ";
	std::cin >> ind;

	std::cout << "Vecinii orasului " << nume[ind] << " sunt: ";
	for (int i = 0; i < n; i++) {
	if (a[ind][i] == 1) {
	std::cout << nume[i] << " ";
	}
	}
	*/

	int noduri[20]; // orase vizitate
	int nrNoduri = 0; // contor lista noduri
	int vizitat[20]; // orasul a fost vizitat sau nu 
	int orasStart = 15;
	int orasDest = 8;
	int parinte[20];
	int gasit = 0;
	int nod;
	int solutie[20];
	int nrSol = 0;
	int limita = 0; // limita pt. cautare in adancime
	int cost[20]; // retine costul unui nod

	///* ***** Algoritmul de cautare cu cost uniform ***** */

	//for (int i = 0; i < n; i++) {
	//	vizitat[i] = 0; //1.Toate orasele sunt nevizitate.
	//}

	//noduri[0] = orasStart; //2. Adaugam in lista de noduri orasul de plecare.
	//nrNoduri++;
	//vizitat[orasStart] = 1; //3. Marcam orasul de plecare ca vizitat.
	//cost[orasStart] = 0; //4. Retinem adancimea.

	//while (!gasit && nrNoduri) {

	//	nod = noduri[0]; //5. Scoatem din fata primul nod.

	//	for (int i = 0; i < nrNoduri - 1; i++) {
	//		noduri[i] = noduri[i + 1]; //6. Eliminam primul element din lista de noduri.
	//	}

	//	nrNoduri--;

	//	if (nod == orasDest) {
	//		gasit = 1; //7. Daca testare_tinta[problema] se aplica la stare(nod), daca orasul == orasul tinta.
	//	}
	//	else {
	//		for (int i = 0; i < n; i++) {
	//			if ((a[nod][i] != 0) && ((vizitat[i] == 0) || ((vizitat[i] == 1) && (cost[i] > (cost[nod] + a[i][nod]))))) {
	//				//8. Cautam orasele "i" conectate de orasul nod si fie sunt nevizitate, fie au fost vizitate, dar costul vechi este mai mare decat costul nou.
	//				cost[i] = cost[nod] + a[i][nod];
	//				int k = 0; // Pozitia unde se adauga orasul i in lista de noduri a.i aceasta sa ramana ordonata crescator dupa cost
	//				while ((k < nrNoduri) && (cost[i] > cost[noduri[k]])) {
	//					k++;
	//				}
	//				for (int j = nrNoduri; j > k; j--) {
	//					noduri[j] = noduri[j - 1]; //9. Deplasam elementele din lista de noduri pana la pozitia k spre dreapta.
	//				}
	//				noduri[k] = i; //10. Adaugam in lista de noduri orasul "i" pe pozitia k.
	//				nrNoduri++;
	//				vizitat[i] = 1; //11. Orasele adaugate sunt marcate ca vizitate.
	//				parinte[i] = nod; //12. Se retine nodul parinte pt orasele adaugate.
	//			}
	//		}
	//	}
	//}

	///* ***** Algoritmul de cautare Greedy cu heuristica ***** */

	//for (int i = 0; i < n; i++)
	//	vizitat[i] = 0; //1.Toate orasele sunt nevizitate.

	//noduri[0] = orasStart; //2. Adaugam in lista de noduri orasul de plecare.
	//nrNoduri++;
	//vizitat[orasStart] = 1; //3. Marcam orasul de plecare ca vizitat.
	//cost[orasStart] = 0; //4. Retinem adancimea.

	//while (!gasit && nrNoduri) {

	//	nod = noduri[0]; //5. Scoatem din fata primul nod.

	//	for (int i = 0; i < nrNoduri - 1; i++)
	//		noduri[i] = noduri[i + 1]; //6. Eliminam primul element din lista de noduri.

	//	nrNoduri--;

	//	if (nod == orasDest) {
	//		gasit = 1; //7. Daca testare_tinta[problema] se aplica la stare(nod), daca orasul == orasul tinta.
	//	}
	//	else {
	//		for (int i = 0; i < n; i++) {
	//			if ((a[nod][i] != 0) && ((vizitat[i] == 0))) {
	//				//8. Cautam orasele "i" conectate de orasul nod si fie sunt nevizitate, fie au fost vizitate, dar costul vechi este mai mare decat costul nou.
	//				cost[i] = cost[nod] + a[i][nod];
	//				int k = 0; // Pozitia unde se adauga orasul i in lista de noduri a.i aceasta sa ramana ordonata crescator dupa heuristica
	//				while ((k < nrNoduri) && (h[i] > h[noduri[k]])) k++;
	//				for (int j = nrNoduri; j > k; j--) {
	//					noduri[j] = noduri[j - 1]; //9. Deplasam elementele din lista de noduri pana la pozitia k spre dreapta.
	//				}
	//				noduri[k] = i; //10. Adaugam in lista de noduri orasul "i" pe pozitia k.
	//				nrNoduri++;
	//				vizitat[i] = 1; //11. Orasele adaugate sunt marcate ca vizitate.
	//				parinte[i] = nod; //12. Se retine nodul parinte pt orasele adaugate.
	//			}
	//		}
	//	}
	//}

	/* ***** - Algoritmul de cautare A* - ***** */

	for (int i = 0; i < n; i++)
		vizitat[i] = 0; //1.Toate orasele sunt nevizitate.

	noduri[0] = orasStart; //2. Adaugam in lista de noduri orasul de plecare.
	nrNoduri++;
	vizitat[orasStart] = 1; //3. Marcam orasul de plecare ca vizitat.
	cost[orasStart] = 0; //4. Retinem adancimea.

	while (!gasit && nrNoduri) {

		nod = noduri[0]; //5. Scoatem din fata primul nod.

		for (int i = 0; i < nrNoduri - 1; i++)
			noduri[i] = noduri[i + 1]; //6. Eliminam primul element din lista de noduri.

		nrNoduri--;

		if (nod == orasDest) {
			gasit = 1; //7. Daca testare_tinta[problema] se aplica la stare(nod), daca orasul == orasul tinta.
		}
		else {
			for (int i = 0; i < n; i++) {
				if ((a[nod][i] != 0) && ((vizitat[i] == 0))) {
					//8. Cautam orasele "i" conectate de orasul nod si fie sunt nevizitate, fie au fost vizitate, dar costul vechi este mai mare decat costul nou.
					cost[i] = cost[nod] + a[i][nod];
					int k = 0; // Pozitia unde se adauga orasul i in lista de noduri a.i aceasta sa ramana ordonata crescator dupa heuristica
					while ((k < nrNoduri) && (cost[i] + h[i] > cost[noduri[k]] + h[noduri[k]])) k++;
					for (int j = nrNoduri; j > k; j--) {
						noduri[j] = noduri[j - 1]; //9. Deplasam elementele din lista de noduri pana la pozitia k spre dreapta.
					}
					noduri[k] = i; //10. Adaugam in lista de noduri orasul "i" pe pozitia k.
					nrNoduri++;
					vizitat[i] = 1; //11. Orasele adaugate sunt marcate ca vizitate.
					parinte[i] = nod; //12. Se retine nodul parinte pt orasele adaugate.
				}
			}
		}
	}


	/* **** Afisarea solutiei **** */
	/* formeaza vectorul solutie */
	if (gasit) {
		std::cout << "Distanta de la start la destinatie este: " << cost[orasDest] << std::endl;
		while (orasDest != orasStart) {
			solutie[nrSol] = orasDest;
			nrSol++;
			orasDest = parinte[orasDest];
		}
		solutie[nrSol] = orasDest;

		/* afisarea vectorului solutie */
		for (int i = nrSol; i >= 0; i--) {
			if (i == 0) {
				std::cout << nume[solutie[i]];
			}
			else {
				std::cout << nume[solutie[i]] << " -> ";
			}
		}
		std::cout << std::endl;

	}
	else {
		std::cout << "Solutia nu a fost gasita!";
	}

	_getch();
	return 0;
}