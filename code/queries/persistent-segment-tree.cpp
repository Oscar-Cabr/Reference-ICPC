struct Node{
    ll zum;
    int lc, rc;
    Node() : zum(0), lc(0), rc() {}
    Node(ll val) : zum(val), lc(0), rc(0) {}
    static Node merge(const Node& a, const Node& b){
        Node res;
        res.zum = a.zum + b.zum;
        return res;
    }
};

struct PersistentSegmentTree{
    int n;
    vi roots;
    vector<Node> tree;
    PersistentSegmentTree(int n) : n(n) {
        tree.pb(Node());
    }
    int build(const vll& a, int l, int r){
        int node = tree.size();
        tree.pb(Node());
        if(l == r){
            tree[node] = Node(a[l]);
            return node;
        }
        int mid = l + (r-l) / 2;
        int left_child = build(a, l, mid);
        int right_child = build(a, mid + 1, r);
        tree[node] = Node::merge(tree[left_child], tree[right_child]);
        tree[node].lc = left_child;
        tree[node].rc = right_child;
        return node;
    }
    int update(int prev, int l, int r, int idx, ll x){
        int node = tree.size();
        tree.pb(tree[prev]);
        if(l == r){
            tree[node] = Node(x);
            return node;
        }
        int mid = l + (r-l) / 2;
        int left_child = tree[node].lc;
        int right_child = tree[node].rc;
        if(idx <= mid){
            left_child = update(tree[prev].lc, l, mid, idx, x);
        }
        else{
            right_child = update(tree[prev].rc, mid + 1, r, idx, x);
        }
        tree[node] = Node::merge(tree[left_child], tree[right_child]);
        tree[node].lc = left_child;
        tree[node].rc = right_child;
        return node;
    }
    Node query(int node, int l, int r, int tl, int tr){
        if(tl > r || tr < l || node == 0) return Node();
        if(tl <= l && tr >= r) return tree[node];
        int mid = l + (r-l) / 2;
        return Node::merge(
            query(tree[node].lc, l, mid, tl, tr),
            query(tree[node].rc, mid + 1, r, tl, tr)
        );
    }
};