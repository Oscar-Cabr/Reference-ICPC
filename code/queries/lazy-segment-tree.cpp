vector<long long> v;
vector<long long> sex;
vector<long long> lazy;
long long n;
 
void push(int node, int tl, int tr){
    if(lazy[node] != 0){
        sex[node] += lazy[node] * (tr - tl + 1);
 
        if(tl != tr){
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }
 
        lazy[node] = 0;
    }
}
 
void build(int node, int tl, int tr){
    if(tl == tr){
        sex[node] = v[tl];
    }
    else{
        int tm = (tl + tr)/2;
        build(2*node, tl, tm);
        build(2*node + 1, tm+1, tr);
        sex[node] = sex[2*node] + sex[2*node + 1];
    }
}
 
void update(int node, int tl, int tr, int l, int r, int val){
    push(node, tl, tr);
    //Si el rango del nodo actual esta fuera de rango totalmente
    if(l > tr || r < tl){
        return;
    }
 
    //Si el rango del nodo esta completamente dentro del rango
    if(l <= tl && r >= tr){
        lazy[node] += val;
        push(node, tl, tr);
        return;
    }
 
    //Si el rango del nodo esta parcialmente en el rango, desciende a los hijos
    int tm = (tl + tr)/2;
    update(2*node, tl, tm, l, r, val);
    update(2*node + 1, tm + 1, tr, l, r, val);
}
 
long long query(int node, int tl, int tr, int l, int r){
    //Antes de cualquier consulta, se pushean las actualizaciones pendientes
    push(node, tl, tr);
 
    //Si el rango del nodo actual esta fuera de rango
    if(l > tr || r < tl){
        return 0; //Regresa el elemento neutro para la suma
    }
 
    //Si el rango del nodo actual esta completamente dentro del rango
    if(l <= tl && r >= tr){
        return sex[node];
    }
 
    //Si el rango del nodo esta parcialmente en el rango, desciende y combina los resultados
    int tm = (tl + tr)/2;
    long long lzum = query(2*node, tl, tm, l, r);
    long long rzum = query(2*node + 1, tm + 1, tr, l , r);
    return lzum + rzum; //Devuelve la operacion aplicada a ambas partes (suma)
}
 
void solve(){
    long long q; cin >> n >> q;
 
    v.resize(n);
    sex.assign(4 * n, 0); //Se inicializan en el elemento neutro
    lazy.assign(4 * n, 0);
 
    //Lectura del arreglo inicial
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    //Construye el sextree
    build(1, 0, n - 1);
 
    //type == 1 es actualización
    //type == 2 es query
    for(long long i = 0; i < q; i++){
        int type; cin >> type;
        if(type == 1){
            long long l, r, val;
            cin >> l >> r >> val;
            update(1, 0, n - 1, l - 1, r - 1, val); //Esta 1-indexed
        }
        else{
            long long l;
            cin >> l;
 
            cout << query(1, 0, n - 1, l - 1, l - 1) << endl;
        }
    }
}
