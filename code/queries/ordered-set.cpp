//<-- Header.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
using namespace std;
using namespace __gnu_pbds; 
template<typename T, typename Cmp = less<T>>
using ordered_set = tree<T,null_type,Cmp,rb_tree_tag,tree_order_statistics_node_update>;
//<-- Declaration.
ordered_set<int> oset;
//<-- Methods usage.
// K-th element in a set (counting from zero).
ordered_set<int>::iterator it = oset.find_by_order(k);
// Number of items strictly smaller than k.
ordered_set<int>::iterator it = oset.order_of_key(k);
// Every other std::set method.
