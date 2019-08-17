//https://cp-algorithms.com/graph/edmonds_karp.html
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

/*
    Implementacion de Edmonds-Karp del algoritmo de Ford-Fulkerson para el maximo flujo
    de un grafo, con complejidad: O(VE^2). s = source, t = sink y = numero de nodos
*/

int maxflow(int s, int t, int n) {
    int flow = 0;
    vector<int> parent(n+1);
    int new_flow;
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur]-=new_flow; //Flujo saliente de prev a cur
            capacity[cur][prev]+=new_flow;  //Flujo entrante de cur desde prev
            cur = prev;
        }
    }
    return flow;
}
