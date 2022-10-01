#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define fr first
#define se second

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    ll n, m; cin >> n >> m;

    vector<ll> path;
    vector<pii> v[n+1];
    vector<ll> par(n+1);
    vector<ll> dist(n+1,1e18);
    vector<bool> vis(n+1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (ll i = 0; i < m; i++) {
        ll a, b, w; cin >> a >> b >> w;
        v[a].pb({b, w});
        v[b].pb({a, w});
    }

    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        ll temp = pq.top().se;
        pq.pop();
        for (auto item : v[temp]) {
            if (!vis[item.fr] and dist[item.fr] > dist[temp] + item.se) {
                dist[item.fr]= dist[temp] + item.se;
                par[item.fr] = temp;
                pq.push({dist[item.fr], item.fr});
            }
        }
        vis[temp] = 1;
    }
    
    if (dist[n] == 1e18) {
        cout << -1 << endl;
        return 0;
    }

    for (ll i = n; i != 1; i = par[i]) path.pb(i);
    path.pb(1);
    reverse(path.begin(), path.end());
    for (auto item : path) cout << item << " ";
    cout << endl;
    return 0;
}