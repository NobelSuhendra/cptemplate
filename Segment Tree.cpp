// Range Minimum Query

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define pii pair<ll,ll>
#define fr first
#define sc second
#define mp make_pair
#define speed ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)

const int N = 1e5+5;

int n, q, tree[N*4];
vector<int> a;

void build(int l, int r, int idx) {
    if (l == r) {tree[idx] = a[l]; return;}
    int mid = (l+r) / 2;
    build(l, mid, idx*2);
    build(mid+1, r, idx*2+1);
    tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

int query(int l, int r, int from, int to, int idx) {
    if (l > to or r < from) return INT_MAX;
    if (l >= from and r <= to) return tree[idx];
    int mid = (l+r) / 2;
    return min(query(l, mid, from, to, idx*2), query(mid+1, r, from, to, idx*2+1));
}

void update(int l, int r, int where, int x, int idx) {
    if (l == r and l == where) {tree[idx] = x; return;}
    if (l > where or r < where) return;
    int mid = (l+r) / 2;
    update(l, mid, where, x, idx*2);
    update(mid+1, r, where, x, idx*2+1);
    tree[idx] = min(tree[idx*2], tree[idx*2+1]);
}

signed main() {
    speed;
    cin >> n; 
    a.assign(n, pow(2, 31) - 1);
    build(0, n-1, 1);
    cin >> q; while(q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t) cout << query(0, n-1, a, b, 1) << endl;
        else update(0, n-1, a, b, 1);
    }
} 
