#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;
typedef long long int lli;
lli bc[110];

struct matrix{
    int row, col;
    lli m[110][110];
};

matrix mul(matrix a, matrix b){
    matrix ans;
    ans.row = a.row;
    ans.col = b.col;
    for(int i = 0; i < a.row; i++){
        for(int j = 0; j < b.col; j++){
            ans.m[i][j] = 0;
            for(int k = 0; k < a.col; k++){
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
                ans.m[i][j]%=MOD;
            }
        }
    }
    return ans;
}

matrix mPow(matrix a, lli p){
    if(p==1) return a;
    if(p&1) return mul(a, mPow(a, p-1));
    matrix ans = mPow(a, p>>1);
    return mul(ans, ans);
}

/*
	Puede sufrir cambios dependiendo del problema.
	Inicializa el vector de casos bases, debe modificarse dependiendo de la formula(as) de recurrencia
*/

void setBC(int k){
    bc[0] = 1;
    for(int i = 1; i < 110; i++){
        bc[i] = 0;
        int aux = k;
        for(int j = i-1; j >= 0 && aux; j--, aux--) bc[i]=(bc[i]+bc[j])%MOD;
    }
}

int main(){
    int k;
    lli sum, n;
    setBC(k);
    matrix trans;
    trans.row = trans.col = k;
    /*
	Puede sufrir cambios dependiendo del problema.
	Inicializacion de la matriz transformada, dependiendo de cuantas funciones unicas de recurrencia existan,
	la matrix se va llenando con sus coeficientes o no. Cuando se tenga una funcion, se va llenando desde el primer
	coeficiente hasta el ultimo(Por lo general).
    */
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            trans.m[i][j] = 0;
            if(i==0) trans.m[i][j] = i-esimo coeficiente; //Funcion unica de recurrencia
	    if(i==j+1) trans.m[i][j] = 1;
        }
    }//La respuesta por lo general esta en la columna k-2, si se inicializata "trans.m" al revez, estaria en la columna 1
    trans = mPow(trans, n-1);
    sum = 0;
    for(int i = 0; i < k; i++) sum+=(trans.m[k-2][i]*bc[k-i-1])%MOD, sum%=MOD; //Multiplicar primer coeficiente con el ultimo caso base de su respectiva funcion y asi
    printf("%lld\n", sum);
    return 0;
}