#include <bits/stdc++.h>

using namespace std;

bool vist[N];
vector<int> g[N], invG[N];
stack<int> s;

void DFS1(int u){
    vist[u] = true;
    for(auto v : g[u]) if(!vist[v]) DFS1(v);
    s.push(u);
}

void DFS2(int u){
    vist[u] = true;
    printf("%d ", u);
    for(auto v : invG[u]) if(!vist[v]) DFS2(v);
}

void SCC(){
    memset(vist, false, sizeof(vist));
    for(int u = 1; u <= n; u++) if(!vist[u]) DFS1(u); //Realizar DFS con el grafo para obtener nodos con el mayor tiempo de llegada
    memset(vist, false, sizeof(vist));
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!vist[v]){ //Imprimir SCC
            DFS2(v);
            printf("\n");
        }
    }
}

int main(){
    SCC();
    return 0;
}
