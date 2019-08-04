struct pt {
    double x, y;
    pt(double x, double y){
        this->x=x;
        this->y=y;
    }
};

bool onSegment(pt p, pt q, pt r) { //Ver si el punto Q cae en la linea PR, donde P, R, Q son colineales
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
    return false;
}

/*
    Diferencia de los distintos valores de la orientacion de un triple:
    Cero = que el triple es colineal
    Positivo = que el triple tiene orientacion contraria al reloj
    Negativo = que el triple tiene orientacion a favor al reloj
*/

int orientation(pt p, pt q, pt r){
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool has_intersection_point(pt p1, pt q1, pt p2, pt q2){ //Ver si dos lineas se intersectan
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if(o1 != o2 && o3 != o4) return true; //Caso general
    //Casos especiales
    if(o1 == 0 && onSegment(p1, p2, q1)) return true;
    if(o2 == 0 && onSegment(p1, q2, q1)) return true;
    if(o3 == 0 && onSegment(p2, p1, q2)) return true;
    if(o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}

bool is_inside(pt test, vector<pt> poly){ //Ver si un punto está contenido dentro de un poligono convexo
    int i;
    int j;
    bool result = false;
    for(i = 0, j = poly.size()-1; i < poly.size(); j = i++){
        if((poly[i].y > test.y) != (poly[j].y > test.y) &&
            (test.x < (poly[j].x-poly[i].x)*(test.y-poly[i].y)/(poly[j].y-poly[i].y)+poly[i].x))
        {
            result = !result;
        }
    }
    return result;
}

/*
    Implementacion para saber si dos poligonos convexos se intersectan entre si.
    1) La primera parte consiste en verificar si alguna arista del poligono A está intersectando a otra del poligono B.
    2) La segunda parte consiste en que si no se pudo encontrar que el poligono A se intersecta con el poligono B, entonces
       se buscará si algún punto del poligino A está contenido dentro el poligono B y viceversa
*/

bool ch_interset(vector<pt> a, vector<pt> b){
    //Primera parte
    for(int i = 0; i < a.size(); i++){
        int nexta=(i+1 == a.size())?0:i+1;
        pt l1p1=a[i], l1p2=a[nexta];
        for(int j = 0; j < b.size(); j++){
            int nextb=(j+1 == b.size())?0:j+1;
            if(has_intersection_point(l1p1, l1p2, b[j], b[nextb])) return true;
        }
    }
    //Segunda parte
    for(int i = 0; i < a.size(); i++) if(is_inside(a[i], b)) return true;
    for(int i = 0; i < b.size(); i++) if(is_inside(b[i], a)) return true;
    return false;
}

/*
    Metodo de Graham para calcular el convex hull de un set de puntos
    con complejidad O(nlogn).
    Esta implementacion ordena los puntos por el eje X y no por angulos polares,
    porque usa la orientacion con el producto vectorial de los 3 puntos.
    Retorna el convex hull en sentido horario empezando por el upper convex hull.
*/

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool clockwise(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool counter_clockwise(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if(a.size() == 1) return;
    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i = 1; i < (int)a.size(); i++){
        if(i == a.size()-1 || clockwise(p1, a[i], p2)){
            while (up.size() >= 2 && !clockwise(up[up.size()-2], up[up.size()-1], a[i])) up.pop_back();
            up.push_back(a[i]);
        }
        if(i == a.size()-1 || counter_clockwise(p1, a[i], p2)){
            while(down.size() >= 2 && !counter_clockwise(down[down.size()-2], down[down.size()-1], a[i])) down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for(int i = 0; i < (int)up.size(); i++) a.push_back(up[i]);
    for(int i = down.size()-2; i > 0; i--) a.push_back(down[i]);
}

int main(){
    vector<pt> a; //Vector de puntos
    convex_hull(a);
    return 0;
}
