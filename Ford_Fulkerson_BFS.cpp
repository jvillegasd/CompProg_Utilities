int graph[n][n], rGraph[n][n], n, parent[n];

bool BFS(int s, int t){
    bool visited[n];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++){
            if(!visited[v] && rGraph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}
//Dado el grafo, donde n = nodos del grafo, s = source y t = sink
int fordFulkerson(int s, int t){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) rGraph[i][j] = graph[i][j];
    }
    int max_flow = 0;
    while(BFS(s, t)){
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
        max_flow+=path_flow;
    }
    return max_flow;
}
