#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

class vector {
 private:
    int tamano;
    double* vec;

 public:
    vector();
    vector(const vector& o);
    vector(int n);

    ~vector();

    int tamano();
    double& operator[](int i) const;
};

class matriz {
 private:
    int alto;
    int ancho;
    double* mat;

 public:
    matriz();
    matriz(const matriz& o);
    matriz(int n, int m);

    ~matriz();

    int ancho();
    int alto();
    bool esCuadrada();
    vector& operator[](int i) const;

    vector eliminacionGaussiana(vector& b);
    vector sustHaciaAtras(const vector& b) const;
};

std::ostream& operator<<(std::ostream& os, const vector& vec);
std::ostream& operator<<(std::ostream& os, const matriz& mat);
