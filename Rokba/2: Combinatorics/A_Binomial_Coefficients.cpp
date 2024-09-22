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

inline ll binPow(int a, int b){
    ll r = 1;
    a %= MOD;

    while(b > 0){
        if(b & 1) r = (r * a) % MOD;

        b >>= 1;
        a = (a * a) % MOD;
    }

    return r;
}

inline int bincoeff(int n, int k){
    if(k > n) return 0;
    else return (fact[n] * binPow(fact[k] * fact[n-k], MOD - 2))%MOD;
}

signed main(){

    int t;
    cin >> t;

    fact[0] = 1;
    for(int i=1; i < MAX; i++){
        fact[i] = (fact[i-1] * i)%MOD;
    }

    while(t--){
        int a, b;
        cin >> a >> b;
        cout << bincoeff(a, b) << endl;
    }
}

