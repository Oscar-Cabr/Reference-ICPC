//<-- Header.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
using namespace std;
using namespace __gnu_pbds; 
template<typename T, typename Cmp = less<T>>
using ordered_set = tree<T,null_type,Cmp,rb_tree_tag,tree_order_statistics_node_update>;
//<-- Use in main.
ordered_set<pair<int,int>> multi_oset;
map<int,int> cuenta;
function<void(int)> insertar = [&](int val) -> void {
  multi_oset.insert({val,++cuenta[val]});
};
function<void(int)> eliminar = [&](int val) -> void {
  multi_oset.erase({val,cuenta[val]--});
};
