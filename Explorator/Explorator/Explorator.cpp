#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

char teren[11][11], explorator= 'E';

int senzor_atingere, senzor_celula, senzor_comoara;

void action_left(int counter, int& i, int& j) {

	if (counter % 4 == 0 /*&& teren[i++][j] != 'X'*/) {

		swap(teren[i][j], teren[i++][j]);
		while (i > 11) {

			i--;
		}
		while (j > 11) {

			j--;
		}
		while (i < 0) {

			i++;
		}
		while (j < 0) {

			j++;
		}
		/*i++;*/
	}
	else {
		if (counter % 3 == 0 /*&& teren[i][j--] != 'X'*/) {

			swap(teren[i][j], teren[i][j--]);
			/*j--;*/
			while (i > 11){

				i--;
			}
			while(j>11){
			
				j--;
			}
			while (i < 0) {

				i++;
			}
			while (j < 0) {

				j++;
			}
		}
		else {
			if (counter % 2 == 0 /*&& teren[i--][j] != 'X'*/) {
				
				swap(teren[i][j], teren[i--][j]);
				/*i--;*/
			}
			while (i > 11){

				i--;
			}
			while(j>11){
			
				j--;
			}
			while (i < 0) {

				i++;
			}
			while (j < 0) {

				j++;
			}
		}
	}
}

void action_right(int counter, int& i, int& j) {

	if (counter % 4 == 0 /*&& teren[i--][j] != 'X'*/) {

		swap(teren[i][j], teren[i--][j]);
		/*i--;*/
		while (i > 11) {

			i--;
		}
		while (j > 11) {

			j--;
		}
		while (i < 0) {

			i++;
		}
		while (j < 0) {

			j++;
		}
	}
	else {

		if (counter % 3 == 0 /*&& teren[i][j--] != 'X'*/) {

			swap(teren[i][j], teren[i][j--]);
			/*j--;*/
			while (i > 11) {

				i--;
			}
			while (j > 11) {

				j--;
			}
			while (i < 0) {

				i++;
			}
			while (j < 0) {

				j++;
			}
		}
		else {

			if (counter % 2 == 0 /*&& teren[i++][j] != 'X'*/) {

				swap(teren[i][j], teren[i++][j]);
				/*i++;*/
				while (i > 11){

				i--;
			}
			while(j>11){
			
				j--;
			}
			while (i < 0) {

				i++;
			}
			while (j < 0) {

				j++;
			}
			}
		}
	}
}

void afisare() {

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {

			cout << teren[i][j] << "   ";
		}
		cout << endl << endl;
	}
}

void initializare_teren() {

	srand(time(NULL));

	int k = 0, poz1, poz2;

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {

			teren[i][j] = 254;
		}
	}

	while (k < 30) {

		poz1 = rand() % 11;
		poz2 = rand() % 11;
		while (poz1 == 10 || poz2 == 1) {

			poz1 = rand() % 11;
			poz2 = rand() % 11;
		}
		teren[poz1][poz2] = 'X';
		k++;
	}

	teren[10][0] = explorator;
	k = 0;

	while (k < 3) {

		poz1 = rand() % 11;
		poz2 = rand() % 11;
		if (teren[poz1][poz2] != 'X' && teren[poz1][poz2] != 1) {

			teren[poz1][poz2] = 71;
			k++;
		}
	}

	k = 0;

	while (k < 2) {

		poz1 = rand() % 11;
		poz2 = rand() % 11;
		if (teren[poz1][poz2] != 'X' && teren[poz1][poz2] != 1 && teren[poz1][poz2] != 'G') {

			teren[poz1][poz2] = 77;
			k++;
		}
	}
	int orientare;

	string intoarcere, optiune;
	int l_counter = 1, r_counter = 1, counter = 1, e_i = 10, e_j = 0;

	while (optiune != "5") {

		system("CLS");

		cout << e_i << " " << e_j << endl;

		afisare();

		cout << "Alegeti una dintre optiuni : " << endl;
		cout << " 1 : Mergi in fata" << endl;
		cout << " 2 : Intoarcere dreapta (90 grade)" << endl;
		cout << " 3 : Intoarcere stanga (90 grade)" << endl;
		cout << " 4 : Impusca celula din fata" << endl;
		cout << " 5 : Oprire" << endl << endl;

		cout << "Optiunea aleasa este : "; cin >> optiune;

		if (optiune == "2") {

			r_counter++;
		}
		else {

			if (optiune == "3") {

				l_counter++;
			}
		}

		if (l_counter == r_counter && optiune == "1" && e_j < 10 && teren[e_i][e_j + 1] != 'X') {

			counter = 1;
			swap(teren[e_i][e_j], teren[e_i][e_j + 1]);
			e_j++;
		}
		else {

			if (l_counter > r_counter) {

				counter = 1 + l_counter - r_counter ;
				action_left(counter, e_i, e_j);

			}
			else {

				if (r_counter > l_counter) {

					counter = 1 + r_counter - l_counter;
					action_right(counter, e_i, e_j);
				}
			}
		}
	}

}

void main() {

	initializare_teren();
	/*afisare();*/
	/*dasdasd*/
	/*system("CLS");*/
}