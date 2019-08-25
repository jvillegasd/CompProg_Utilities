//Modificado de http://www.inf.fh-flensburg.de/lang/algorithmen/sortieren/merge/mergen.htm
void merge(int a[], int l, int m, int r){
    int i = l, j = m+1, bsize = 0, b[1000100], inv;
    while(i<=m && j<=r){
        if(a[i]<=a[j]) b[bsize++]=a[i++];
        else b[bsize++]=a[j++], //inv+=(m-i+1);
    }
    while(i<=m) b[bsize++]=a[i++];
    while(j<=r) b[bsize++]=a[j++];
    for(int k = 0; k < bsize; k++) a[l+k] = b[k];
}

void mergesort(int a[], int l, int r){
    int inv=0
    if(l >= r) return;
    int m = (l+r)/2;
    mergesort(a, l, m); //Asignar a inv
    mergesort(a, m+1, r); //Sumar a inv 
    merge(a, l, m, r); //Sumar a inv
    //return inv;
}

/*
    Implementacion del MegeSort para ordenar un array en O(nLog(n)).
    Tambien se usa para contar las inversiones del arra.
    Una inversion es el costo que se paga por ordenar dos elementos a[i] y a[j],
    para contarlo se deben colocar los metodos: mergesort y merge como int.
*/

int main(){
    int a[1000100], n;
    mergesort(a, 0, n-1);
    return 0;
}
