#include "gauss.h"

/**
Zwraca 0 - elimnacja zakonczona sukcesem
Zwraca 1 - macierz osobliwa - dzielenie przez 0
*/

int eliminate(Matrix *mat, Matrix *b){
    
	int i, j, k;

    for (i = 0; i < mat->r - 1; i++){
        if (mat->data[i][i] == 0.0){
            return 1;
		}
		for (k = i + 1; k < mat->r; k++){
            double factor = mat->data[k][i] / mat->data[i][i];
            for (j = i; j < mat->c; j++){
               mat->data[k][j] -= factor * mat->data[i][j];
            }
            b->data[k][0] -= factor * b->data[i][0];
        }
    }

    return 0;
}
