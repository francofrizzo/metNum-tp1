#include "./matriz.h"
#include <stdio.h>

int main(){
    /* vector b = vector(3);
    for (int i = 0; i < 3; i++) {
        b[i] = i;
    }

    cout << b;

	matriz a = matriz(3, 3);
	
    a[0][0] = 9;
    a[0][1] = 7;
    a[0][2] = 5;
    a[1][0] = 6;
    a[1][1] = 4;
    a[1][2] = 0;
    a[2][0] = 1;
    a[2][1] = 0;
    a[2][2] = 0;

    a.eliminacionGaussiana(b);

    cout << a; */

    int re; //radio externo
    int ri; //radio interno
    double pi; //pi 3,14

    double deltaR = (re - ri)/m;
    double deltaRCuadrado = deltaR * deltaR;

    double r = ri + deltaR*j;
    double rCuadrado = r*r;
    
    double deltaT = (2*pi)/n;
    double deltaTCuadrado = deltaT * deltaT;

    for (j = 0; j < n; j++) {
        mat[j][j] = 1;
    }

    for (j = 1; j < m; j++) {
        for (k = 0; k < n; k++) {
            int p1 = hornoAMatriz(j-1, k);
            int p2 = hornoAMatriz(j, k-1);
            int p3 = hornoAMatriz(j, k);
            int p4 = hornoAMatriz(j, k+1);
            int p5 = hornoAMatriz(j+1, k);

            mat[p3][p1] = 1 / (deltaRCuadrado);
            mat[p3][p2] = 1 / (rCuadrado*deltaTCuadrado);
            mat[p3][p3] = -2 / deltaRCuadrado + 1 / (r*deltaR) - 2 / (rCuadrado*deltaTCuadrado);
            mat[p3][p4] = 1 / (rCuadrado*deltaTCuadrado);
            mat[p3][p5] = 1 / deltaRCuadrado;
        }
    }

    for (j = 0; j < n; j++) {
        mat[m*n+j][m*n+j] = 1;
    }

	return 0;
}
