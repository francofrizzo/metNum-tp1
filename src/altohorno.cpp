#include "./matriz.h"
#include <iostream>
#include <fstream>

#define M_PI 3.14159265358979323846

// using std::ifstream;
// using std::ofstream;
using namespace std;

int hornoAMatriz(int j, int k, int n) {
    if (k == -1) {
        k = n - 1;
    } else if (k == n) {
        k = 0;
    }
    return j * n + (k % n);
}

int modulo (int a) {
    int res = a;
    if (a < 0){
        res = -a;
    }
    return res;
}

vector isoterma(vector v, int iso, int n, int m, int re, int ri) {
    vector res = vector(n);
    int h;
    int r;
    for (int j = 0; j < n; j++) {
        h = v[j];
        r = 0;
        for (int i = 0; i < (m + 1)*n - j; i + n) {
            if (modulo(iso - v[i + j]) <= modulo(iso - h)) {
                h = v[i + j];
                r = i / n;
            }
        }
        res [j] = ri + r * ((re - ri) / (m + 1));
    }
    return res;
}

vector isotermaPeligro(vector v, int iso, int n, int m, int re, int ri) {
    vector res = vector(n);
    int h;
    int r; 
    for (int j = 0; j < n; j++) {
        h = v[(m + 1)*n - 1 - j];
        r = m + 1;
        for (int i = (m + 1)*n - 1; i >= 0; i - n) {
            if (v[i - j] < iso) {
                h = v[i - j];
                r = i / n;
            }
        }
        res[j] = ri + r * ((re - ri) / (m + 1));
    }
    return res;
}


vector isotermaExactaCasi(vector v, int iso, int n, int m, int re, int ri) {
    vector res = vector(n);
    int h;
    int r;
    for (int j = 0; j < n; j++) {
        h = v[(m + 1)*n - 1 - j];
        r = m + 1;
        for (int i = (m + 1)*n - 1; i >= 0; i - n) {
            if (v[i - j] < iso) {
                h = v[i - j];
                r = i / n;
            }
        }
        res[j] = ri + r * ((re - ri) / (m + 1)) - ((v[r] - iso) / (v[r - 1] - v[r])) * ((re - ri) / (m + 1));
    }
    return res;
}








int main(int argc, char* argv[]) {

    // Leo los datos desde el archivo de entrada

    ifstream infile;
    infile.open(argv[1], ios::in);
    // infile.open("minions.in", ios::in);

    if (argc < 4) {
        cout << "Error: Faltan argumentos" << endl;
        return 0;
    }

    double ri; //radio interno
    double re; //radio externo
    int m;
    int n;
    double iso;
    int ninst;

    infile >> ri;
    infile >> re;
    infile >> m;
    m--;
    infile >> n;
    infile >> iso;
    infile >> ninst;

    vector datos[ninst];

    for (int i = 0; i < ninst; i++) {
        datos[i] = vector(n * (m + 1));

        for (int j = 0; j < n; j++) {
            infile >> datos[i][j];
        }

        for (int j = 0; j < n; j++) {
            infile >> datos[i][n * m + j];
        }
    }

    infile.close();

    // Construyo la matriz del sistema

    matriz mat = matriz(n * (m + 1), n * (m + 1));

    double deltaR = (re - ri) / m;
    double deltaRCuadrado = deltaR * deltaR;

    double r;
    double rCuadrado;
    
    double deltaT = (2 * M_PI) / n;
    double deltaTCuadrado = deltaT * deltaT;

    for (int j = 0; j < n; j++) {
        mat[j][j] = 1;
    }

    for (int j = 1; j < m; j++) {
        r = ri + deltaR * j;
        rCuadrado = r*r;

        double coef1 = 1 / (deltaRCuadrado) - 1 / (r * deltaR);
        double coef2 = 1 / (rCuadrado * deltaTCuadrado);
        double coef3 = -2 / deltaRCuadrado + 1 / (r * deltaR) - 2 / (rCuadrado * deltaTCuadrado);
        double coef4 = 1 / (rCuadrado * deltaTCuadrado);
        double coef5 = 1 / deltaRCuadrado;


        for (int k = 0; k < n; k++) {
            int p1 = hornoAMatriz(j - 1, k, n);
            int p2 = hornoAMatriz(j, k - 1, n);
            int p3 = hornoAMatriz(j, k, n);
            int p4 = hornoAMatriz(j, k + 1, n);
            int p5 = hornoAMatriz(j + 1, k, n);

            mat[p3][p1] = coef1;
            mat[p3][p2] = coef2;
            mat[p3][p3] = coef3;
            mat[p3][p4] = coef4;
            mat[p3][p5] = coef5;
        }
    }

    for (int j = 0; j < n; j++) {
        mat[m * n + j][m * n + j] = 1;
    }

    // Abro el archivo de salida

    ofstream outfile;
    outfile.open(argv[2], ios::in);
    // outfile.open("minions.out", ios::in);

    // Aplico el algoritmo pedido

    // if ('1' == '1') {
    if (*(argv[3]) == '1') {

        // Factorización LU

        mat.factorizacionLU();

        for (int i = 0; i < ninst; i++) {
            vector res = mat.solucionLU(datos[i]);

            // Imprimo los resultados            

            for (int j = 0; j < res.tamano(); j++) {
                outfile << fixed << setprecision(6) << res[j] << endl;
            }
        }

    // } else if ('1' == '0') {       
    } else if (*(argv[3]) == '0') {       

        // Eliminación gaussiana

        for (int i = 0; i < ninst; i++) {
            matriz matCopia = matriz(mat);
            vector res = matCopia.eliminacionGaussiana(datos[i]);

            // Imprimo los resultados

            for (int j = 0; j < res.tamano(); j++) {
                outfile << fixed << setprecision(6) << res[j] << endl;
            }
        }
    }

    // Cierro el archivo de salida

    outfile.close();

    return 0;
}
