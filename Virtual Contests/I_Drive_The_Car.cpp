#include<bits/stdc++.h>
#define endl '\n';
#define Pin ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0);
#define int long long
#define ff first
#define ss second
#define int long long
 
typedef long long ll;
 
using namespace std;
 
signed main(){Pin
    ll s, n;
    cin >> s >> n;

    vector<pair<ll, ll>> speed(n);
    for (int i = 0; i < n; i++) {
        cin >> speed[i].ff >> speed[i].ss;
    }
    
    ll v = 0;
    ll x = 0;

    if(n == 1) {
        int t = s - speed[0].ff + 1;
        x = t * speed[0].ss;
    } else {

        for (ll i = 0; i < n-1; i++) {
            int t = speed[i+1].ff - speed[i].ff;
            v += speed[i].ss;
            x += v * t;
        }

        v += speed[n-1].ss;
        int t = s - speed[n-1].ff + 1;
        x += v * t;
    }

    cout << x << endl;

    return 0;
}