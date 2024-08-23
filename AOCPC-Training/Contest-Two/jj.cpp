#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

void test() {
    int n; cin >> n;

    ll a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> suf(n, a[n-1]);
    for(int i = n-2; i >= 0; i--) suf[i] = suf[i+1] + a[i];

    ll sum = 0;
    for(int i = 0; i+1 < n; i++) {
        sum = (sum + (a[i] * suf[i+1])) % MOD;
    }

    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;  //cin >> t;
    
    while(t--) {
        test();
    }

    return 0;
}
