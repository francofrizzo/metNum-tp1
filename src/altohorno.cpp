#include "./matriz.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

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

int modulo(int a) {
    int res = a;
    if (a < 0){
        res = -a;
    }
    return res;
}

double peligrosidad(vector iso, double re) {
    int n = iso.tamano();
    double res = 0;
    for(int i = 0; i < n; i++) {
        if (iso[i] > res) {
            res = iso[i];
        }
    }
    return res / re;

}

vector isotermaMenorDiferencia(vector v, double iso, int n, int m, double re, double ri) {
    vector res = vector(n);
    double h;
    int r;
    for (int j = 0; j < n; j++) {
        h = v[j];
        r = 0;
        for (int i = 0; i < (m + 1)*n - j; i = i + n) {
            if (modulo(iso - v[i + j]) <= modulo(iso - h)) {
                h = v[i + j];
                r = i / n;
            }
        }
        res [j] = ri + r * ((re - ri) / (m + 1));
    }
    return res;
}

vector isotermaPeligro(vector temp, double iso, int n, int m, double re, double ri) {
    vector res = vector(n);
    double deltaR = (re - ri) / m;
    for (int j = 0; j < n; j++) {
        res[j] = re;
        for (int i = m; i >= 0; i--) {
            int ind = hornoAMatriz(i, j, n);
            if (temp[ind] > iso) {
                res[j] = ri + deltaR * i;
                break;
            }
        }
    }
    return res;
}

vector isotermaCasiExacta(vector temp, double iso, int n, int m, double re, double ri) { // Revisar casos borde
    vector res = vector(n);
    double deltaR = (re - ri) / m;
    for (int k = 0; k < n; k++) {
        res[k] = re;
        if (temp[hornoAMatriz(m, k, n)] < iso) {
            for (int j = m - 1; j >= 0; j--) {
                int ind1 = hornoAMatriz(j, k, n);
                int ind2 = hornoAMatriz(j + 1, k, n);
                if (temp[ind1] >= iso) {
                    res[k] = ri + deltaR * (j + (iso - temp[ind1])/(temp[ind2] - temp[ind1]));
                    break;
                }
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]) {

    // Leo los datos desde el archivo de entrada

    ifstream infile;
    infile.open(argv[1], ios::in);

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
    outfile.open(argv[2], ios::out);
    // outfile.open("minions.out", ios::in);

    // Reviso si quieren la isoterma y el tiempo

    ofstream isofile;
    bool pidieronIsoterma = false;
    bool pidieronTiempo = false;
    char isoModo;

    if (argc > 4) {
        if (argv[4] == string("-t")) {
            pidieronTiempo = true;
            if (argc > 6) {
                pidieronIsoterma = true;
                isofile.open(argv[4], ios::out);
                isoModo = *(argv[5]);
            }
        } else {
            if (argc > 5) {
                pidieronIsoterma = true;
                isofile.open(argv[4], ios::out);
                isoModo = *(argv[5]);
            }
        }
    }

    // Aplico el algoritmo pedido

    clock_t t;
    char algoritmo = *(argv[3]);
    if (algoritmo == '1') {

        // Factorización LU

        t = clock();

        mat.factorizacionLU();

        for (int i = 0; i < ninst; i++) {
            vector res = mat.solucionLU(datos[i]);

            // Imprimo los resultados            
            for (int j = 0; j < res.tamano(); j++) {
                outfile << fixed << setprecision(6) << res[j] << endl;
            }

            // Calculo la isoterma
            if (pidieronIsoterma) {
                vector isoterma;
                if (isoModo == '0') {
                    isoterma = isotermaMenorDiferencia(res, iso, n, m, re, ri);
                } else if (isoModo == '1') {
                    isoterma = isotermaPeligro(res, iso, n, m, re, ri);
                } else if (isoModo == '2') {
                    isoterma = isotermaCasiExacta(res, iso, n, m, re, ri);
                }
                cout << "Ïndice de peligrosidad:" << peligrosidad(isoterma, re) << endl;
                // Imprimo la isoterma            
                for (int j = 0; j < isoterma.tamano(); j++) {
                    isofile << fixed << setprecision(6) << isoterma[j] << endl;
                }
            }
        }

        t = clock() - t;

        if (pidieronTiempo) {
            cout << "Tiempo de ejecución (ciclos de clock): " << t << endl;
            ofstream timefile;
            timefile.open("tiempos.sol", ios::app);
            timefile << m << " " << n << " " << ninst << " " << algoritmo << " " << t << endl;
        }

    } else if (algoritmo == '0') {       

        // Eliminación gaussiana

        t = clock();

        for (int i = 0; i < ninst; i++) {
            matriz matCopia = matriz(mat);
            
            // mat.esDiagDomin(); // CHEQUEO

            vector res = matCopia.eliminacionGaussiana(datos[i]);


            // Imprimo los resultados
            for (int j = 0; j < res.tamano(); j++) {
                outfile << fixed << setprecision(6) << res[j] << endl;
            }

            // Calculo la isoterma
            if (pidieronIsoterma) {
                vector isoterma;
                if (isoModo == '0') {
                    isoterma = isotermaMenorDiferencia(res, iso, n, m, re, ri);
                } else if (isoModo == '1') {
                    isoterma = isotermaPeligro(res, iso, n, m, re, ri);
                } else if (isoModo == '2') {
                    isoterma = isotermaCasiExacta(res, iso, n, m, re, ri);
                }
                cout << "Ïndice de peligrosidad:" << peligrosidad(isoterma, re) << endl;

                // Imprimo la isoterma            
                for (int j = 0; j < isoterma.tamano(); j++) {
                    isofile << fixed << setprecision(6) << isoterma[j] << endl;
                }
            }
        }

        t = clock() - t;

        if (pidieronTiempo) {
            cout << "Tiempo de ejecución (ciclos de clock): " << t << endl;
            ofstream timefile;
            timefile.open("tiempos.sol", ios::app);
            timefile << m << " " << n << " " << ninst << " " << algoritmo << " " << t << endl;
        }
    }

    // Cierro el archivo de salida

    outfile.close();
    isofile.close();

    return 0;
}
