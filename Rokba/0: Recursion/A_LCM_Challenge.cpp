#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

    ll n;
    cin >> n;

    if(n <= 2) cout << n << '\n';
    else {
        ll l = lcm(n, lcm(n-1, n-2));
        ll r = lcm(n, lcm(n-1, n-3));
        ll h = lcm(n-1, lcm(n-2, n-3));
        cout << max(l, max(r, h)) << '\n';
    }
    
    return 0;
}