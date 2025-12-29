vector<long long> v, sex;
int n;
void build(int node, int l, int r){
    if(l == r) sex[node] = v[l];
    else{
        int mid = (l+r)/2;
        build(2*node, l, mid);
        build(2*node + 1, mid+1, r);
        sex[node] = sex[2*node] + sex[2*node +1];
    }
}
void update(int node, int l, int r, int idx, int val){
    if(l == r){
        v[idx] = val;
        sex[node] = val;
    }
    else{
        int mid = (l+r)/2;
        if(l <= idx && idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node +1, mid+1, r, idx, val);
        sex[node] = sex[2*node] + sex[2*node + 1];
    }
}
int query(int node, int tl, int tr, int l, int r){
    if(r < tl || tr < l) return 0;
    if(l <= tl && tr <= r) return sex[node];
    int tm = (tl+tr)/2;
    return query(2*node, tl, tm, l, r) + query(2*node +1, tm+1, tr, l, r);
}
v.resize(n);
sex.resize(4 * n);
build(1, 0, n - 1);
query(1, 0, n-1, l - 1, r - 1)
