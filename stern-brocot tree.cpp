/*
    Implementacion de busqueda de Stern-Brocot tree.
    Se usa la mediante para hacerlo y se realiza lo siguiente:
    1) Iniciar con un intervalo (p1/q1, p2/q2) = (0/1, 1/1) y se buscara el nodo p/q
    2) Se calcula la mediante: m=(p1+p2)/(q1+q2)
    3) Si p/q <= m, el nodo p/q estará a la derecha y el nuevo intervalo es (p1/q1, m); sino, el intervalo es (m, p2/q2)
    4) Te detienes cuando p1/q1, p2/q2 o m sean igual al nodo p/q
    Algo a notar es que las m anteriores a encontrar el nodo son los nodos anteriores en el camino de la raiz 1/1 a p/q,
    tambien lo pueden ser p1/q1 y p2/q2, todo depende de quien rompe el algoritmo. Los primeros nodos que tocan a p/q,
    son los p1/q1 y/o p2/q2 que sean diferentes a p/q, los demas son sus descendientes.
    En la implementacion de abajo, se encuentra el nodo p/q y los primeros n nodos que lo tocan

    Implementacion de creacion de Stern-Brocot tree.
    Si tienes un nodo a/b, su hijo izquierdo es: a/(a+b), y su hijo derecho es: (a+b)/b
*/
int main(){
    lli p, q, n, p1, q1, p2, q2, pm, qm, aux;
    while(scanf("%lld %lld %lld", &p, &q, &n) == 3){
        p1=0, q1=1, p2=1, q2=1;
        aux=n;
        while(true){
            if(p1 == p && q1 == q) break;
            if(p2 == p && q2 == q) break;
            pm=p1+p2;
            qm=q1+q2;
            if(pm == p && qm == q) break;
            if((double)p*qm <= (double)q*pm) p2=pm, q2=qm;
            else p1=pm, q1=qm;
        }
        set<pair<lli, lli>> ans;
        if((p1 != p || q1 != q) && n) ans.insert({p1, q1}), p1+=p, q1+=q, n--;
        if((p2 != p || q2 != q) && n) ans.insert({p2, q2}), p2+=p, q2+=q, n--;
        while(ans.size() <= aux){
            if((p1 != p || q1 != q) && ans.count({p1, q1}) == 0) ans.insert({p1, q1}), p1+=p, q1+=q;
            if((p2 != p || q2 != q) && ans.count({p2, q2}) == 0) ans.insert({p2, q2}), p2+=p, q2+=q;
        }
    }
    return 0;
}
