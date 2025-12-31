typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
const int INF = INT_MAX;
class Segment_tree {
   public: vll t;
   Segment_tree( int n = 1e5+10 ) {
      t.assign(n*4,INF);
   }
   void update(int node, int index, int tl, int tr, int val) {
      if( tr < index || tl > index ) return;
      if( tr == tl ) t[node] = val;
      else {
         int mid = tl + ((tr-tl)>>1);
         int lft = node << 1;
         int rght = lft + 1;
         update(lft,index,tl,mid,val);
         update(rght,index,mid+1,tr,val);
         t[node] = min(t[lft],t[rght]);
      }
   }
   ll query(int node, int l, int r, int tl, int tr) {
      if( tl > r || tr < l ) return INF;
      if( tl >= l and tr <= r ) return t[node];
      else {
         int mid = tl + ((tr-tl)>>1);
         int lft = node << 1;
         int rght = lft + 1;
         ll q1 = query(lft,l,r,tl,mid);
         ll q2 = query(rght,l,r,mid+1,tr);
         return min(q1,q2);
      }
   }
   void build(vi &v, int node, int tl, int tr) {
      if( tl == tr ) t[node] = v[tl];
      else {
         int mid = tl + ((tr-tl)>>1);
         int lft = node << 1;
         int rght = lft + 1;
         build(v,lft,tl,mid);
         build(v,rght,mid+1,tr);
         t[node] = min(t[lft],t[rght]);
      }
   }
};
Segment_tree st(n);
st.build(v,1,0,n-1);
st.update(1,a-1,0,n-1,b);
st.query(1,a-1,b-1,0,n-1));
