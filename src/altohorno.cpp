#include "./matriz.h"

int main(){
    vector b = vector(3);
    for (int i = 0; i < 3; i++) {
        b[i] = i;
    }

    cout << b;

	matriz a = matriz(3, 3);
	
    a[0][0] = 9;
    a[0][1] = 7;
    a[0][2] = 5;
    a[1][0] = 6;
    a[1][1] = 4;
    a[1][2] = 0;
    a[2][0] = 1;
    a[2][1] = 0;
    a[2][2] = 0;

    a.eliminacionGaussiana(b);

    cout << a;

	return 0;
}
