//https://cp-algorithms.com/data_structures/disjoint_set_union.html
void make_set(int n){
    for(int i = 0; i < n; i++) parent[i] = i;
}

int find(int i){
    if(i == parent[i]) return i;
    return find(parent[i]);
    /*
        return parent[i] = find(parent[i]) Compresion de camino (Mejora)
        La compresion de camino lo que hace es basicamente asignar directamente a la raiz los nodos que se
        visitan mientras se encuentra el nodo "i"
    */
}

bool union_set(int i, int j){
    int iRoot = find(i), jRoot = find(j);
    if(iRoot == jRoot) return false; 
    parent[iRoot] = jRoot;
    /*
        Mejora rank (Peso)
        if(iRoot != jRoot){
            if(sz[iRoot] < sz[jRoot]) swap(iRoot, jRoot);
            parent[jRoot] = iRoot; //El menor se añade al mayor
            sz[iRoot]+=sz[jRoot];
        }
        
        Mejora rank (Depth)
        if(iRoot != jRoot){
            if(depth[iRoot] < depth[jRoot]) swap(iRoot, jRoot);
            parent[jRoot] = iRoot; //El menor se añade al mayor
            if(depth[iRoot] == depth[jRoot]) depth[jRoot]++;
        }
        
        Mejora rank (Permite usar Path Compression)
        if(iRoot != jRoot){
            if(rankdsu[iRoot] < rankdsu[jRoot]) swap(iRoot, jRoot);
            parent[jRoot] = iRoot;
            if(rankdsu[iRoot] == rankdsu[jRoot]) rank[iRoot]++;
        }
    */
    return true;
}
