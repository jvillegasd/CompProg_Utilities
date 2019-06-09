//Modificado de http://www.inf.fh-flensburg.de/lang/algorithmen/sortieren/merge/mergen.htm
void merge(int a[], int l, int m, int r){
    int i = l, j = m+1, bsize = 0, cnt = 0, b[1000100];
    while(i<=m && j<=r){
        if(a[i]<=a[j]) b[bsize++]=a[i++];
        else b[bsize++]=a[j++], cnt++;
    }
    while(i<=m) b[bsize++]=a[i++];
    while(j<=r) b[bsize++]=a[j++];
    for(int k = 0; k < bsize; k++) a[l+k] = b[k];
}

void mergesort(int a[], int l, int r){
    if(l >= r) return;
    int m = (l+r)/2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
}

int main(){
    int a[1000100], n;
    mergesort(a, 0, n-1);
    return 0;
}
