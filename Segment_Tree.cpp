#include <bits/stdc++.h>

using namespace std;

int tree[t], arr[]={1, 3, 5, 7, 9, 11}, n = 6;

/*
    h = ceil(log2(n)) altura del arbol
    t = 2*pow(2, h) - 1 tamaño total del arbol
    n = pow(2, h) (numero de nodos) o el tamaño de el array
*/

void buildTree(int node, int l, int r){
    if(l == r){
        tree[node] = arr[l];
        return;
    }
    int mid = (l + r)/2;
    buildTree(2*node, l, mid);
    buildTree(2*node + 1, mid + 1, r);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int node, int l, int r, int i, int j){
    if(i <= l && r <= j) return tree[node];
    if(r < i || l > j) return 0;
    int mid = (l + r)/2;
    return query(2*node, l, mid, i, j) + query(2*node + 1, mid + 1, r, i, j);
}

void updateTree(int node, int l, int r, int i, int value){
    if(l == i && r == i){
        tree[node] = value;
        return;
    }
    int mid = (l + r)/2;
    if(i <= mid) updateTree(2*node, l, mid, i, value);
    else updateTree(2*node + 1, mid + 1, r, i, value);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int main(){
    buildTree(1, 0, n - 1);
    cout << query(1, 0, n - 1, 1, 3) << endl; //Suma de los valores del intervalo [1, 3]
    updateTree(1, 0, n - 1, 1, 10); //Remplazar el valor de arr[1] = 10 y actualizar
    cout << getSum(1, 0, n - 1, 1, 3) << endl; //Suma de los valores del intervalo [1, 3] con arr[1] = 10
    return 0;
}
