#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll MAX = 5e9;

int main() {

    ll n, k; cin >> n >> k;
    vector<ll> a(n), t(n), ps(n+5, 0);
    for(auto& i: a) cin >> i;
    ll sum = 0;
    for(int i=0; i < n; i++){
        cin >> t[i];
        if(t[i]) {
            sum += a[i];
            ps[i] = i == 0 ? 0 : 0 + ps[i-1];
        } else {
            ps[i] = i == 0 ? a[i] : a[i] + ps[i-1];
        }
    }

    ll m = sum + ps[k-1];
    for(int i=1; i < n-k+1; i++){
        m = max(m, sum + (ps[i+k-1] - ps[i-1]));
    }

    cout << m << endl;

    return 0;
}