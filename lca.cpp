parent[n nodes][lg2n == log2(n nodes)+1]
void DFS2(int u, int p){
    tin[u] = cntt++;
    parent[u][0] = p;
    for(int i = 1; i < lg2n; ++i) parent[u][i] = parent[parent[u][i-1]][i-1];
    for(auto v : g[u]){
        if(v == p) continue;
        DFS2(v, u);
    }
    tout[u] = cntt++;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(is_anc(u, v)) return u;
    if(is_anc(v, u)) return v;
    for(int i = lg2n - 1; i >= 0; --i) if(parent[u][i] && !is_anc(parent[u][i], v)) u = parent[u][i];
    return parent[u][0];
}
