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
  // cout << "¡Han llamado al destructor de matrices! Quieren que elimine " << this << ": " << endl << *this << endl;
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
  if (esCuadrada()) {
    int n = ancho();
    if (b.tamano() == n) {
      for (int j = 0; j < n; j++) {
        for (int i = j + 1; i < n; i++) {
          double m = mat[i][j] / mat[j][j];
          for (int k = j; k < n; k++) {
            mat[i][k] = mat[i][k] - m * mat[j][k];
          }
          b[i] = b[i] - m * b[j];
        }
      }
      return vector();
      return sustHaciaAtras(b);
   } else {
     cout << "Error: Las dimensiones del vector y de la matriz no coinciden." << endl;
     return vector();
   }
  } else {
   cout << "Error: La matriz no es cuadrada." << endl;
   return vector();
  }
}
void matriz::factorizacionLU() {
  if (esCuadrada()) {
    int n = ancho();
    for (int j = 0; j < n; j++) {
      for (int i = j + 1; i < n; i++) {
        int m = mat[i][j] / mat[j][j];
        mat[i][j] =  m;
        for (int k = j + 1; k < n; k++) {
          mat[i][k] = mat[i][k] - m * mat[j][k];
        }
        
      }
    }    
  } else {
      cout << "Error: La matriz no es cuadrada." << endl;
  }
}

vector matriz::solucionLU(vector& b){
  // multiplicar con L con b.
  int n = ancho();
  vector auxb = vector(n);
  for (int i = 0; i < n; i++) {
    auxb[i] = b[i];
    for (int j = 0; j < i; j++){
      auxb[i] = auxb[i] + mat[i][j] * b[j];
    }
  }
  return sustHaciaAtras(auxb);
}



vector matriz::sustHaciaAtras(vector& b) {
  int n = ancho();
  vector res = vector(n);

  for (int i = n-1; i >= 0; i--) {
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
    for (int j = 0; j < mat.alto(); j++) {
      cout << setfill(' ') << setw(10) << mat[i][j] << " ";
    }
    cout << endl;
  }
}
