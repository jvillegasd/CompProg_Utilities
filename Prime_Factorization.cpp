void sieve(){ //O(nLog(Log(n)))
    memset(primesB, true, sizeof(primesB));
    for(int i = 2; i * i <= MAXN; i++){
        if(primesB[i]){
            for(int j = i * i; j <= MAXN; j+=i) primesB[j] = false;
        }
    }
    for(int i = 2; i <= MAXN; i++) if(primesB[i]) primes.pb(i);
}

void sieve(){
    memset(prime, 1, sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i = 2; i <= 100010; i++){
        if(prime[i]){
            primes.pb(i);
            for(int j = 2*i; j <= 100010; j+=i) prime[j]=0;
        }
    }
}

void smallPF(){ //O(log(n))
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
