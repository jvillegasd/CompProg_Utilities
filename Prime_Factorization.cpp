void sieve(){ 
    memset(primesB, true, sizeof(primesB));
    for(int i = 2; i * i <= MAXN; i++){
        if(primesB[i]){
            for(int j = i * i; j <= MAXN; j+=i) primesB[j] = false;
        }
    }
    for(int i = 2; i <= MAXN; i++) if(primesB[i]) primes.pb(i);
}

void smallPF(){//O(nlog(n)*log(n))
    spf[1] = 1;
    for(int i = 2; i < MAXN; i++) spf[i] = i;
    for(int i = 4; i < MAXN; i+=2) spf[i] = 2;
    for(int i = 3; i * i < MAXN; i++){
        if(spf[i] == i){
            for(int j = i * i; j < MAXN; j+=i) if(spf[j] == j) spf[j] = i;
        }
    }
}

vector<int> fact(int num){ //O(log(n))
    vector<int> ans;
    while(num != 1){
        ans.pb(spf[num]);
        num/=spf[num];
    }
    return ans;
}