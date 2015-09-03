#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream iF;
    iF.open("tiempos.sol");
    if (iF.is_open()) {
      while (iF.good()) {
        int m;
        int n;
        int ninst;
        int modo;
        double suma = 0;
        for (int i = 0; i < 4; i++) {
            iF >> m;
            iF >> n;
            iF >> ninst;
            iF >> modo;
            double valor;
            iF >> valor;
            suma = suma + valor;
        }
        cout << m+1 << " " << n << " " << ninst << " " << modo << " " << fixed << setprecision(8) << suma/4000000 << endl;
      }
      iF.close();
    }

    return 0;
}