#include <bits/stdc++.h>

using namespace std;
                                     /*Unweighted Maximum Bipartite Matching*/
bool graph[150][150], visited[150];
int match[150];

bool DFS(int node, int m){
    for(int i = 0; i < m; i++){
        if(graph[node][i] && !visited[i]){
            visited[i] = true;
            if(match[i] < 0 || DFS(match[i], m)){
                match[i] = node;
                return true;
            }
        }
    }
    return false;
}

int MBM(int n, int m){
    int maxFlow = 0;
    memset(match, -1, sizeof(match));
    for(int i = 0; i < n; i++){
        memset(visited, false, sizeof(visited));
        if(DFS(i, m)) maxFlow++;
    }
    return maxFlow;
}

int main(){
    //Dado el grafo, donde n = nodos del grafo 1, m = nodos del grafo 2
    MBM(n, m);
    return 0;
}