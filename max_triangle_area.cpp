double triangle_area (const pt& p1, const pt& p2, const pt& p3) {
    return abs((double) p1.x * p2.y +
               (double) p2.x * p3.y +
               (double) p3.x * p1.y -
               (double) p1.y * p2.x -
               (double) p2.y * p3.x -
               (double) p3.y * p1.x) / 2.0;
}

/*
    Implementacion para hallar el triangulo de mayor area en un conjunto de puntos
    con complejidad O(n) y O(3n) en el peor de los casos
*/

double max_triangle_area(vector<pt> p){
    if(p.size() == 3) return triangle_area(p[0], p[1], p[2]);
    convex_hull(p);
    int n = p.size();
    int i = 0;
    int j = i + 1;
    int k = j + 1;
    double res = 0.;
    while (true) {
        double area = triangle_area(p[i], p[j], p[k]);
        while (true) {
            while (true) {
                int nk = (k + 1) % n;
                double narea = triangle_area(p[i], p[j], p[nk]);
                if (narea >= area) {
                    k = nk;
                    area = narea;
                } else {
                    break;
                }
            }
            int nj = (j + 1) % n;
            double narea = triangle_area(p[i], p[nj], p[k]);
            if (narea >= area) {
                j = nj;
                area = narea;
            } else {
                break;
            }
        }
        if (area > res) res = area;
        i++;
        if (i == j) j = (j + 1) % n;
        if (j == k) k = (k + 1) % n;
        if (i == n) break;
    }
    return res;
}
