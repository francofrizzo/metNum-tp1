#include <iostream>
#include "vector.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

class matriz {
 private:
    int filas;
    int columnas;
    vector* mat; //NO ENTENDEMOS POR QUE DOUBLE y no vector

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
    vector sustHaciaAtras(vector& b);
};

std::ostream& operator<<(std::ostream& os, const matriz& mat);
