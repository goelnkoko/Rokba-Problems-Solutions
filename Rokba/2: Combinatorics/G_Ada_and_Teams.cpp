#include <bits/stdc++.h> 

#define endl '\n'
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9+7;
const int MAX = 1e6+10;

int fact[MAX];

inline ll binPow(ll a, ll b, ll m){

    a %= m;
    ll r = 1;

    while(b > 0){
        if(b & 1) r = (a * r) % m;

        b >>= 1;
        a = (a * a) % m;
    }

    return r;
}

signed main(){

    vector<int> fact(MAX);
    fact[0] = 1;
    for(int i=1; i < MAX; i++)
        fact[i] = (i * fact[i-1])%MOD;

    int n, a, b, d;
    
    while(cin >> n >> a >> b >> d){
        ll x = (fact[n] * binPow(fact[a] * fact[n-a], MOD-2, MOD))%MOD;
        ll y = (fact[b] * binPow(fact[d] * fact[b-d], MOD-2, MOD))%MOD;
        ll res = (x * binPow(y, a, MOD))%MOD;
        cout << res << endl;
    }

}   