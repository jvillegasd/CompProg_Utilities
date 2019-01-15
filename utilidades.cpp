/**
 krthr 2017
 */


#include <bits/stdc++.h>

using namespace std;

int main() {

    // Declarar un vector de enteros
    vector<int> vec;
    // Tamaño
    int n = vec.size();
    // Agregar elemento
    vec.push_back(2);
    // Eliminar último elemento
    vec.pop_back();
    // Ordenar
    sort(vec.begin(), vec.end());

    // Eliminar
    // Removes the element present at position.
    vec.erase(vec.begin() + 4); // (erases the fifth element of the vector v)
    // Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
    vec.erase(vec.begin()+2,vec.begin()+5); // (erases all the elements from the third element to the fifth element.)

}
