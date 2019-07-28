//Source: https://codeforces.com/blog/entry/44351
typedef long long int lli;
typedef pair<int, int> pii;
vector<int> g[1000010];
multiset<int> dsu[1000010];
int k;
/*
	Es la implementacion en O(nlog^2(n)) de DSU on trees. Sirve para resolver problemas donde
	se pregunten ciertas propiedades que debe tener un nodo "u", todo esto para multiples queries.
	El multiset hace de la estructura del dsu, aqui se iran guardando los representantes de cada conjunto,
	esto cambia de acuerdo al problema. Una optimizacion lo cual hace que tenga la complejidad antes descrita
	es el hecho de usar la mejora del peso del DSU original, para esto, se busca el hijo del subarbol "u" que
	tenga mas peso y este se le asigna al DSU de "u". Dependiendo de la propiedad que te esten pidiendo, vas
	a iterar en los demas hijos e iras buscando nodos que cumplan la propiedad especifica y lo iras uniendo
	en su respectivo conjunto disjunto (literalmente como el DSU original), claro, dependiendo de que si entra en uno
	ya creado o sino, lo crea. Cabe aclarar que la union tambien depende del problema. 
	Ejemplo: La implementacion que esta aqui corresponde a un problema cuyo enunciado es:
	Dado un arbol, se necesita el numero de conjuntos de hojas cuyas distancias "d" entre ellas sea "d"<="k";
	para optimizar espacio solo guardabamos el representante de cada conjunto disjunto y esto se denotaba como 
	el que tuviera una mayor distancia ya que solo nos pedia el numero de conjuntos disjuntos
*/
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