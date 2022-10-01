#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

vector<ll> primes;

void sieve(ll n) {
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= n; i++) if (isprime[i]) {for (int j = i*i; j <= n; j+=i) isprime[j] = false; primes.pb(i);}
}

int main() {
    ll n; cin >> n;
    sieve(n);
    for (auto item : primes) cout << item << " ";
    cout << endl;
}