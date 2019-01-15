#include <bits/stdc++.h>

using namespace std;

vector<int> g[1100];
int b;
bool vist[1100];

void DFS(int u, int cont, int &maxi){
    vist[u] = true;
    cont++;
    for(auto v : g[u]){
        if(!vist[v]){
            if(cont >= maxi) maxi = cont, b = v;
            DFS(v, cont, maxi);
        }
    }
}

int treeDiam(int n){
    int maxi = INT_MIN;
    memset(vist, false, sizeof(vist));
    DFS(1, 1, maxi);
    memset(vist, false, sizeof(vist));
    DFS(b, 1, maxi);
    return maxi;
}

int main(){
    treeDiam(n);
    return 0;
}