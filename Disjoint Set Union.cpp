#include <bits/stdc++.h>

using namespace std;

int parent[100005];
int ranks[100005];

void makeset(int v) {
    parent[v] = v;
    ranks[v] = 0;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b]) swap(a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b]) ranks[a]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    // CODE HERE
}