struct Node{ // Ejemplo con query de suma en rango y update de suma en rango
  ll zum;
  Node() : zum(0) {} //elemento neutro
  Node(ll val) : zum(val) {}
  static Node merge(const Node& a, const Node& b){
    Node res;
    res.zum = a.zum + b.zum; //Aquí se cambia la operación(es) del problema
    return res;
  }
};
struct Update{
  ll add_val;
  Update() : add_val(0) {} //elemento neutro
  Update(ll val) : add_val(val) {}
  bool is_empty() const{
    return add_val == 0;
  }
  void clear(){
    add_val = 0;
  }
  void apply(Node& node, int l, int r) const{
    ll cnt = r - l + 1;
    // se suma el valor agregado por la cantidad de nodos hijos modificados (solo aplica para suma)
    node.zum += add_val * cnt;
  }
  // si hay más de una operación aquí se deben priorizar
  void combine(const Update& other){
    add_val += other.add_val;
  }
};
struct LazySegmentTree{
  int n;
  vector<Node> tree;
  vector<Update> lazy;
  LazySegmentTree(int n) : n(n), tree(4*n), lazy(4*n) {}
  void build(const vll& a, int node, int l, int r){
    if(l == r){
      tree[node] = Node(a[l]);
      return;
    }
    int mid = l + (r-l) / 2;
    build(a, 2 * node, l, mid);
    build(a, 2 * node + 1, mid + 1, r);
    tree[node] = Node::merge(tree[2 * node], tree[2 * node + 1]);
  }
  void push(int node, int l, int r){
    if(!lazy[node].is_empty()){
      int mid = l + (r-l) / 2;
      lazy[node].apply(tree[2 * node], l, mid);
      lazy[node].apply(tree[2 * node + 1], mid + 1, r);
      lazy[2 * node].combine(lazy[node]);
      lazy[2 * node + 1].combine(lazy[node]);
      lazy[node].clear();
    }
  }
  void update(int node, int l, int r, int tl, int tr, const Update& upd){
    if(tl > r || tr < l) return;
    if(tl <= l && tr >= r){
      upd.apply(tree[node], l, r);
      lazy[node].combine(upd);
      return;
    }
    push(node, l, r);
    int mid = l + (r-l)/2;
    update(2 * node, l, mid, tl, tr, upd);
    update(2 * node + 1, mid + 1, r, tl, tr, upd);
    tree[node] = Node::merge(tree[2 * node], tree[2 * node + 1]);
  }
  Node query(int node, int l, int r, int tl, int tr){
    if(tl > r || tr < l) return Node();
    if(tl <= l && tr >= r) return tree[node];
    push(node, l, r);
    int mid = l + (r-l) / 2;
    return Node::merge(
      query(2 * node, l, mid, tl, tr),
      query(2 * node + 1, mid + 1, r, tl, tr)
    );
  }
  // wrappers para el main
  void build(const vll& a) { build(a, 1, 0, n - 1); }
  void update(int tl, int tr, const Update& upd) { update(1, 0, n - 1, tl, tr, upd); }
  Node query(int tl, int tr) { return query(1, 0, n - 1, tl, tr); }
};
LazySegmentTree segtree(n);
segtree.build(a);
//sumar 5 a [1, 4] (0-indexed)
segtree.update(1, 4, Update((ll)5));
segtree.query(0, 3).zum
