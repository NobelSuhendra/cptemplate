// General DFS algorithm to search through all nodes in a graph

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <iomanip>
#include <list>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define f(a) for (int i = 0; i < a; i++)

using namespace std;

vector<ll> v[1005];
ll visited[1005];

void dfs(ll a) {
    visited[a] = 1;
    cout << a << " ";
    for (auto item : v[a]) {
        if (!visited[item]) dfs(item);
    }
}

void run() {
    ll n; cin >> n;
    f(n) {
        ll p, q; cin >> p >> q;
        v[p].pb(q);
        v[q].pb(p);
    }
    ll a; cin >> a;
    cout << "Path: ";
    dfs(a);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t; cin >> t;
    while(t--) run();
}