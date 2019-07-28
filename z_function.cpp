/*
    Implementacion de Z function para saber el tamaño de la
    maxima subcadena de la string "S" que empieza en la posicion "i" que es
    prefijo de "S", este valor se encuentra en el array "Z" en "Z[i]". Este algoritmo
    tiene diversos usos:
    1) Buscar cuantas ocurrencias de un patron "P" suceden en una string "S":
       *) Se crea una string "T" = "P" + "$" + "S, "$" es un separador para indicarle al algoritmos hasta donde debe comparar
       *) Sea "k" = Z[i+length("P")+1], si "k" = length("P"), entonces se encontro una ocurrencia. Notese que se hace un juego de
          indices para arreglar el desfase que tiene "T"
    2) Contar el numero de diferentes substring de "S":
       -) Denotemos como "c" a la letra que se va agregando a la substring en reversa de "S" en cada iteracion.
       Se va resolviendo iterativamente. Para cada substring en reversa de "S" se le calcula la tabla "Z" y se busca el mayor
       valor Z[i], luego, ir sumando length(subtring reversa "S")-max(Z). Lo que se hace es calcular cuantas substrings que solo
       se puedan encontrar en la substring reversa "S"
*/

vector<int> z_function(string s){
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int no_substrings(string s){
    int cnt=0, mx;
    for(int i = 0; i < s.size(); i++){
        string x=s.substr(0, i+1);
        reverse(x.begin(), x.end());
        vector<int> z=z_function(x);
        mx=0;
        for(int j = 0; j < x.size(); j++) mx=max(mx, z[j]);
        cnt+=(i+1)-mx;
    }
    return cnt;
}

int string_compression(string s){
    vector<int> z=z_function(s);
    int n=(int)s.length(), ans=0;
    for(int i = 0; i < z.size(); i++){
        if(n%i == 0 && i+z[i] == n){
            ans=i;
            break;
        }
    }
    return ans;
}
