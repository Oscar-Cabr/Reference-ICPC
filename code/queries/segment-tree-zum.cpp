#include<bits/stdc++.h>
typedef long long ll;
struct Node{
    ll zum;
    Node() : zum(0) {}

    Node(ll val){
        zum = val;
    }

    static Node merge(const Node& a, const Node& b){
        Node res;
        res.zum = a.zum + b.zum;
        return res;
    }

};

struct SegmentTree{
    int n;
    vector<Node> tree;

    SegmentTree(int n) : n(n), tree(4*n){}

    void build(const vector<ll>& a, int node, int l, int r){
        if(l==r){
            tree[node] = Node(a[l]);
            return;
        }
        int mid = l + (r-l)/2;
        build(a, 2*node, l, mid);
        build(a, 2*node + 1, mid + 1, r);
        tree[node] = Node::merge(tree[2*node], tree[2*node + 1]);
    }

    void update(int node, int l, int r, int idx, ll x){
        if(l == r){
            tree[node] = Node(x);
            return;
        }
        int mid = l + (r-l)/2;
        if(idx <= mid) update(2*node, l, mid, idx, x);
        else update(2*node + 1, mid + 1, r, idx, x);
        tree[node] = Node::merge(tree[2*node], tree[2*node + 1]);
    }

    Node query(int node, int l, int r, int tl, int tr){
        if(tl > r || tr < l) return Node();
        if(tl <= l && r <= tr) return tree[node];
        int mid = l + (r-l)/2;
        return Node::merge(
            query(2*node, l, mid, tl, tr),
            query(2*node + 1, mid + 1, r, tl, tr)
        );
    }
};