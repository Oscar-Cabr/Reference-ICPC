struct Query{
    int l, r, idx;
};
//vector queries ya leido y 0-indexado anteriormente
int block_size = (int)sqrt(n);
auto mo_cmp = [&](Query a, Query b) { //custom cmptor
    int block_a = a.l / block_size;
    int block_b = b.l / block_size;
    if(block_a != block_b) return block_a < block_b;
    if(block_a & 1) return a.r < b.r; //zig-zag sorting
    return a.r > b.r;
};
sort(all(queries), mo_cmp);
