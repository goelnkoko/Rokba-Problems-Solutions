#include <bits/stdc++.h>

#define Nkumbo ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define vi vector<int> 
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll MAX = 5e9;
const ll MOD = 1e9+7;

inline ll modPow(ll a, ll b){
    ll r = 1;
    a%=MOD;
    while(b > 0){
        if(b % 2 == 1) r = (r*a)%MOD;
        b = b >> 1;
        a = (a*a)%MOD;
    }
    return r;
}

int main() {

    ll t;
    cin >> t;

    while(t--){
        ll n, q;
        cin >> n >> q;

        vector<ll> a(n), evens(n+5, 0), odds(n+5, 0);
        for(auto& i: a) cin >> i;

        evens[0] = a[0] % 2 ? 0:1; odds[0] = a[0]%2;
        for(int i=1; i < n; i++){
            evens[i] = evens[i-1] + !(a[i]%2);
            odds[i] = odds[i-1] + a[i]%2;
        }

        while(q--){
            int l, r, op;
            cin >> l >> r >> op;
            l--; r--;

            ll resp;
            if(op){
                if(l == 0) resp = modPow(2ll, odds[r]) - 1;
                else resp = modPow(2ll, odds[r]-odds[l-1]) - 1;
            } else {
                if(l == 0) resp = (modPow(2ll, evens[r])-1)*(modPow(2ll, odds[r]));
                else resp = (modPow(2ll, evens[r] - evens[l-1])-1)*(modPow(2ll, odds[r]-odds[l-1]));
            }
            cout << resp%MOD << endl;
        }
        
    }

    return 0;
}