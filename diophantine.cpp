typedef long long int lli;

lli extended_gcd(lli a, lli b, lli &x, lli &y){
    if(a == 0){
        x=0, y=1;
        return b;
    }
    lli x1, y1;
    lli d=extended_gcd(b%a, a, x1, y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

bool can_solve(lli a, lli b, lli c, lli &x0, lli &y0, lli &g){ //Calcula una solucion
    g=extended_gcd(abs(a), abs(b), x0, y0);
    if (c%g) return false;
    x0*=c/g;
    y0*=c/g;
    if(a < 0) x0*=-1;
    if(b < 0) y0*=-1;
    return true;
}

void shift_solution(lli &x, lli &y, lli a, lli b, lli cnt){
    x+=cnt*b;
    y-=cnt*a;
}

/*
    Calcula el numero de todas las soluciones de la ecuacion en un intervalo dado para X como para Y.
    De aqui obtienes un intervalo donde se encuentran todas las soluciones en X, para hallarlas:
                            x=lx+k*b/g, donde g es el gcd(a, b)
                            para toda k>=0 hasta que x==rx
    Los valores de Y lo sacas despejando de a*X+b*Y=c
*/

lli all_solutions(lli a, lli b, lli c, lli minx, lli maxx, lli miny, lli maxy){
    lli x, y, g;
    if(!can_solve(a, b, c, x, y, g)) return 0;
    a/=g;
    b/=g;
    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;
    shift_solution(x, y, a, b, (minx-x)/b);
    if(x < minx) shift_solution(x, y, a, b, sign_b);
    if(x > maxx) return 0;
    lli lx1=x;
    shift_solution(x, y, a, b, (maxx-x)/b);
    if(x > maxx) shift_solution(x, y, a, b, -sign_b);
    lli rx1=x;
    shift_solution(x, y, a, b, -(miny-y)/a);
    if(y < miny) shift_solution(x, y, a, b, -sign_a);
    if(y > maxy) return 0;
    lli lx2=x;
    shift_solution(x, y, a, b, -(maxy-y)/a);
    if(y > maxy) shift_solution(x, y, a, b, sign_a);
    lli rx2=x;
    if(lx2 > rx2) swap(lx2, rx2);
    lli lx=max(lx1, lx2);
    lli rx=min(rx1, rx2);
    if(lx > rx) return 0;
    return (rx-lx)/abs(b)+1;
}
