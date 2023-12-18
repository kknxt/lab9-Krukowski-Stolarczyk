#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	if (mat->r != mat->c || mat->r != b->r || x->r != b->r || x->c != 1) {
		printf("Nieprawidlowy rozmiar macierzy\n");
        return 2;
	}

	int n = mat->r;
	for (int w = n - 1; w >= 0; w--) {
        if (mat->data[w][w] == 0) {
		printf("Element na diagonali jest rowny 0");
            return 1;
        }

        double s = 0;
        for (int k = w + 1; k < n; k++) {
            s += mat->data[w][k] * x->data[k][0];
        }
        x->data[w][0] = (b->data[w][0] - s) / mat->data[w][w];
	}

	return 0;
}


