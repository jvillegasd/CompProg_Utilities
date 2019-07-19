int main(){
    int n;
    lli dp[510][510]; //0x3f memset
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%lld", &dp[i][j]);
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][k]+dp[k][j] < dp[i][j]) dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }
    return 0;
}
