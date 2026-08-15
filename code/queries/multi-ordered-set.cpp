//<-- Paste the header below at file scope (after your template): #include directives cannot be inside a function.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
using namespace std;
using namespace __gnu_pbds; 
template<typename T, typename Cmp = less<T>>
using ordered_set = tree<T,null_type,Cmp,rb_tree_tag,tree_order_statistics_node_update>;
//<-- Paste from here down inside main() (the lambdas need a capture-default).
ordered_set<pair<int,int>> multi_oset;
map<int,int> cuenta;
function<void(int)> insertar = [&](int val) -> void {
  multi_oset.insert({val,++cuenta[val]});
};
function<void(int)> eliminar = [&](int val) -> void {
  if( cuenta[val] == 0 ) return; // guard: erasing without a matching insert would go negative
  multi_oset.erase({val,cuenta[val]});
  cuenta[val]--;
};
