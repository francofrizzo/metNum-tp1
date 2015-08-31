#include <iostream>
#include <iomanip>
#include "vector.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::setfill;
using std::setw;

class matriz {
 private:
    int filas;
    int columnas;
    vector* mat;

 public:
    matriz();
    matriz(const matriz& o);
    matriz(int n, int m);

    ~matriz();

    int ancho() const;
    int alto() const;
    bool esCuadrada();
    vector& operator[](int i);
    vector& operator[](int i) const;

    vector eliminacionGaussiana(vector& b);
    vector sustHaciaAtras(vector& b) const;
    vector sustHaciaAdelante(vector& b) const;
    vector sustHaciaAdelanteConUnos(vector& b) const;
    void factorizacionLU();
    vector solucionLU(vector& b) const;
};

std::ostream& operator<<(std::ostream& os, const matriz& mat);
