// general algorithm to do binary search

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <random>

#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair

using namespace std;

ll mn = INT8_MIN;
ll mx = INT8_MAX;
ll n;
vector<ll> v(1005);

ll bs(ll s) {
    ll low = 0, high = n-1, mid, ret = -1;
    while(low <= high) {
        mid = (low + high) / 2;
        if (v[mid] > s) {
            high = mid - 1;
            ret = mid; // move this based on whether you want the value to be rounded up or down
        }
        else {
            low = mid + 1;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    ll s; cin >> s;
    cout << bs(s) << endl;
}