/*
	Implementacion de la secuenca de Bruijin de alfabeto de tamaño k
	con subcadenas de tamaño n.
	Es una secuencia ciclica donde todas las diferentes subcadenas de tamaño n
	aparecen una sola vez.
*/

vector<int> sequence;

void calSequence(int k, int n, int t, int p, int a[]){
  if(t > n){
    if(n % p == 0){
      for(int i = 1; i < p + 1; i++) sequence.push_back(a[i]);
    }
  }else{
      a[t] = a[t - p];
      calSequence(k, n, t + 1, p, a);
      for(int i = a[t - p] + 1; i < k; i++){
        a[t] = i;
        calSequence(k, n, t + 1, t, a);
      }
    }
}

void deBruijn_Sequence(int k, int n){
  int a[n * k] = {0};
  sequence.clear();
  if(k > 1){
    calSequence(k, n, 1, 1, a);
    for(int i = 0; i < sequence.size(); i++) printf("%c", sequence[i]+'A');
  }else for(int i = 0; i < n; i++) printf("%c",'A');
  printf("\n");
}