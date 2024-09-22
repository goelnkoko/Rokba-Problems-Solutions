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
const int MAX = 1e5+10;

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

    int n;

    while(cin >> n && n != 0){
        vector<int> a(n), b(n);
        int total = 0;
        for(int i=0; i < n; i++) cin >> a[i];
        for(int i=0; i < n; i++) cin >> b[i];
        bool ans = true;
        for(int i=0; i < n; i++){
            b[i] = b[i] - a[i];
            if(b[i] < 0) ans = false;
            total += b[i];
        }
        ll res = fact[total];
        if(ans){
            for(int i=0; i < n; i++){
                res = (res * binPow(fact[b[i]], MOD-2, MOD))%MOD;
            }
        } else{ 
            res = 0;
        }

        cout << res << endl;
    }

}   