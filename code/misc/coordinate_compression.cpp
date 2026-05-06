//Previously read vector<int> a(n)
vector<int> coords = a;
sort(all(coords));
coords.erase(unique(all(coords)), coords.end()); //erases duplicates
//Reassings every value in vector "a" to the new corresponding value
for(int &x : a) x = lower_bound(all(coords), x) - coords.begin();
