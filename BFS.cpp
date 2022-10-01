// Algorithm to find the shortest path between any two nodes in a graph

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

struct Node {
    ll cur, dist; // stores current node and distance from root node
};

ll bfs(ll a, ll b) {
    ll visited[1005];
    ll distance[1005];
    memset(distance, INT8_MAX, sizeof(distance));

    list<Node> q;
    q.pb({a, 0});

    while(!q.empty()) {
        Node temp = q.front();
        q.pop_front();
        // Looping through all adjacent nodes
        for (auto item : v[temp.cur]) {
            if (!visited[item]) {
                // If the node is not visited, add the nodes adjacent to the current node to the queue and set as visited. 
                // Add 1 to distance
                q.pb({item, temp.dist + 1});
                visited[item] = 1;
            }
            // If the distance to the node is more than the current distance achived, set it to the current distance
            // This is to find the shortest distance between the two nodes
            if (temp.dist + 1 < distance[item]) distance[item] = temp.dist + 1;
        }
    }
    return distance[b];
}

void run() {
    // Creates an adjacency list
    ll n; cin >> n;
    f(n) {
        ll p, q; cin >> p >> q;
        v[p].pb(q);
        v[q].pb(p);
    }
    ll a, b; cin >> a >> b;
    cout << bfs(a, b) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Several testcases
    ll t; cin >> t;
    while(t--) run();
}