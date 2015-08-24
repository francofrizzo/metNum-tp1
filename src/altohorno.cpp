#include "./matriz.h"

int main(){
	matriz a = matriz(5, 5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << a[i];
			a[i][j] = double(i);
		}
	}

	cout << a;

	return 0;
}
