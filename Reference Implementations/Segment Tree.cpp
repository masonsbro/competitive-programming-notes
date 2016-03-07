#include <iostream>

using namespace std;

ull tree[MAX_N*4];

ull update(ull *tree, int i, int a, int b, int j, int m, int ma) {
    if (b < a) return 0;
    if (b < j || j < a) return tree[i];
    if (a == b && a == j) tree[i] = (ma < tree[i] + m) ? ma : (tree[i] + m);
    else tree[i] = update(tree, 2*i+1, a, (a+b)/2, j, m, ma) + update(tree, 2*i+2, (a+b)/2+1, b, j, m, ma);
    return tree[i];
}

ull query(ull *tree, int i, int a, int b, int l, int r) {
    if (b < a) return 0;
    if (b < l || r < a) return 0;
    if (a >= l && b <= r) return tree[i];
    return query(tree, 2*i+1, a, (a+b)/2, l, r) + query(tree, 2*i+2, (a+b)/2+1, b, l, r);
}
