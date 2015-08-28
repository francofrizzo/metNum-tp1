#include "vector.h"

vector::vector() {
	tam = 0;
	vec = NULL;
}

vector::vector(const vector& o) {
	tam = o.tam;
	vec = new double[tam];
	for (int i = 0; i < tam; i++) {
		vec[i] = o.vec[i];
	}
}

vector::vector(int n) {
	tam = n;
	vec = new double[n];
	for (int i = 0; i < n; i++) {
		vec[i] = 0;
	}
}

vector::~vector() {
	if (vec != NULL) {
		delete vec;
	}
}

int vector::tamano() const{
	return tam;
}

double& vector::operator[](int i) {
	return vec[i];
}


double& vector::operator[](int i) const {
	return vec[i];
}

std::ostream& operator<<(std::ostream& os, const vector& vec) {
	cout << "[";
	for (int i = 0; i < vec.tamano() - 1; i++) {
		cout << vec[i] << ", ";
	}
	if (vec.tamano() > 0) {
		cout << vec[vec.tamano() - 1];
	}
	cout << "]" << endl;
}