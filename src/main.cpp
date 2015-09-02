#include <iostream>
#include <fstream>
#include <string>
#include <math.h> 
#include <iomanip>

#define M_PI 3.14159265358979323846

using namespace std;

int main(int argc, char* argv[]){
    
    char modo = *(argv[2]);
    int n = std::stoi(argv[3]); 

    ofstream outfile;
    outfile.open(argv[1], ios::out);

    for(int i = 0; i < n; i++){
    	outfile << "1500 ";
    }

    if (modo == '0'){
    	//constante
    	for(int i = 0; i < n; i++){
    		outfile <<"50 ";    		
    	}
    } else {
    	//funcion seno
    	double x;
    	for(int i = 0; i < n; i++) {
    		x = 75 * sin((4 * M_PI) / n * i) + 125;
    		outfile << int(x) << " "; 
    	}
    }

    outfile.close();


	return 0;
}