#include <bits/stdc++.h>

using namespace std;

int main(){
    /*
        Algoritmo 1
        m = mascara
        s = submascara
        Obtiene todas las submascaras posibles
    */
    int m, s = m;
    while(s > 0){
        s = (s - 1) & m;
    }
    /*
        Algoritmo 2
        n = maximo numero de bits
        Este para va en el intervalo [0, 2^n] encontrando todas las submascaras posibles
    */
    for(int i = 0; i < n; i++) if((1 << i) & mask) 
    return 0;
}