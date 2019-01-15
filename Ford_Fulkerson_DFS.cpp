#include <bits/stdc++.h>

using namespace std;
int n, graph[n][n], rGraph[n][n], parent[n];
bool visited[n];
            /*Ford Fulkerson with DFS*/
bool DFS(int s, int t){
    visited[s] = true;
    for(int v = 0; v < n; v++){
        if(!visited[v] && rGraph[s][v] > 0){
            parent[v] = s;
            DFS(v, t);
        }
    }
    return visited[t];
}

int fordFulkerson(int s, int t){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) rGraph[i][j] = graph[i][j];
    }
    int max_flow = 0;
    while(DFS(s, t)){
        int path_flow = INT_MAX;
        for(int i = t; i != s; i = parent[i]){
            int j = parent[i];
            path_flow = min(path_flow, rGraph[j][i]);
        }
        for(int i = t; i != s; i = parent[i]){
            int j = parent[i];
            rGraph[j][i]-=path_flow;
            rGraph[i][j]+=path_flow;
        }
        parent[s] = -1;
        memset(visited, false, sizeof(visited));
        max_flow+=path_flow;
    }
    return max_flow;
}

int main(){
    //Dado el grafo, donde n = nodos del grafo, s = source y t = sink
    memset(visited, false, sizeof(visited));
    cout<<fordFulkerson(s, t);
    return 0;
}