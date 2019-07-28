//Source: https://codeforces.com/blog/entry/44351
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[1000010];
multiset<int> dsu[1000010];
int k;

void DFS(int u, int p, int d){
    if(p && g[u].size()==1){
        dsu[u].insert(d);
        return;
    }
    int bigc = -1, dk, dki_val;
    for(auto v : g[u]){
        if(v==p) continue;
        DFS(v, u, d+1);
        if(bigc == -1 || dsu[v].size() > dsu[bigc].size()) bigc = v;
    }
    dsu[u]=dsu[bigc];
    for(auto v : g[u]){
        if(v==p || v==bigc) continue;
        for(auto di : dsu[v]){
            dk = d+k-(di-d);
            auto dki = dsu[u].upper_bound(dk);
            if(dki==dsu[u].begin()) dsu[u].insert(di);
            else{
                --dki;
                dki_val = *dki;
                dsu[u].erase(dki);
                dsu[u].insert(max(di, dki_val));
            }
        }
    }
}