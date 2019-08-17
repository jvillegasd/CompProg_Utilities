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
        for(int v = 1; v <= n; v++){
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
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++) rGraph[u][v] = graph[u][v];
    }
    int max_flow = 0;
    while(BFS(s, t)){
        int path_flow = INT_MAX;
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            path_flow = min(path_flow, rGraph[v][u]);
        }
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            rGraph[u][v]-=path_flow; //Flujo saliente
            rGraph[v][j]+=path_flow; //Flujo entrante
        }
        max_flow+=path_flow;
    }
    return max_flow;
}
