// Using function
bool cmpFunction(const pair<int,int> &a, const pair<int,int> &b) {
  return a.second < b.second;
}
sort(all(v), cmpFunction);
// Using functor
struct CmpFunctor {
  bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
    return a.second < b.second;
  }
};
sort(all(v), CmpFunctor());
// Using lambda function
sort(all(v), [](const pair<int,int> &a, const pair<int,int> &b) {
  return a.second < b.second;
});
