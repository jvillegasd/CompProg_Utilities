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

/*
	Implementacion del Unweigthed Maximum Bipartite Matching usando el algoritmo
	de Ford-Fulkerson con complejidad O(VE).
	n = numero de nodos del grafo 1
	m = numero de nodos del grafo 2
	Si graph[u][v] == 1, entonces, hay una arista (u, v)
*/

int MBM(int n, int m){
    int matching = 0;
    memset(match, -1, sizeof(match));
    for(int i = 0; i < n; i++){
        memset(visited, false, sizeof(visited));
        if(DFS(i, m)) matching++;
    }
    return maxFlow;
}