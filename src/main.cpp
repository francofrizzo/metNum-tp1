#include "./matriz.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    vector v = vector(4);

    for (int i = 0; i < 4; i++) {
        v[i] = i + 2;
    }

    cout << v << endl;

    matriz m = matriz(900,900);

    m[0][0] = 2.5;

    return 0;
}
