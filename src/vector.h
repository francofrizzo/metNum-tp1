#include <iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

class vector {
 private:
    int tam;
    double* vec;

 public:
    vector();
    vector(const vector& o);
    vector(int n);

    ~vector();

    int tamano() const;
    double& operator[](int i);
    double& operator[](int i) const;
};

std::ostream& operator<<(std::ostream& os, const vector& vec);
