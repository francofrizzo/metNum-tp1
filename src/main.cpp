#include "./matriz.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    cout << "Prueba de 3x3" << endl;

    matriz m2 = matriz(3, 3);

    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[0][2] = 3;
    m2[1][0] = 1;
    m2[1][1] = 4;
    m2[1][2] = 9;
    m2[2][0] = 1;
    m2[2][1] = 8;
    m2[2][2] = 27;

    vector b2 = vector(3);
    b2[0] = 3;
    b2[1] = 9;
    b2[2] = 7;

    cout << "Prueba la maravillosa... FACTORIZACIÓN LU!" << endl;

    cout << "Antes:" << endl;

    cout << m2 << endl;

    cout << endl << "Después:" << endl;

    m2.factorizacionLU();

    cout << m2 << endl << endl << "LLAME YA!" << endl;

    vector res2 = m2.solucionLU(b2);

    cout << "Solución: " << res2 << endl;

    m2[0][0] = 1;
    m2[0][1] = 2;
    m2[0][2] = 3;
    m2[1][0] = 1;
    m2[1][1] = 4;
    m2[1][2] = 9;
    m2[2][0] = 1;
    m2[2][1] = 8;
    m2[2][2] = 27;
    b2[0] = 3;
    b2[1] = 9;
    b2[2] = 7;

    vector resGauss2 = m2.eliminacionGaussiana(b2);

    cout << "Solución con Gauss: " << resGauss2 << endl;

    cout << endl << "Prueba de 4x4" << endl;

    matriz m = matriz(4, 4);

    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[0][3] = 4;
    m[1][0] = 1;
    m[1][1] = 4;
    m[1][2] = 9;
    m[1][3] = 16;
    m[2][0] = 1;
    m[2][1] = 8;
    m[2][2] = 27;
    m[2][3] = 64;
    m[3][0] = 1;
    m[3][1] = 16;
    m[3][2] = 81;
    m[3][3] = 256;

    vector b = vector(4);
    b[0] = 2;
    b[1] = 10;
    b[2] = 44;
    b[3] = 190;

    cout << "Prueba la maravillosa... FACTORIZACIÓN LU!" << endl;

    cout << "Antes:" << endl;

    cout << m << endl;

    cout << endl << "Después:" << endl;

    m.factorizacionLU();

    cout << m << endl << endl << "LLAME YA!" << endl;

    vector res = m.solucionLU(b);

    cout << "Solución: " << res << endl;

    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[0][3] = 4;
    m[1][0] = 1;
    m[1][1] = 4;
    m[1][2] = 9;
    m[1][3] = 16;
    m[2][0] = 1;
    m[2][1] = 8;
    m[2][2] = 27;
    m[2][3] = 64;
    m[3][0] = 1;
    m[3][1] = 16;
    m[3][2] = 81;
    m[3][3] = 256;
    b[0] = 2;
    b[1] = 10;
    b[2] = 44;
    b[3] = 190;

    vector resGauss = m.eliminacionGaussiana(b);

    cout << "Solución con Gauss: " << resGauss << endl;

    return 0;
}
