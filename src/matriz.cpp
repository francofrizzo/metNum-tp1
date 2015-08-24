#include "matriz.h"

matriz::matriz() {
  columnas = 0;
  filas = 0;
  mat = NULL;
}

matriz::matriz(const matriz& o) {
  columnas = o.columnas;
  filas = o.filas;
  for (int i = 0; i < filas; i++) {
    mat[i] = vector(o[i]);
  }
}

matriz::matriz(int n, int m){
  columnas = n;
  filas = m;
  mat = new vector[m];
  for (int i = 0; i < m; i++) {
    mat[i] = vector(n);
  }
}

matriz::~matriz() {
/*  for(int i = 0; i < filas; i++) {
    ~vector(mat[i]);
  }
  if(mat != NULL) {
    ~vector(mat);
  } */
}

int matriz::ancho() const {
  return columnas;
}

int matriz::alto() const {
  return filas;
}

bool matriz::esCuadrada() {
  return (columnas == filas);
}

vector& matriz::operator[](int i) {
  return mat[i];
}


vector& matriz::operator[](int i) const {
  return mat[i];
}

vector matriz::eliminacionGaussiana(vector& b) {
  //if (esCuadrada()) {
    int n = ancho();
  //  if (b.tamano() == n) {
      for (int j = 0; j < n; j++) {
        for (int i = j + 1; j < n; j++) {
          int m = mat[i][j] / mat[j][j];
          for (int k = j; k < n; k++) {
            mat[i][k] = mat[i][k] - m * mat[j][k];
          }
          b[i] = b[i] - m * b[j];
        }
      }
      return sustHaciaAtras(b);
  //  } else {
  //    throw domain_error("Error: Las dimensiones del vector y de la matriz no coinciden.");
  //  }
  //} else {
  //  throw domain_error("Error: La matriz no es cuadrada.");
  //}
}

vector matriz::sustHaciaAtras(vector& b) {
  int n = ancho();
  vector res = vector(n);

  for (int i = n; i >= 0; i--) {
    int suma = 0;
    for (int j = i + 1; j < n; j++) {
      suma = suma + mat[i][j] * res[j];
    }
    res[i] = (b[i] - suma) / mat[i][i];
  }

  return res;
}

std::ostream& operator<<(std::ostream& os, const matriz& mat) {
  for (int i = 0; i < mat.alto(); i++) {
    cout << "Fila " << i << ": " << mat[i] << endl; 
  }
}
