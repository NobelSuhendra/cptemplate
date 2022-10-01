#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define pb push_back
#define ll long long

using namespace std;
 
//algo to find maximum sum of m numbers from an array of n numbers

int main() {
    int n, m; cin >> n >> m;
    // n is the number of items in the array, m is the number of items you can add together
    
    int a[n];
    
    for (int i = 0; i < n; i++) cin >> a[i];
    // taking input and storing it in array a
    
    int ans = 0;
    
    // uses binary combinations to find the number of sum combinations
    for (int mask = 0; mask < (1 << n); mask++) {
        // 1 << 3 is 1 000 while 1 << 6 is 1 000000
        // thus mask < (1 << n) is n number of 1s
        // example: 1 << 3 is 111 while 1 << 6 is 111111
        
        int curValue = 0;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                curValue += a[i];
                
                // find the sum of values for where 1 occurs 
            }
        }
        if (__builtin_popcount(mask) == m) {
            // __builtin_popcount(mask) counts the number of ones in the binary representation of the mask
            
            // if the mask has the same number of values as the needed, then check if its greater than the current answer and update it
            ans = max(ans, curValue);
        }
    }

    cout << ans << endl;
}